//
// Created by 胡杨 on 2021/9/26.
//

#ifndef C__PROJECT_COMMON_H
#define C__PROJECT_COMMON_H

#endif //C__PROJECT_COMMON_H
#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pwd.h>
#include <crypt.h>
#include<shadow.h>
#include <dirent.h>
#include<sys/stat.h>
#include <time.h>
#include <signal.h>
#include "sysutil.h"
#include "session.h"
#include <assert.h>
#include <sys/wait.h>
#include <linux/capability.h>
#include <sys/syscall.h>
#include <netdb.h>

#define MAX_COMMOND_LINE_SIZE 1024
#define MAX_CMD_SIZE          128
#define MAX_ARG_SIZE          1024
#define MAX_BUFFER_SIZE       1024
#define MAX_CWD_SIZE          512
#define MAX_SETTING_LINE_SIZE 1024
#define MAX_KEY_SIZE 128
#define MAX_VALUE_SIZE 512
#define MAX_BUCKET_SIZE 191
#define MAX_HOST_NAME_SIZE 256


#define ERR_EXIT(msg)\
do{\
    perror(msg);\
    exit(EXIT_FAILURE);\
}while(0)