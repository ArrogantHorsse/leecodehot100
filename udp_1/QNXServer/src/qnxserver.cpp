#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define MAX_LEN 1000

int str_to_number(const char* str);
int sendReply();
int main(int argc, char** argv) {
    char message[MAX_LEN];
    int sk;
    struct sockaddr_in src_addr;  //用于指定本地监听信息
    struct sockaddr_in cli_addr;  //獲取客戶端地址信息
    int src_addr_len, cli_addr_len;
    int count, ret;
    struct in_addr addr;

    if (argc != 2)  //获取监听端口
    {
        printf("Error: you must enter port to monite\n");
        exit(0);
    }

    bzero(&src_addr, sizeof(src_addr));
    src_addr.sin_family = AF_INET;
    src_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //作为服务器，可能有多块网卡，设置INADDR_ANY，表示绑定一个默认网卡进行监听
    src_addr.sin_port = htons(str_to_number(argv[1]));

    printf("port:%d\n", str_to_number(argv[1]));

    src_addr_len = sizeof(src_addr);
    cli_addr_len = sizeof(cli_addr);

    sk = socket(AF_INET, SOCK_DGRAM, 0);
    if (sk < 0) {
        printf("socket create failure\n");
        return -1;
    }

    ret = bind(sk, (struct sockaddr*)&src_addr, src_addr_len);
    if (ret < 0) {
        printf("socket bind failure\n");
        return -1;
    }

    while (1) {
        printf("========================Waiting for data from sender ================================\n");
        count = recvfrom(sk, message, MAX_LEN, 0, (struct sockaddr*)&cli_addr, (socklen_t*)&cli_addr_len);
        if (count == -1) {
            printf("receive data failure\n");
            return -1;
        }
        addr.s_addr = cli_addr.sin_addr.s_addr;

        printf("Receive info: %s \n", message);
        printf("Receive info from %s %d\n", inet_ntoa(addr), cli_addr.sin_port);
        sendReply();
        sendto(sk, message, sizeof(message), 0, (struct sockaddr*)&cli_addr, cli_addr_len);
    }

    close(sk);

    return 0;
}

int str_to_number(const char* str) {
    int i, len, num = 0;
    len = strlen(str);

    for (i = 0; i < len; i++) num = num * 10 + str[i] - '0';

    return num;
}

int sendReply() {
    int sk;
    char buf[MAX_LEN] = "I am QNX,I receive a message, this id reply";
    struct sockaddr_in ser_addr;  //是用于指定对方(目的主机)信息
    struct sockaddr_in loc_addr;  //可以用来指定一些本地的信息，比如指定端口进行通信，而不是让系统随机分配
    int ser_addr_len, loc_addr_len;
    int ret, count;
    struct in_addr addr;

    // if (argc != 3) {
    //     printf("Error: the number of args must be 3\n");
    //     exit(0);
    // }

    //配置服务器信息
    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;                      //设置为IPV4通信
    ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //设置目的ip
    ser_addr.sin_port = htons(str_to_number("8081"));   //设置目的端口去链接服务器
    ser_addr_len = sizeof(ser_addr);

    sk = socket(AF_INET, SOCK_DGRAM, 0);  //设置UDP报文传输    0表示默认    SOCK_DGRAM 默认使用UDP
    //其中第三位 0 是调用方式标志位，设置socket通方式，比如非阻塞
    if (sk < 0) {
        printf("socket create failure\n");
        return -1;
    }

    sendto(sk, buf, sizeof(buf), 0, (struct sockaddr*)&ser_addr, ser_addr_len);

    // count = recvfrom(sk, buf, sizeof(buf), 0, (struct sockaddr*)&loc_addr, (socklen_t*)&loc_addr_len);
    // if (count == -1) {
    //     printf("receive data failure\n");
    //     return -1;
    // }
    // addr.s_addr = loc_addr.sin_addr.s_addr;
    // printf("Receive info: %s from %s %d\n", buf, inet_ntoa(addr), loc_addr.sin_port);

    printf("communicate end\n");
    close(sk);
    return 0;
}