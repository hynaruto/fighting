//
// Created by 胡杨 on 2021/9/25.
//

#include "ftp_proto.h"
#include "session.h"
#include "str.h"
#include "ftp_code.h"
#include "privsock.h"
#include "fcntl.h"
#include "tunable.h"

extern session_t *p_sess;
void ftp_replay(session_t *sess, unsigned int code,const char *text)
{
    char buffer[MAX_BUFFER_SIZE] = {0};
    sprintf(buffer,"%d %s\r\n",code,text);
    send(sess->ctrl_fd,buffer,strlen(buffer),0);
}

static void do_user(session_t *sess);
static void do_pass(session_t *sess);
static void do_syst(session_t *sess);
static void do_feat(session_t *sess);
static void do_pwd(session_t *sess);
static void do_type(session_t *sess);
static void do_port(session_t *sess);
static void do_list(session_t *sess);
static void do_pasv(session_t *sess);
static void do_cwd(session_t *sess);
static void do_mkd(session_t *sess);
static void do_rmd(session_t *sess);
static void do_dele(session_t *sess);
static void do_size(session_t *sess);
static void do_rnfr(session_t *sess);
static void do_rnto(session_t *sess);
static void do_retr(session_t *sess);
static void do_stor(session_t *sess);
static void do_rest(session_t *sess);

//命令响应
typedef struct ftpcmd
{
    const char *cmd;
    void(*cmd_handler)(session_t *sess);//命令处理方法,函数指针
}ftpcmd_t;

ftpcmd_t ctrl_cmds[] =  {    {"USER",do_user},
                             {"PASS",do_pass},
                             {"SYST",do_syst},
                             {"FEAT",do_feat},
                             {"PWD",do_pwd},
                             {"TYPE",do_type},
                             {"PORT",do_port},
                             {"LIST",do_list},
                             {"PASV",do_pasv},
                             {"CWD",do_cwd},
                             {"MKD",do_mkd},
                             {"RMD",do_rmd},
                             {"DELE",do_dele},
                             {"SIZE",do_size},
                             {"RNFR",do_rnfr},
                             {"RNTO",do_rnto},
                             {"RETR",do_retr},
                             {"STOR",do_stor},
                             {"REST",do_rest}
};

//空闲断开
void handle_ctr_timeout(int sig)
{
    //响应421超时
    shutdown(p_sess->child_fd,SHUT_RD);
    ftp_replay(p_sess,FTP_IDLE_TIMEOUT,"Timeout.");
    shutdown(p_sess->child_fd,SHUT_WR);
    exit(EXIT_SUCCESS);
}
void start_cmdio_alarm()
{
    if (tunable_idle_session_timeout > 0)
    {
        //开启空闲断开
        signal(SIGALRM,handle_ctr_timeout);
        alarm(tunable_idle_session_timeout);
    }
}
//数据连接断开
void start_data_alarm();
void handle_data_timeout(int sig)
{
    if(!p_sess->data_process)
    {
        ftp_replay(p_sess, FTP_DATA_TIMEOUT, "Data timeout, Reconnect Sorry.");
        exit(EXIT_FAILURE);
    }
    p_sess->data_process = 0;
    start_data_alarm();
}
void start_data_alarm()
{
    if(tunable_data_connection_timeout > 0)
    {
        signal(SIGALRM, handle_data_timeout);
        alarm(tunable_data_connection_timeout);
    }
}

