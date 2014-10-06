#include<stdio.h>
#include<string.h>

int main(){
    char a[10], *s;
    int n=0;
    printf("enter a string:\n");
    scanf("%s",a);
    s = a;
    while(*s++)n++;
    printf("the length is :%d", n);
    return 0;
}
