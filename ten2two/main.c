#include<stdio.h>
#include<string.h>
#include"ten_t_two.h"
#include"reverse.h"

int main(){
    int in;
    char arr[100];
    char* p;
    int i=0;

    /*清空内存区域*/
    memset(arr,'\0',sizeof(arr));
    
    printf("please input a number:\n");
    scanf("%d",&in);

    /*转换为二进制，存入数组*/
    ten_t_two(in, arr);

    /*打印数组*/
    p=arr;
    while(*p)
        printf("%c\t",*p++);
    printf("\n");

    /*计算数组个数*/
    p=arr;
    while(*p++&&++i);

    /*反转*/
    reverse(arr,i);

    /*重新打印*/
    p=arr;
    while(*p)
        printf("%c\t",*p++);

    printf("\n");
    return 0;
}
