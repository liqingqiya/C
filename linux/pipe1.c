#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char buffer[BUFSIZ + 1];
    int fd_s[2];
    int n_write, n_read;
    const char *some_data = "some data for test";

    memset(buffer, '\0', sizeof(buffer));

    if(pipe(fd_s) == 0){
        n_write = write(fd_s[1], some_data, strlen(some_data));
        printf("write to the pipe\n");
        n_read = read(fd_s[0], buffer, BUFSIZ);
        printf("read from the pipe :%s\n", buffer);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