//ftp服务进程
void handle_Child(session_t *sess)
{
    //send(sess->ctrl_fd,"220 (miniftp 1.0.0)\r\n",strlen("220 (miniftp 1.0.0)\r\n"),0);
    ftp_replay(sess,FTP_GREET,"(huyang miniftp 1.0.0)");
    while (1)
    {
        //不停等待客户端的命令并做出处理
        memset(sess->cmd_line,0,MAX_COMMOND_LINE_SIZE);
        memset(sess->cmd,0,MAX_CMD_SIZE);
        memset(sess->arg,0,MAX_ARG_SIZE);

        //开启控制连接
        start_cmdio_alarm();

        int ret = recv(sess->ctrl_fd,sess->cmd_line,MAX_COMMOND_LINE_SIZE,0);
        //printf("cmd_line = %s\n",sess->cmd_line);
        if (ret < 0)
            ERR_EXIT("recv");
        if (ret == 0)
            exit(EXIT_SUCCESS);
        str_trim_crlf(sess->cmd_line);
        str_split(sess->cmd_line,sess->cmd,sess->arg,' ');
        //printf("cmd_line = %s\n",sess->cmd_line);
        //printf("cmd = %s\n",sess->cmd);
        //printf("arg = %s\n",sess->arg);

        //命令查找
        int table_size = sizeof(ctrl_cmds) / sizeof(ctrl_cmds[0]);
        int i;
        for (i = 0;i < table_size;++i)
        {
            if (strcmp(sess->cmd,ctrl_cmds[i].cmd) == 0)
            {
                if (ctrl_cmds[i].cmd_handler)
                    ctrl_cmds[i].cmd_handler(sess);
                else
                    ftp_replay(sess,FTP_COMMANDNOTIMPL,"unimplement command.");
                break;
            }
        }
        if (i >= table_size)
            ftp_replay(sess,FTP_BADCMD,"unknown command.");
    }
}

//验证登陆
static void do_user(session_t *sess)
{
    struct passwd *pwd = getpwnam(sess->arg);
    if (pwd != NULL)
        sess->uid = pwd->pw_uid;//保存用户id
    ftp_replay(sess,FTP_GIVEPWORD,"Please inter the password.");
}
static void do_pass(session_t *sess)
{
    //鉴权登陆
    struct passwd *pwd = getpwuid(sess->uid);
    if (pwd == NULL)
    {
        ftp_replay(sess,FTP_LOGINERR,"Login incorrect.");
        return;
    }
    struct spwd *spd = getspnam(pwd->pw_name);
    if (spd == NULL)
    {
        ftp_replay(sess,FTP_LOGINERR,"Login incorrect.");
        return;
    }
    char *encrypted_pw = crypt(sess->arg,spd->sp_pwdp);
    if (strcmp(encrypted_pw,spd->sp_pwdp) != 0)
    {
        //密码错误
        ftp_replay(sess,FTP_LOGINERR,"Login incorrect.");
        return;
    }
    //更改ftp服务进程
    setegid(pwd->pw_gid);
    seteuid(pwd->pw_uid);
    //调整工作目录
    chdir(pwd->pw_dir);
    ftp_replay(sess,FTP_LOGINOK,"Login successful.");
}
static void do_syst(session_t *sess)
{
    ftp_replay(sess,FTP_SYSTOK,"Linux Type:L8");
}
static void do_feat(session_t *sess)
{
    send(sess->ctrl_fd,"211-Features:\r\n",strlen("211-Features:\r\n"),0);
    send(sess->ctrl_fd,"EPRT\r\n",strlen("EPRT\r\n"),0);
    send(sess->ctrl_fd,"EPSV\r\n",strlen("EPSV\r\n"),0);
    send(sess->ctrl_fd,"MDTM\r\n",strlen("MDTM\r\n"),0);
    send(sess->ctrl_fd,"PASV\r\n",strlen("PASV\r\n"),0);
    send(sess->ctrl_fd,"REST STREAM\r\n",strlen("REST STREAM\r\n"),0);
    send(sess->ctrl_fd,"SIZE\r\n",strlen("SIZE\r\n"),0);
    send(sess->ctrl_fd,"TVFS\r\n",strlen("TVFS\r\n"),0);
    send(sess->ctrl_fd,"UTF8\r\n",strlen("UTF8\r\n"),0);
    send(sess->ctrl_fd,"211 End\r\n",strlen("211 End\r\n"),0);
}
static void do_pwd(session_t *sess)
{
    char cwd[MAX_CMD_SIZE] = {0};
    getcwd(cwd,MAX_CMD_SIZE);
    char text[MAX_CMD_SIZE] = {0};
    sprintf(text,"\"%s\"",cwd);
    ftp_replay(sess,FTP_MKDIROK,text);
}
static void do_type(session_t *sess)
{
    if (strcmp(sess->arg,"A") == 0 || strcmp(sess->arg,"a") == 0)
    {
        //ASCII
        sess->is_ascii = 1;
        ftp_replay(sess,FTP_TYPEOK,"Switching to ASCII mode.");
    }
    else if (strcmp(sess->arg,"I") == 0 || strcmp(sess->arg,"i") == 0)
    {
        //二进制模式
        sess->is_ascii = 0;
        ftp_replay(sess,FTP_TYPEOK,"Switching to Binary mode.");
    }
    else
    {
        ftp_replay(sess,FTP_BADCMD,"Unrecognised TYPE command.");
    }
}

