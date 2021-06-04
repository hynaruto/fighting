//
// Created by 胡杨 on 2021/6/4.
//


#include <cstdio>
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

class UdpSocket{
private:
    int _sockfd;
public:
    UdpSocket():_sockfd(-1){}
    bool Socket() {
        _sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (_sockfd < 0) {
            perror("socket error");
            return false;
        }
        return true;
    }
    bool Bind(const std::string &ip, uint16_t port) {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
        socklen_t len = sizeof(struct sockaddr_in);
        int ret = bind(_sockfd, (struct sockaddr*)&addr, len);
        if (ret < 0) {
            perror("bind error");
            return false;
        }
        return true;
    }
    bool Send(const std::string &data,
              const std::string &ip, uint16_t port) {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
        socklen_t len = sizeof(struct sockaddr_in);
        int ret = sendto(_sockfd, data.c_str(), data.size(), 0,
                         (struct sockaddr*)&addr, len);
        if (ret < 0) {
            perror("sendto error");
            return false;
        }
        return true;
    }
    bool Recv(std::string *buf,
              std::string *ip=NULL, uint16_t *port=NULL) {
        struct sockaddr_in addr;
        socklen_t len = sizeof(struct sockaddr_in);
        char tmp[4096] = {0};
        int ret = recvfrom(_sockfd, tmp, 4096, 0,
                           (struct sockaddr*)&addr, &len);
        if (ret < 0) {
            perror("recvfrom error");
            return false;
        }
        buf->assign(tmp, ret);
        if (ip != NULL) {
            *ip = inet_ntoa(addr.sin_addr);
        }
        if (port != NULL) {
            *port = ntohs(addr.sin_port);
        }
        return true;
    }
    bool Close() {
        if(_sockfd != -1) {
            close(_sockfd);
        }
        return true;
    }
};

