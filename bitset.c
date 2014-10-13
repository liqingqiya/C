#include<stdio.h>

int main(){
    int in, out;
    printf("please input a number:\n");
    scanf("%d", &in);
    out=2;
    out|=1<<in;
    printf("in:%d, out:%d\n",in, out);
}
