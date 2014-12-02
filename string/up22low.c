#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define lx_low(c) (u_char)((c>='A'&&c<='Z')?(c|0x20):c)
#define lx_up(c)  (u_char)((c>='a'&&c<='z')?(c&~0x20):c)

#define INPUT1 0

int 
main(int argc, char *const *argv)
{
    int i, c;
    char *p;
    printf("please input a string:\n");

#if DEBUG
    char buf[100] = "static test string";
#else
    char buf[100] = {'\0'};
#if INPUT1
    scanf("%s", &buf);
#else
    while((c = getchar()) != '\n'){
        buf[i++] = (u_char)c;
    }
#endif
#endif

    p = buf;
    while(*p){
        *(p++) = lx_low(*p);
    }
    printf("change to low:%s\n", buf);

    p = buf;
    while(*p){
        *(p++) = lx_up(*p);
    }
    printf("change to up:%s\n", buf);

    return 0;
}
