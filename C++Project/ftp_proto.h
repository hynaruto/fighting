//
// Created by 胡杨 on 2021/9/25.
//

#ifndef C__PROJECT_FTP_PROTO_H
#define C__PROJECT_FTP_PROTO_H

#endif //C__PROJECT_FTP_PROTO_H

#include "Common.h"
#include "session.h"
void handle_Child(session_t *session);
void ftp_replay(session_t *sess, unsigned int code,const char *text);