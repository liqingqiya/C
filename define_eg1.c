#include <stdio.h>

#define LX1 1
#define LX2 1

#if (LX1)

void *
test(void)
{
    printf("test LX1\n");
    return NULL;
}

#elif (LX2)

void *
test(void)
{
    printf("test LX2\n");
    return NULL;
}

#endif

int
main(int argc, char *const *argv)
{

    test();
    return 0;
}
