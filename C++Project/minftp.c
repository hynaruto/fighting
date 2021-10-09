//
// Created by 胡杨 on 2021/9/25.
//
#include "session.h"
#include "sysutil.h"
#include "parseconf.h"
#include "tunable.h"
#include "ftp_code.h"
#include "ftp_proto.h"
#include "hash.h"



void Test_Parseconf()
{
    parseconf_load_file("miniftp.conf");

    printf("tunable_pasv_enable = %d\n",  tunable_pasv_enable);
    printf("tunable_port_enable = %d\n",  tunable_port_enable);
    printf("tunable_listen_port = %d\n",  tunable_listen_port);
    printf("tunable_max_clients = %d\n",  tunable_max_clients);
    printf("tunable_max_per_ip = %d\n",  tunable_max_per_ip);
    printf("tunable_accept_timeout = %d\n",  tunable_accept_timeout);
    printf("tunable_connect_timeout = %d\n",  tunable_connect_timeout);
    printf("tunable_idle_session_timeout = %d\n",  tunable_idle_session_timeout);
    printf("tunable_data_connection_timeout = %d\n",  tunable_data_connection_timeout);
    printf("tunable_local_umask = %d\n",  tunable_local_umask);
    printf("tunable_upload_max_rate = %d\n",  tunable_upload_max_rate);
    printf("tunable_download_mas_rate = %d\n",  tunable_download_max_rate);
    printf("tunable_listen_address = %s\n",  tunable_listen_address);
}

//全局会话结构指针
session_t *p_sess;
//最大连接数限制
static unsigned int s_children_nums = 0;
static struct hash *s_ip_count_hash;
static struct hash *s_pid_ip_hash;
void drop_ip_count(unsigned int *ip);


static void check_limit(session_t *sess);
static void handle_sigchld(int sig);
unsigned int hash_func(unsigned int bucket_size,void *key);
unsigned int handle_ip_count(void *ip);



int main(int argc,char* argv[])
{
    //加载配置文件
    parseconf_load_file("miniftp.conf");
    //程序后台化
    daemon(0,0);
    //必须是root用户启动，普通用户不能启动程序
    if (getuid() != 0)
    {
        printf("miniftp must started as root\n");
    }
    session_t sess = {
            //控制连接
            -1,
            -1,
            "",
            "",
            "",
            1,
            //数据连接
            NULL,
            //数据连接套接字
            -1,
            -1,
            -1,
            -1,
            NULL,
            0,
            0,
            0,
            0,
            0,
            0
    };
    //全局的会话指针
    p_sess = &sess;
    //处理僵尸进程 && 拦截子进程退出信号
    signal(SIGCHLD,handle_sigchld);
    //申请hash表
    s_ip_count_hash = hash_alloc(MAX_BUCKET_SIZE,hash_func);
    s_pid_ip_hash = hash_alloc(MAX_BUCKET_SIZE,hash_func);

    int listen_fd = tcp_server(tunable_listen_address,tunable_listen_port);//处于监听状态
    int socketConn;
    struct sockaddr_in addrCli;
    socklen_t addr_len = sizeof(struct sockaddr);
    while (1)
    {
        socketConn = accept(listen_fd,(struct sockaddr*)&addrCli,&addr_len);//阻塞等待
        if (socketConn < 0)
        {
            perror("accept");
            continue;
        }
        //最大连接数加一
        s_children_nums++;
        sess.max_clients = s_children_nums;
        //每个ip的连接数
        unsigned int ip = addrCli.sin_addr.s_addr;
        sess.max_per_ip = handle_ip_count(&ip);
        //创建进程
        pid_t pid = fork();
        if (pid == -1)
        {
            s_children_nums--;
            ERR_EXIT("fork");
        }
        if (pid == 0)
        {
            //子进程
            close(listen_fd);
            sess.ctrl_fd = socketConn;//保存控制连接的套接字
            //连接限制
            check_limit(&sess);
            begin_session(&sess);
            exit(EXIT_SUCCESS);
        }else{
            //父进程
            //创建进程意味着套接字被创建了2份，因为原来有一个，又复制了一个，所以要关闭一个

            //增加pid和ip地址的映射
            hash_add_entry(s_pid_ip_hash,&pid,sizeof(pid),&ip,sizeof(ip));
            close(socketConn);//关闭客户端的套接字，父进程不用对它服务
        }
    }
    close(listen_fd);
    return 0;
}
static void check_limit(session_t *sess)
{
    if (tunable_max_clients != 0 && tunable_max_clients < sess->max_clients)
    {
        ftp_replay(sess,FTP_TOO_MANY_USERS,"There are too many connected users,please try later");
        exit(EXIT_FAILURE);
    }
    if (tunable_max_per_ip != 0 && sess->max_per_ip > tunable_max_per_ip)
    {
        ftp_replay(sess,FTP_IP_LIMIT,"There are too many connections from your internet address");
        exit(EXIT_FAILURE);
    }
}
static void handle_sigchld(int sig)
{
    //减少连接数
    s_children_nums--;
    //减少每ip的连接数
    pid_t pid;
    while((pid = waitpid(-1,NULL,WNOHANG)) > 0)
    {
        unsigned int *ip = (unsigned int *)hash_lookup_entry(s_pid_ip_hash,&pid,sizeof(pid));
        if (ip == NULL)
            continue;
        drop_ip_count(ip);
        hash_free_entry(s_pid_ip_hash,&pid,sizeof(pid));
    }
}
unsigned int hash_func(unsigned int bucket_size,void *key)
{
    return (*(unsigned int*)key) % bucket_size;
}
unsigned int handle_ip_count(void *ip)
{
    unsigned int *p_count = (unsigned int *)hash_lookup_entry(s_ip_count_hash,ip,sizeof(unsigned int));
    if (p_count == NULL)
    {
        unsigned count = 1;
        hash_add_entry(s_ip_count_hash,ip,sizeof(unsigned int),&count,sizeof(unsigned int));
        return count;
    }
    (*p_count)++;
    return *p_count;
}
void drop_ip_count(unsigned int *ip)
{
    unsigned int *p_count = hash_lookup_entry(s_ip_count_hash,ip,sizeof(unsigned int));
    if (p_count == NULL)
        return;
    (*p_count)--;
    if (*p_count == 0)
        hash_free_entry(s_ip_count_hash,ip,sizeof(unsigned int));
}