//
// Created by 胡杨 on 2021/6/4.
//

#ifndef TCP_TCPSOCKET_HPP
#define TCP_TCPSOCKET_HPP
#include <cstdio>
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define CHECK_RET(q) if((q)==false){return -1;}
#define MAX_LISTEN 5
class TcpSocket{
private:
    int _sockfd;
public:
    TcpSocket():_sockfd(-1){}
    bool Socket() {
        _sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
        if (_sockfd < 0) {
            perror("sockert error");
            return false;
        }
        return true;
    }
    void Addr(struct sockaddr_in *addr,
              const std::string &ip, uint16_t port) {
        addr->sin_family = AF_INET;
        addr->sin_port = htons(port);
        addr->sin_addr.s_addr = inet_addr(ip.c_str());
        return ;
    }
    bool Bind(const std::string &ip, uint16_t port) {
        struct sockaddr_in addr;
        Addr(&addr, ip, port);
        socklen_t len = sizeof(struct sockaddr_in);
        int ret = bind(_sockfd, (sockaddr*)&addr, len);
        if (ret < 0) {
            perror("bind error");
            return false;
        }
        return true;
    }
    bool Listen(int backlog = MAX_LISTEN) {
        // int listen(描述符， 同一时间最大连接数)
        int ret = listen(_sockfd, backlog);
        if (ret < 0) {
            perror("listen error");
            return false;
        }
        return true;
    }
    bool Connect(const std::string &ip, uint16_t port){
        struct sockaddr_in addr;
        Addr(&addr, ip, port);
        socklen_t len = sizeof(struct sockaddr_in);
        //int connect(描述符，服务端地址，地址长度)
        int ret = connect(_sockfd, (sockaddr*)&addr, len);
        if (ret < 0) {
            perror("connect error");
            return false;
        }
        return true;
    }
    bool Accept(TcpSocket *sock,
                std::string *ip = NULL,uint16_t *port = NULL){
        //int accept(监听描述符，获取客户端地址，长度)
        struct sockaddr_in addr;
        socklen_t len = sizeof(struct sockaddr_in);
        int newfd = accept(_sockfd,(sockaddr*)&addr,&len);
        if (newfd < 0) {
            perror("accept error");
            return false;
        }
        sock->_sockfd = newfd;
        if (ip != NULL) {
            *ip = inet_ntoa(addr.sin_addr);
        }
        if (port != NULL) {
            *port = ntohs(addr.sin_port);
        }
        return true;
    }

    bool Send(const std::string &data) {
        // ssize_t send(描述， 数据，长度，标志)
        int total = 0;
        while(total < data.size()){
            int ret = send(_sockfd, &data[0]+total,
                           data.size() - total, 0);
            if (ret < 0) {
                perror("send error");
                return false;
            }
            total += ret;
        }
        return true;
    }
    bool Recv(std::string *buf) {
        // ssize_t recv(描述符，缓冲区，长度，标志)
        char tmp[4096] = {0};
        int ret = recv(_sockfd, tmp, 4096, 0);
        if (ret < 0) {
            perror("recv error");
            return false;
        }else if (ret == 0){
            printf("peer shutdown\n");
            return false;
        }
        buf->assign(tmp, ret);//申请空间拷贝指定长度数据
        return true;
    }
    bool Close() {
        if (_sockfd != -1) {
            close(_sockfd);
        }
        return true;
    }
};

#endif //TCP_TCPSOCKET_HPP