//数据协商
static void do_port(session_t *sess)
{
    //主动模式 服务器主动连接客户端，客户端处于accept状态，服务器处于connect状态
    //解析ip地址和端口号
    unsigned int v[6] = {0};
    sscanf(sess->arg,"%u,%u,%u,%u,%u,%u",&v[0],&v[1],&v[2],&v[3],&v[4],&v[5]);
    sess->port_addr = (struct sockaddr_in*)malloc(sizeof(struct sockaddr));
    //填充协议家族
    sess->port_addr->sin_family = AF_INET;
    //填充端口号
    unsigned char *p = (unsigned char*)&(sess->port_addr->sin_port);
    p[0] = v[4];
    p[1] = v[5];
    //填充ip地址
    p = (unsigned char*)&(sess->port_addr->sin_addr);
    p[0] = v[0];
    p[1] = v[1];
    p[2] = v[2];
    p[3] = v[3];
    ftp_replay(sess,FTP_PORTOK,"PORT command successful.Consider using PASV.");
}
static void do_pasv(session_t *sess)
{
    priv_sock_send_cmd(sess->child_fd,PRIV_SOCK_PASV_LISTEN);
    char ip[16] = {0};
    int len = priv_sock_get_int(sess->child_fd);
    priv_sock_recv_buf(sess->child_fd,ip,len);
    unsigned short port = (unsigned short)priv_sock_get_int(sess->child_fd);


    unsigned v[4] = {0};
    sscanf(ip,"%u.%u.%u.%u",&v[0],&v[1],&v[2],&v[3]);
    char text[MAX_BUFFER_SIZE] = {0};
    sprintf(text,"Entering Passive Mode (%u,%u,%u,%u,%u,%u).",v[0],v[1],v[2],v[3],port>>8,port&0x00ff);
    ftp_replay(sess,FTP_PASVOK,text);
}
//数据连接
int pasv_activate(session_t *sess);
int port_activate(session_t *sess)
{
    if (sess->port_addr != NULL)
    {
        if (pasv_activate(sess))
            ERR_EXIT("both port an pasv are active");
        return 1;
    }
    return 0;
}
int pasv_activate(session_t *sess)
{
    priv_sock_send_cmd(sess->child_fd,PRIV_SOCK_PASV_ACTIVE);
    int active = priv_sock_get_int(sess->child_fd);
    if (sess->pasv_listen_fd != -1)
    {
        if (port_activate(sess))
            ERR_EXIT("both port an pasv are active");
        return 1;
    }
    return 0;
}
int get_port_fd(session_t *sess)
{
    priv_sock_send_cmd(sess->child_fd,PRIV_SOCK_GET_DATA_SOCK);
    //发送ip
    char *ip = inet_ntoa(sess->port_addr->sin_addr);
    priv_sock_send_int(sess->child_fd,strlen(ip));
    priv_sock_send_buf(sess->child_fd,ip,strlen(ip));
    //发送端口
    unsigned short port = ntohs(sess->port_addr->sin_port);
    priv_sock_send_int(sess->child_fd,(int)port);

    char res = priv_sock_get_result(sess->child_fd);
    if (res == PRIV_SOCK_RESULT_BAD)
        return -1;
    sess->data_fd = priv_sock_recv_fd(sess->child_fd);
    return 0;
}
int get_pasv_fd(session_t *sess)
{
    priv_sock_send_cmd(sess->child_fd,PRIV_SOCK_PASV_ACCEPT);
    char res = priv_sock_get_result(sess->child_fd);
    if (res == PRIV_SOCK_RESULT_BAD)
        return -1;
    sess->data_fd = priv_sock_recv_fd(sess->child_fd);
    return 0;
}
static int get_transfer_fd(session_t *sess)
{
    //判断主动模式或者被动模式是否启动
    if (!port_activate(sess) && !pasv_activate(sess))
    {
        ftp_replay(sess,FTP_BADSENDCONN,"Use PORT or PASV first.");
        return -1;
    }
    if (port_activate(sess))
    {
        //创建套接字，连接客户端
        if (get_port_fd(sess) != 0)
            return -1;
    }
    if (pasv_activate(sess))
    {
        if (get_pasv_fd(sess) != 0)
            return -1;
    }
    //释放空间
    if (sess->port_addr)
    {
        free(sess->port_addr);
        sess->port_addr = NULL;
    }
    //开启数据连接空闲断开
    start_data_alarm();
    return 0;
}

