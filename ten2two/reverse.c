static void 
exchange(char* a, char* b){
    char tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void reverse(char* arr, int n){
    int i=0;
    int j=n-1;
    for(;i<j;){
        exchange(&arr[i++], &arr[j--]);
    }
}
