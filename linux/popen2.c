#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *fp_write;
    char buffer[BUFSIZ+1];

    sprintf(buffer, "Once upon a time, there was ...\n");
    fp_write = popen("od -c", "w");

    if(fp_write != NULL){
        fwrite(buffer, sizeof(char), strlen(buffer), fp_write);
        pclose(fp_write);
        exit(EXIT_SUCCESS);
    }

    exit(EXIT_FAILURE);
}
