#ifndef C_DROPBOX
#define C_DROPBOX

typedef struct{
    char name;
    int weight;
    int effective_weight;
    int current_weight;
}peer_t ;

//typedef struct peer_s peer_t;

peer_t*
round_robin_get_peer(peer_t* peers[], int n);

#endif
