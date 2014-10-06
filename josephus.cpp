#include<iostream>

using std::cout;
using std::endl;

const int N = 10;
const int M = 3;

int main(){
    int t[N] = {0};
    int i = 0, pos=-1;
    int count = 0;
    while(count<=N){
        do{
            pos = (pos+1)%N;
            if(t[pos]==0)i++;
            if(i==M){i=0;break;}
        }while(1);
        t[pos] = count++;
    }
    for(int i=0;i<N;i++){
        cout<<i<<"  "<<t[i]<<endl;
    }
    return 0;
}
