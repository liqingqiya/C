#include<iostream>

//using namespace std::cout;
//using namespace std::endl;

void print(int* a, int n){
    for(int i=0;i<n;i++){
        std::cout<<"i:"<<i<<"  "<<"a[i]"<<a[i]<<std::endl;
    }
}

void print(int a){
    std::cout<<a<<std::endl;
}

int main(){
    int a[12] = {1,2,3,7,56,6,434232,1,212,4,5,7};
    int size_n = 10;

    for(int gap=size_n/2;gap>0;gap/=2){
        for(int i=0;i<=size_n-gap;i++){
            for(int m=i+gap;m<size_n;m+=gap){
                int key = a[m];
                int n = m-gap;
                while((n>0)&&(a[n]>=key)){
                    a[n+gap] = a[n];
                    n -= gap;
                }
                a[n+gap] = key;
            }
        }
    }
    print(a,10);
    return 0;
}
