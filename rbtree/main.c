#include "rb_tree.h"

int main(){
    int i;
    int test[7] = {12,2,14,5,31,45,6};
    rb_tree_t *rb;

    rb = rb_tree_create();

    for(i=0; i<7; i++){
        rb_tree_insert(rb, test[i]);
    }
    
    printf("\nraw:");
    for(i = 0; i < 7; i++){
        printf("\t%d\t", test[i]);
    }

    printf("\n");
    rb_tree_middle_show(rb->root);
    printf("\n");

    return 0;
}