void list_common(session_t *sess)
{
    DIR *dir = opendir(".");
    if (dir == NULL)
        ERR_EXIT("open_dir");
    struct stat sbuf;
    char buf[MAX_BUFFER_SIZE] = {0};
    unsigned int offset;
    struct dirent *dt;
    while((dt = readdir(dir)))
    {
        if(stat(dt->d_name,&sbuf) < 0)
            ERR_EXIT("stat");
        if (dt->d_name[0] == '.')
            continue;
        const char *perms = statbuf_get_perms(&sbuf);
        offset = sprintf(buf,"%s",perms);
        offset += sprintf(buf + offset,"%3d %-8d %-8d %8lld ",
                          (int)sbuf.st_nlink,sbuf.st_uid,sbuf.st_gid,(unsigned long long)sbuf.st_size);
        const char *pdata = statbuf_get_date(&sbuf);
        offset += sprintf(buf + offset,"%s ",pdata);
        sprintf(buf + offset,"%s\r\n",dt->d_name);
        send(sess->data_fd,buf,strlen(buf),0);
    }
    closedir(dir);
}
static void do_list(session_t *sess)
{
    //1.创建数据连接
    if (get_transfer_fd(sess) != 0)
        return;
    //2.回复150
    ftp_replay(sess,FTP_DATACONN,"Here comes the directory listing.");
    //3.传输列表
    list_common(sess);
    //4.回复226
    ftp_replay(sess,FTP_TRANSFEROK,"Directory OK.");
    //关闭数据连接
    close(sess->data_fd);
    sess->data_fd = -1;
    //重新开启控制连接断开
    start_cmdio_alarm();
}
static void do_cwd(session_t *sess)
{
    if(chdir(sess->arg) < 0)
        ftp_replay(sess,FTP_NOPERM,"Failed to change directory.");
    else
        ftp_replay(sess,FTP_CWDOK,"Directory successfully changed.");
}
static void do_mkd(session_t *sess)
{
    if (mkdir(sess->arg,0x755) < 0)
        ftp_replay(sess,FTP_NOPERM,"Create directory operation failed.");
    else
    {
        char text[MAX_BUFFER_SIZE] = {0};
        sprintf(text,"\"%s\" created",sess->arg);
        ftp_replay(sess,FTP_MKDIROK,text);
    }
}
static void do_rmd(session_t *sess)
{
    if (rmdir(sess->arg) < 0)
        ftp_replay(sess,FTP_FILEFAIL,"Remove directory operation failed.");
    else
    {
        ftp_replay(sess,FTP_DELEOK,"Remove directory operation successfully.");
    }
}
static void do_dele(session_t *sess)
{
    if (unlink(sess->arg) < 0)
        ftp_replay(sess,FTP_NOPERM,"Delete operation failed.");
    else
        ftp_replay(sess,FTP_DELEOK,"Delete operation successfully");
}
static void do_size(session_t *sess)
{
    struct stat sbuf;
    if (stat(sess->arg,&sbuf) < 0)
        ftp_replay(sess,FTP_FILEFAIL,"Could not get file size.");
    else{
        char text[MAX_BUFFER_SIZE] = {0};
        sprintf(text,"%d",(int)sbuf.st_size);
        ftp_replay(sess, FTP_SIZEOK,text);
    }
}

