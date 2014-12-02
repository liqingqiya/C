#include <stdio.h>

#define LX_INT32_LEN (sizeof("-2147483648") -1)
#define LX_INT64_LEN (sizeof("-9223372036854775808") -1)

int 
main(int argc, char *const *argv)
{
    printf("LX_INT32_LEN:%d\n", LX_INT32_LEN);
    printf("LX_INT64_LEN:%d\n", LX_INT64_LEN);
}
