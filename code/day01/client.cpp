/*
 * @Author: your name
 * @Date: 2022-01-04 20:03:45
 * @LastEditTime: 2022-01-05 19:08:58
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \30dayMakeCppServer\code\day01\client.cpp
 */

#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

// 链接 Winsock 库
#pragma comment(lib, "ws2_32.lib")

int main() {

    WSADATA wsaData; // WSADATA is a struct defined in winsock2.h
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    //bind(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)); 客户端不进行bind操作

    connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr));    
    
    closesocket(sockfd);
    WSACleanup();

    return 0;
}
