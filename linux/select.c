#include<sys/types.h>
#include<sys/time.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    char buffer[128];
    int result, nread;

    fd_set inputs, testfds;
    struct timeval timeout;

    FD_ZERO(&inputs);
    /*将文件描述符0加入到监听集合，标准输入的描述符号为0*/
    FD_SET(0, &inputs);

    while(1){
        testfds = inputs;
        timeout.tv_sec = 2;
        timeout.tv_usec = 500000;

        //result  = select(FD_SETSIZE, &testfds, (fd_set*)NULL, (fd_set*)NULL, &timeout);
        //阻塞监听，等待事件发生
        result  = select(FD_SETSIZE, &testfds, (fd_set*)NULL, (fd_set*)NULL, (struct timeval *)NULL);

        switch(result){
            case 0:
                //超时
                printf("timeout\n");
                break;
            case -1:
                //错误
                perror("select");
                exit(1);
            default:
                if(FD_ISSET(0, &testfds)){
                    ioctl(0, FIONREAD, &nread);
                    if(nread==0){
                        printf("keyboard done\n");
                        exit(0);
                    }
                    nread = read(0, buffer, nread);
                    buffer[nread] = 0;
                    printf("read %d from keyboard: %s", nread, buffer);
                }
                break;
        }
    }
    return 0;
}
