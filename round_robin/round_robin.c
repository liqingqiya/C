#include<stdio.h>
#include"round_robin.h"

peer_t*
round_robin_get_peer(peer_t* peers[], int n){
    
    peer_t* best=peers[0];
    int total_weight=0;
    int i;

    for(i=0;i<n;i++){
        peers[i]->current_weight += peers[i]->effective_weight;
        total_weight+=peers[i]->effective_weight;

        if(peers[i]->effective_weight<peers[i]->weight){
            peers[i]->effective_weight++;
        }
        if(best->current_weight<peers[i]->current_weight)
            best = peers[i];
    }

    best->current_weight-=total_weight;
    printf("choose:%c, a:%d, b:%d, c:%d\n", best->name, peers[0]->current_weight, peers[1]->current_weight, peers[2]->current_weight);
    return best;
}
