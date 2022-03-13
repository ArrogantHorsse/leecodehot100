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
        printf("Waiting for data from sender \n");
        count = recvfrom(sk, message, MAX_LEN, 0, (struct sockaddr*)&cli_addr, (socklen_t*)&cli_addr_len);
        if (count == -1) {
            printf("receive data failure\n");
            return -1;
        }
        addr.s_addr = cli_addr.sin_addr.s_addr;

        printf("Receive info: %s from %s %d\n", message, inet_ntoa(addr), cli_addr.sin_port);

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