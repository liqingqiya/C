#include<stdio.h>

void strcpy_qy(char *s1, const char *s2);
void strcat_qy(char *s1, const char *s2);


void strcpy_qy(char *s1, const char *s2){
    while(*s2&&(*s1++=*s2++));
}

void strcat_qy(char *s1, const char *s2){
    char *p=s1;
    while(*p)p++;
    while(*p++=*s2++);
}

int main(){
    char s1[10] = "abcdef";
    char s2[10] = "qe";
    strcpy_qy(s1, s2);
    printf("s1:%s\ns2:%s\n", s1,s2);
    strcat_qy(s1, s2);
    printf("s1:%s\ns2:%s\n", s1,s2);
    return 0;
}
