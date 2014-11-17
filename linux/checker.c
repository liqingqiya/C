#include <stdio.h>
#include <stdlib.h>

int main(){
    char *ptr = (char *) malloc(1024);
    char ch;
    /*Uninitialized read, 未定义*/
    ch = ptr[1024];

    /*Write beyond the block, 越界*/
    ptr[1024] = 0;

    /*Orphan the block, 内存泄漏*/
    ptr = 0;
    exit(0);
}
