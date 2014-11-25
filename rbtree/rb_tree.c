#include "rb_tree.h"


rb_tree_t *
rb_tree_create(void){
    rb_tree_t *rb_tree;

    rb_tree = malloc(sizeof(rb_tree_t));
    if(rb_tree == NULL){
        fprintf(stderr, "failed malloc");
        exit(EXIT_FAILURE);
    }
    rb_tree_init(rb_tree);
    return rb_tree;
}

rb_tree_node_t *
rb_tree_insert(rb_tree_t* rb_tree, int key){
    rb_tree_node_t *tree_node;
    rb_tree_node_t *x = rb_tree->root;
    rb_tree_node_t *y;

    tree_node = malloc(sizeof(rb_tree_node_t));
    tree_node->key = key;
    tree_node->left = NULL;
    tree_node->right = NULL;
    tree_node->parent = NULL;

    if(x == NULL){
        rb_tree->root = tree_node;
        return tree_node;
    }

    while(x != NULL){
        y = x;
        if(x->key >= key)
            x = x->left;
        else
            x = x->right;
    }   

    if(y->key >= key)
        y->left = tree_node;
    else
        y->right = tree_node;
    
    tree_node->parent = y;
    return tree_node;
}

void 
rb_tree_delete(int key){

}

void 
rb_tree_middle_show(rb_tree_node_t *rb_tree_node){
    rb_tree_node_t *x = rb_tree_node;
    if(x==NULL)
        return;
    rb_tree_middle_show(x->left);
    printf("\t%d\t", x->key);
    rb_tree_middle_show(x->right);
}
