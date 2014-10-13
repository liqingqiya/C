#include"ten_t_two.h"

char*
ten_t_two(int in, char* arr){
    char tmp_t;
    int i=0;
    while(in){
        tmp_t=in%2;
        if(tmp_t==0){
            arr[i++]='0';
        }else if(tmp_t==1){
            arr[i++]='1';
        }
        in/=2;
    }
    return arr;
}