static void do_rnfr(session_t *sess)
{
    unsigned int len = strlen(sess->arg);
    sess->rnfr_name = (char*)malloc(len + 1);
    memset(sess->rnfr_name,0,len + 1);
    strcpy(sess->rnfr_name,sess->arg);
    ftp_replay(sess,FTP_RNFROK,"Ready for RNTO.");
}
static void do_rnto(session_t *sess)
{
    if(sess->rnfr_name == NULL)
    {
        ftp_replay(sess,FTP_NEEDRNFR,"RNFP required first.");
        return;
    }
    if (rename(sess->rnfr_name,sess->arg) < 0)
    {
        ftp_replay(sess,FTP_NOPERM,"Rename failed.");
        return;
    }
    else
    {
        free(sess->rnfr_name);
        sess->rnfr_name = NULL;
        ftp_replay(sess,FTP_RENAMEOK,"Rename successful.");
    }
}


void limit_rate(session_t *sess,unsigned long bytes_transfer,int is_upload)
{
    //登记结束时间
    unsigned long long cur_sec = get_time_sec();
    unsigned long long cur_usec = get_time_usec();
    double pass_time = (double)(cur_sec - sess->transfer_start_sec);
    pass_time += (double)(cur_usec - sess->transfer_start_usec) / 1000000;
    unsigned long cur_rate = (unsigned long)(bytes_transfer / pass_time);
    double rate_ratio;//速率
    if (is_upload)
    {
        //上传
        if (tunable_upload_max_rate == 0 || cur_rate <= tunable_upload_max_rate)
        {
            //不限速
            sess->transfer_start_sec = get_time_sec();
            sess->transfer_start_usec = get_time_usec();
            return;
        }
        rate_ratio = cur_rate / tunable_upload_max_rate;
    }
    else
    {
        //下载
        if (tunable_download_max_rate == 0 || cur_rate <= tunable_download_max_rate)
        {
            //不限速
            sess->transfer_start_sec = get_time_sec();
            sess->transfer_start_usec = get_time_usec();
            return;
        }
        rate_ratio = cur_rate / tunable_download_max_rate;
    }
    double sleep_time = (rate_ratio - 1) * pass_time;
    //休眠
    nano_sleep(sleep_time);
    //重新登记时间
    sess->transfer_start_sec = get_time_sec();
    sess->transfer_start_usec = get_time_usec();
}
static void do_retr(session_t *sess)
{
    if(get_transfer_fd(sess) != 0)
        return;

    int fd;
    if((fd = open(sess->arg, O_RDONLY)) < 0)
    {
        ftp_replay(sess,FTP_FILEFAIL,"Failed to open file.");
        return;
    }
    struct stat sbuf;
    fstat(fd, &sbuf);
    char buf[MAX_BUFFER_SIZE] = {0};
    if(sess->is_ascii)
        sprintf(buf, "Opening ASCII mode data connection for %s (%u bytes).", sess->arg, (unsigned long long)sbuf.st_size);
    else
        sprintf(buf, "Opening BINARY mode data connection for %s (%u bytes).",sess->arg, (unsigned long long)sbuf.st_size);
    ftp_replay(sess,FTP_DATACONN,buf);

    unsigned long long total_size = sbuf.st_size;
    //断点续载
    unsigned long long offset = sess->restart_pos;
    sess->restart_pos = 0;
    if (offset >= total_size)
    {
        ftp_replay(sess,FTP_TRANSFEROK,"Transfer complete.");
    }
    else {
        if (lseek(fd,offset,SEEK_SET) < 0)
        {
            ftp_replay(sess,FTP_UPLOADFAIL,"Could not create file.");
        }
        else{
            int read_count = 0;
            total_size -= offset;
            //登记时间
            sess->transfer_start_sec = get_time_sec();
            sess->transfer_start_usec = get_time_usec();
            while(1)
            {
                memset(buf, 0, MAX_BUFFER_SIZE);
                read_count = total_size > MAX_BUFFER_SIZE ? MAX_BUFFER_SIZE : total_size;
                int ret = read(fd, buf, read_count);
                if(ret==-1 || ret!=read_count)
                {
                    ftp_replay(sess,FTP_BADSENDNET,"Failure writting to network stream.");
                    break;
                }
                if(ret == 0)
                {
                    ftp_replay(sess,FTP_TRANSFEROK,"Transfer complete.");
                    break;
                }
                sess->data_process = 1;//处于数据连接状态

                //开始限速
                //下载 0 上传 1
                limit_rate(sess,ret,0);
                send(sess->data_fd, buf, ret, 0);
                total_size -= read_count;
            }
        }
    }
    close(fd);
    if(sess->data_fd != -1)
    {
        close(sess->data_fd);
        sess->data_fd = -1;
    }
    start_cmdio_alarm();
}

