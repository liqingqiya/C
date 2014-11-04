#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t pid;
    char *message;
    int n;

    printf("fork program starting\n");

    pid = fork();

    switch(pid){
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "this is child";
            n = 10;
            break;
        default:
            message = "this is parent";
            n = 3;
            break;
    }

    for(; n>0; n--){
        puts(message);
        sleep(1);
    }

    exit(0);
}
