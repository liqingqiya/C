#include<iostream>
#include<cstring>

using std::strlen;

int main(int argc, char* argv[]){
    switch(argc){
        case 1:
            std::cout<<"argc=1"<<std::endl;
            break;
        case 2:
            std::cout<<"argc=2"<<std::endl;
            std::cout<<"len(argv):"<<strlen(argv[1])<<std::endl;
            break;
        default:
            std::cout<<"argc>2"<<std::endl;
    }
    return 0;
}
