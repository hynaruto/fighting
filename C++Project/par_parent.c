//
// Created by 胡杨 on 2021/9/25.
//
#include "par_parent.h"
#include "privsock.h"
#include "sysutil.h"
#include "session.h"
//获取主动套接字连接
static void privop_pasv_get_data_sock(session_t *sess);
//判定被动模式是否被激活
static void privop_pasv_active(session_t *sess);
//创建被动模式的监听套接字
static void privop_pasv_listen(session_t *sess);
//被动模式下接受连接
static void privop_pasv_accept(session_t *sess);


int capset(cap_user_header_t hdrp, const cap_user_data_t datap)
{
    return syscall(__NR_capset, hdrp, datap);
}
static void minimize_privilege()
{
    struct passwd *pwd = getpwnam("nobody");
    if (pwd == NULL)
        ERR_EXIT("getpwnam");
    if (setegid(pwd->pw_gid) < 0)
        ERR_EXIT("setegid");
    if (seteuid(pwd->pw_uid) < 0)
        ERR_EXIT("seteuid");
    struct __user_cap_header_struct cap_header;
    struct __user_cap_data_struct   cap_data;
    memset(&cap_header, 0, sizeof(cap_header));
    memset(&cap_data,   0, sizeof(cap_data));

    cap_header.version = _LINUX_CAPABILITY_VERSION_2;
    cap_header.pid = 0;//提升为root用户

    unsigned int cap_mask = 0;
    cap_mask |= (1<<CAP_NET_BIND_SERVICE);
    //设置数据结构
    cap_data.effective = cap_data.permitted = cap_mask;
    cap_data.inheritable = 0;
    capset(&cap_header, &cap_data);
}

//nobody服务进程
void handle_parent(session_t *sess)
{
    //提升权限
    minimize_privilege();
    char cmd;
    while(1)
    {
        //不停等待ftp服务进程的消息
        cmd = priv_sock_get_cmd(sess->parent_fd);
        switch (cmd)
        {
            case PRIV_SOCK_GET_DATA_SOCK:
                privop_pasv_get_data_sock(sess);
                break;
            case PRIV_SOCK_PASV_ACTIVE:
                privop_pasv_active(sess);
                break;
            case PRIV_SOCK_PASV_LISTEN:
                privop_pasv_listen(sess);
                break;
            case PRIV_SOCK_PASV_ACCEPT:
                privop_pasv_accept(sess);
                break;
        }
    }
}


//获取主动套接字连接
static void privop_pasv_get_data_sock(session_t *sess)
{
    //接受IP
    char ip[16] = {0};
    int len = priv_sock_get_int(sess->parent_fd);
    priv_sock_recv_buf(sess->parent_fd,ip,len);
    //接受端口号
    unsigned short port = (unsigned short)priv_sock_get_int(sess->parent_fd);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);


    int sock = tcp_client(20);
    socklen_t addrlen = sizeof(struct sockaddr);
    if (connect(sock,(struct sockaddr*)&addr,addrlen) < 0)
    {
        priv_sock_send_result(sess->parent_fd,PRIV_SOCK_RESULT_BAD);
        return;
    }
    priv_sock_send_result(sess->parent_fd,PRIV_SOCK_RESULT_OK);
    priv_sock_send_fd(sess->parent_fd,sock);
    close(sock);
}
//判定被动模式是否被激活
static void privop_pasv_active(session_t *sess)
{
    int active = -1;//-1表示未激活
    if (sess->pasv_listen_fd != -1)
        active = 1;//表示激活
    priv_sock_send_int(sess->parent_fd,active);
}
//创建被动模式的监听套接字
static void privop_pasv_listen(session_t *sess)
{
    //获取本地ip
    char ip[16] = {0};
    get_local_ip(ip);
    unsigned int v[4] = {0};
    sscanf(ip,"%u.%u.%u.%u",&v[0],&v[1],&v[2],&v[3]);
    int sockfd = tcp_server(ip,0);//0代表生产默认端口号
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(struct sockaddr);
    if(getsockname(sockfd,(struct sockaddr*)&addr, &addrlen) < 0)
        ERR_EXIT("getsockname");
    unsigned short port = ntohs(addr.sin_port);
    sess->pasv_listen_fd = sockfd;

    priv_sock_send_int(sess->parent_fd,strlen(ip));
    priv_sock_send_buf(sess->parent_fd,ip,strlen(ip));
    priv_sock_send_int(sess->parent_fd,(int)port);
}
//被动模式下接受连接
static void privop_pasv_accept(session_t *sess)
{
    int socket_conn;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(struct sockaddr);
    if((socket_conn = accept(sess->pasv_listen_fd,(struct sockaddr*)&addr,&addrlen)) < 0)
    {
        priv_sock_send_result(sess->parent_fd,PRIV_SOCK_RESULT_BAD);
        return;
    }
    priv_sock_send_result(sess->parent_fd,PRIV_SOCK_RESULT_OK);
    priv_sock_send_fd(sess->parent_fd,socket_conn);
    close(sess->pasv_listen_fd);
    sess->pasv_listen_fd = -1;
    close(socket_conn);
}