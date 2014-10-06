#include<iostream>

int func(int x){
    int count = 0;
    while(x){
        count++;
        x=x&(x-1);
    }
    return count;
}

int main(){
    std::cout<<func(9999)<<std::endl;
    return 0;
}
