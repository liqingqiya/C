#include <stdio.h>
#include <stdlib.h>

typedef struct rb_tree_node_s rb_tree_node_t;
typedef struct rb_tree_s rb_tree_t;

struct rb_tree_node_s {
    int                 key;
    rb_tree_node_t      *left;
    rb_tree_node_t      *right;
    rb_tree_node_t      *parent;
};

struct rb_tree_s {
    rb_tree_node_t *root;
};

extern rb_tree_t *rb_tree;

rb_tree_t *rb_tree_create(void);
rb_tree_node_t *rb_tree_insert(rb_tree_t *rb_tree, int key);
void rb_tree_delete(int key);
void rb_tree_middle_show();

static rb_tree_t *
rb_tree_init(rb_tree_t* rb_tree){
    rb_tree->root = NULL;
    return rb_tree;
}
