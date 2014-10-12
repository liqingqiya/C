#include<stdio.h>
#include"round_robin.h"

int main(){
    peer_t a={'a',5,0,5};
    peer_t b={'b',1,0,1};
    peer_t c={'c',1,0,1};

    peer_t* peers[3]={&a,&b,&c};

    peer_t* ret_peer;

    int i;

    for(i=0;i<10;i++){
        ret_peer = round_robin_get_peer(peers, 3);
        //printf("%c\t", ret_peer->name);
    }

    printf("\ndone\n");

    return 0;
}
