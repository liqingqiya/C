#include<iostream>

//归并排序
void quick(int* p , int p, int r){

}

//归并
void merge(int* s, int p, int q, int r){
    /*
     0, 2, 4
     3+1 
     2+1
     5
    */
    int n_1 = q-p+2;
    int n_2 = r-q+1;
    int n_3 = r-p+1;

    int* a=new int[n_1];
    int* b=new int[n_2];

    for(int i=0;i<n_1;i++){
        if(i==n_1-1){
            a[i] = 9999;
        }else{
            a[i] = s[i+p];
        }
    }
    
    for(int i=0;i<n_2;i++){
        if(i==n_2-1){
            b[i] = 9999;
        }else{
            b[i] = s[i+q+1];
        }
    }

    int m=0;
    int n=0;
    for(int i=p;i<=r;i++){
        if(a[m]>b[n]){
            s[i]=b[n++];
        }else{
            s[i]=a[m++];
        }
    }
}

void sort(int s[], int p, int q, int r){
    //

}

int main(){
    int size_n = 10;
    int a[size_n] = {12,3,1,3,12,134,45,74,1122,52};


    return 0;
}
