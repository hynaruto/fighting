#include "tcpsocket.hpp"
#include <signal.h>

void worker(TcpSocket &new_sock)
{
    bool ret;
    while(1){
        //5. 通过新建连接与客户端通信
        std::string buf;
        ret = new_sock.Recv(&buf);
        if (ret == false) {
            new_sock.Close();
            return;
        }
        std::cout << "client say: " << buf << std::endl;

        buf.clear();
        std::cout << "server say: ";
        std::cin >> buf;
        ret = new_sock.Send(buf);
        if (ret == false) {
            new_sock.Close();
            return;
        }
    }
}
int main(int argc, char *argv[])
{
    //argc是程序运行参数的个数
    //argv存放运行参数   ./tcp_srv 192.168.2.2 9000
    if (argc != 3) {
        printf("usage: ./tcp 192.168.2.2 9000\n");
        return -1;
    }
    signal(SIGCHLD, SIG_IGN);//避免产生僵尸进程
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
        TcpSocket new_sock;
        bool ret = lst_sock.Accept(&new_sock, &ip, &port);
        if (ret == false) {
            usleep(1000);
            continue;
        }
        std::cout << "new conn-" << ip << ":" << port << "\n";
        //创建一个新的子进程与客户端进行通信
        pid_t pid = fork();
        if (pid == 0) {
            worker(new_sock);
            new_sock.Close();
            exit(0);
        }
        //这个关闭不会影响客户端-父子进程数据独有
        //反而如果不关闭，会造成资源泄露
        //new_sock.Close();
    }
    //6. 关闭套接字
    lst_sock.Close();
    return 0;
}
