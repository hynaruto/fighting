//
// Created by 胡杨 on 2021/9/25.
//

#include "session.h"
#include "ftp_proto.h"
#include "par_parent.h"
#include "privsock.h"
void begin_session(session_t *sess)
{
    priv_sock_init(sess);
    //在进程组中创建进程
    pid_t pid = fork();
    if (pid == -1)
        ERR_EXIT("session fork");
    if (pid == 0)
    {
        //子进程
        //ftp服务进程
        priv_sock_set_child_context(sess);
        handle_Child(sess);
    }else{
        //父进程
        //nobody进程
        priv_sock_set_parent_context(sess);
        //1.更改nobody进程
        handle_parent(sess);
    }
}