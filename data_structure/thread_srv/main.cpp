#include "tcpsocket.hpp"
#include <pthread.h>

void *worker(void *arg)
{
    bool ret;
    TcpSocket *new_sock = (TcpSocket*)arg;
    while(1) {
        //5. 通过新建连接与客户端通信
        std::string buf;
        ret = new_sock->Recv(&buf);
        if (ret == false) {
            new_sock->Close();
            delete new_sock;
            return NULL;
        }
        std::cout << "client say: " << buf << std::endl;

        buf.clear();
        std::cout << "server say: ";
        std::cin >> buf;
        ret = new_sock->Send(buf);
        if (ret == false) {
            new_sock->Close();
            delete new_sock;
            return NULL;
        }
    }
    delete new_sock;
    return NULL;
}
int main(int argc, char *argv[])
{
    //argc是程序运行参数的个数
    //argv存放运行参数   ./tcp_srv 192.168.2.2 9000
    if (argc != 3) {
        printf("usage: ./tcp 192.168.2.2 9000\n");
        return -1;
    }
    std::string ip = argv[1];
    uint16_t port = std::stoi(argv[2]);

    TcpSocket lst_sock;
    //1. 创建套接字
    CHECK_RET(lst_sock.Socket());
    //2. 绑定地址信息
    CHECK_RET(lst_sock.Bind(ip, port));
    //3. 开始监听
    CHECK_RET(lst_sock.Listen());
    while(1){
        //4. 获取新建连接
        TcpSocket *new_sock = new TcpSocket();
        bool ret = lst_sock.Accept(new_sock, &ip, &port);
        if (ret == false) {
            usleep(1000);
            continue;
        }
        std::cout << "new conn-" << ip << ":" << port << "\n";
        pthread_t tid;
        pthread_create(&tid, NULL, worker, (void*)new_sock);
        pthread_detach(tid);

    }
    //6. 关闭套接字
    lst_sock.Close();
    return 0;
}
