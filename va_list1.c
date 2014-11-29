#include <stdarg.h>
#include <stdio.h>


int 
max_va_list(int n, ...)
{
    va_list ap, ap_dest;
    va_start(ap, n);
    int maximum = -0x7FFFFFFF;
    int temp;
    int i;
    for(i=0; i<n; i++){
        va_copy(ap_dest, ap);
        temp = va_arg(ap, int);
        va_copy(ap_dest, ap);
        if(temp > maximum){
            maximum = temp;
        }
    }
    va_end(ap);
    return maximum;
}


int 
main(int argc, char *const *argv)
{
    printf("max:%d\n", max_va_list(4, 12,31,4,134));
    printf("max:%d\n", max_va_list(3, 12,45,1));
    return 0;
}
