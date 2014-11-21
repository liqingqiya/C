/*
 *gcc -Wall -g -o epoll_test epoll_test.c
 * 
 * */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    int sockfd;
    struct sockaddr_in server_addr;

    if((sockfd=sock(AF_INET, SOCK_STREAM, 0))==-1){
        fprintf(stderr, "Socket error, %s\r\n", strerror(errno));
        return -1;
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    if(!inet_aton("192.168.1.104", &server_addr.sin_addr)){
        fprintf(stderr, "Bad address:%s\r\n", strerror(errno));
        close(sockfd);
        return -1;
    }

    if(connect(sockfd, (struct sockaddr*)(&server_addr), sizeof(struct sockaddr))==-1){
        fprintf(stderr, "Connect Error:%s\r\n", strerror(errno));
        close(sockfd);
        return -1;
    }

    write(sockfd, "test1", sizeof("test1"));
    write(sockfd, "test2", sizeof("test2"));

    close(sockfd);
    return 0;
}