static void do_stor(session_t *sess)
{
    if(get_transfer_fd(sess) != 0)
        return;

    int fd;
    if((fd = open(sess->arg, O_CREAT|O_WRONLY, 0755)) < 0)
    {
        ftp_replay(sess,FTP_FILEFAIL,"Failed to open file.");
        return;
    }
    ftp_replay(sess,FTP_DATACONN,"Ok to send data.");

    //断点续传
    unsigned long long offset = sess->restart_pos;
    sess->restart_pos = 0;
    if (lseek(fd,offset,SEEK_SET) < 0)
    {
        ftp_replay(sess,FTP_UPLOADFAIL,"Could not create file.");
        return;
    }
    //登记时间
    sess->transfer_start_sec = get_time_sec();
    sess->transfer_start_usec = get_time_usec();
    //传输数据
    char buf[MAX_BUFFER_SIZE] = {0};
    while(1)
    {
        memset(buf, 0, MAX_BUFFER_SIZE);
        int ret = recv(sess->data_fd, buf, MAX_BUFFER_SIZE, 0);
        if(ret == -1)
        {
            ftp_replay(sess,FTP_BADSENDNET,"Failure writting to network stream.");
            break;
        }
        if(ret == 0)
        {
            ftp_replay(sess,FTP_TRANSFEROK,"Transfer complete.");
            break;
        }
        sess->data_process = 1;//处于数据连接状态
        //限速
        limit_rate(sess,ret,1);
        write(fd, buf, ret);
    }

    close(fd);
    if(sess->data_fd != -1)
    {
        close(sess->data_fd);
        sess->data_fd = -1;
    }
    //重新开启
    start_cmdio_alarm();
}

static void do_rest(session_t *sess)
{
    sess->restart_pos = (unsigned long long)atoll(sess->arg);
    char text[MAX_BUFFER_SIZE] = {0};
    sprintf(text,"Restart position accepted (%lld).",sess->restart_pos);
    ftp_replay(sess,"FTP_RESTOK",text);
}
