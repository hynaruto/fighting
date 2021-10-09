//
// Created by 胡杨 on 2021/9/25.
//

#ifndef C__PROJECT_SYSUTIL_H
#define C__PROJECT_SYSUTIL_H

#include "Common.h"

void get_local_ip(char *ip);

int tcp_server(const char *host, unsigned short port);
int tcp_client(int port);
char* statbuf_get_perms(struct stat *sbuf);
char* statbuf_get_date(struct stat *sbuf);
int recv_fd(const int sock_fd);
void send_fd(int sock_fd, int fd);

unsigned long long get_time_sec();
unsigned long long get_time_usec();

void nano_sleep(double sleep_time);
#endif //C__PROJECT_SYSUTIL_H
