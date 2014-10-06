#include<stdio.h>

#define SIZE ((int)(sizeof(digit_seen)/sizeof(digit_seen[0])))

int main(){
    int digit_seen[10] = {0};
    int digit;
    long n;

    printf("enter a number: ");
    scanf("%d", &n);

    while(n){
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }

    for(int i=0;i<SIZE;i++){
        printf("digit:%d,count:%d,\n",i,digit_seen[i]);
    }

    return 0;
}
