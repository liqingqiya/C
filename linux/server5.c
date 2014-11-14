#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<sys/time.h>
#include<sys/ioctl.h>
#include<stdlib.h>

int main(){
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int result;
    fd_set readfds, testfds;

    //创建监听套接字
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);

    //绑定监听地址
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    //开始监听
    listen(server_sockfd, 5);

    FD_ZERO(&readfds);
    //将监听套接字描述符加入到select监听集合中
    FD_SET(server_sockfd, &readfds);

    while(1){
        char ch;
        int fd;
        int nread;

        testfds = readfds;

        printf("server waiting\n");
        //阻塞监听，等待时间发生
        result = select(FD_SETSIZE, &testfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0);
        
        if(result < 1){
            //发生错误了
            perror("server5");
            exit(1);
        }

        //事件发生，轮询找到哪些套接字发生了事件（通过FD_ISSET()来判断）
        for(fd = 0; fd < FD_SETSIZE; fd++){
            if(FD_ISSET(fd, &testfds)){
                if(fd == server_sockfd){//如果是监听套接字发生的事件
                    client_len = sizeof(client_address);
                    //创建套接字
                    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
                    //加入监听集合
                    FD_SET(client_sockfd, &readfds);
                    printf("adding client on fd: %d \n", client_sockfd);
                }
            }else{
                //客户套接字发生的事件，那么就处理
                ioctl(fd, FIONREAD, &nread);

                if(nread == 0){//关闭套接字的事件
                    close(fd);
                    FD_CLR(fd, &readfds);
                    printf("removing client on fd: %d\n", fd);
                }else{//读写事件
                    read(fd, &ch, 1);
                    sleep(5);
                    printf("serving client on fd: %d\n", fd);
                    ch++;
                    write(fd, &ch, 1);
                }
            }
        }
    }
    return 0;
}
