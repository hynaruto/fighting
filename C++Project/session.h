//
// Created by 胡杨 on 2021/9/25.
//

#ifndef C__PROJECT_SESSION_H
#define C__PROJECT_SESSION_H

#include "Common.h"
typedef struct session
{
    //控制连接
    uid_t uid;
    int ctrl_fd;//用来保存sockConn
    char cmd_line[MAX_COMMOND_LINE_SIZE];
    char cmd[MAX_CMD_SIZE];
    char arg[MAX_ARG_SIZE];
    //ftp协议状态
    int is_ascii;
    //数据连接
    struct sockaddr_in *port_addr;
    //数据链接套接字
    int data_fd;
    int pasv_listen_fd;
    //父子进程通道
    int parent_fd;
    int child_fd;
    char *rnfr_name;
    //文件记录
    unsigned long long restart_pos;
    //限速
    unsigned long long transfer_start_sec;
    unsigned long long transfer_start_usec;
    //数据进程
    int data_process;
    //最大连接数
    unsigned int max_clients;
    unsigned int max_per_ip;
}session_t;
//开始会话
void begin_session(session_t *sess);
#endif //C__PROJECT_SESSION_H
