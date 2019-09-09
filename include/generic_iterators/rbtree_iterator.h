#ifndef GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_RED_BLACK_TREE_ITERATOR_H
#define GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_RED_BLACK_TREE_ITERATOR_H

typedef enum RbTreeTravelDirection {
    RBTREE_TRAVEL_LEFT,
    RBTREE_TRAVEL_RIGHT,
    RBTREE_TRAVEL_UP
} RbTreeTravelDirection;

/*
    This algorithm is a specialized version of the one described here:
    https://www.geeksforgeeks.org/inorder-non-threaded-binary-tree-traversal-without-recursion-or-stack/

    It has to take some extra steps to make sure the user can still use
    break and continue inside of the loop and get the expected result.

    The local variables are also somewhat obfuscated to avoid potentiall 
    name collisions, but due to how C shadows variables, it is still
    possible to nest iter statements.
*/

#define rbtree_iter_start(tree_type, tree, out_key, out_value) \
    { \
        RbTreeTravelDirection rb_travel_direction = RBTREE_TRAVEL_LEFT; \
        tree_type ## Node* rbtree_inorder_iter_node = (tree)->root; \
 \
        while(rbtree_inorder_iter_node != NULL) { \
            switch(rb_travel_direction) { \
                case RBTREE_TRAVEL_LEFT: \
                { \
                    while(rbtree_inorder_iter_node->left != NULL) \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->left; \
 \
                    out_key = rbtree_inorder_iter_node->key; \
                    out_value = rbtree_inorder_iter_node->value; \
 \
                    rb_travel_direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
                case RBTREE_TRAVEL_RIGHT: \
                { \
                    rbtree_inorder_iter_node = rbtree_inorder_iter_node->right; \
                    while(rbtree_inorder_iter_node->left != NULL) \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->left; \
 \
                    out_key = rbtree_inorder_iter_node->key; \
                    out_value = rbtree_inorder_iter_node->value; \
 \
                    rb_travel_direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
                case RBTREE_TRAVEL_UP: \
                { \
                    if (rbtree_inorder_iter_node->parent == NULL || \
                        rbtree_inorder_iter_node->parent->right == rbtree_inorder_iter_node)  \
                    { \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->parent; \
                        continue; \
                    } \
 \
                    rbtree_inorder_iter_node = rbtree_inorder_iter_node->parent; \
                    out_key = rbtree_inorder_iter_node->key; \
                    out_value = rbtree_inorder_iter_node->value; \
 \
                    rb_travel_direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
            }

#define rbtree_iter_keys_start(tree_type, tree, out_key) \
    { \
        RbTreeTravelDirection rb_travel_direction = RBTREE_TRAVEL_LEFT; \
        tree_type ## Node* rbtree_inorder_iter_node = (tree)->root; \
 \
        while(rbtree_inorder_iter_node != NULL) { \
            switch(rb_travel_direction) { \
                case RBTREE_TRAVEL_LEFT: \
                { \
                    while(rbtree_inorder_iter_node->left != NULL) \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->left; \
 \
                    out_key = rbtree_inorder_iter_node->key; \
 \
                    rb_travel_direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
                case RBTREE_TRAVEL_RIGHT: \
                { \
                    rbtree_inorder_iter_node = rbtree_inorder_iter_node->right; \
                    while(rbtree_inorder_iter_node->left != NULL) \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->left; \
 \
                    out_key = rbtree_inorder_iter_node->key; \
 \
                    rb_travel_direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
                case RBTREE_TRAVEL_UP: \
                { \
                    if (rbtree_inorder_iter_node->parent == NULL || \
                        rbtree_inorder_iter_node->parent->right == rbtree_inorder_iter_node)  \
                    { \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->parent; \
                        continue; \
                    } \
 \
                    rbtree_inorder_iter_node = rbtree_inorder_iter_node->parent; \
                    out_key = rbtree_inorder_iter_node->key; \
 \
                    rb_travel_direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
            }

#define rbtree_iter_values_start(tree_type, tree, out_value) \
    { \
        RbTreeTravelDirection rb_travel_direction = RBTREE_TRAVEL_LEFT; \
        tree_type ## Node* rbtree_inorder_iter_node = (tree)->root; \
 \
        while(rbtree_inorder_iter_node != NULL) { \
            switch(rb_travel_direction) { \
                case RBTREE_TRAVEL_LEFT: \
                { \
                    while(rbtree_inorder_iter_node->left != NULL) \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->left; \
 \
                    out_value = rbtree_inorder_iter_node->value; \
 \
                    rb_travel_direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
                case RBTREE_TRAVEL_RIGHT: \
                { \
                    rbtree_inorder_iter_node = rbtree_inorder_iter_node->right; \
                    while(rbtree_inorder_iter_node->left != NULL) \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->left; \
 \
                    out_value = rbtree_inorder_iter_node->value; \
 \
                    rb_travel_direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
                case RBTREE_TRAVEL_UP: \
                { \
                    if (rbtree_inorder_iter_node->parent == NULL || \
                        rbtree_inorder_iter_node->parent->right == rbtree_inorder_iter_node)  \
                    { \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->parent; \
                        continue; \
                    } \
 \
                    rbtree_inorder_iter_node = rbtree_inorder_iter_node->parent; \
                    out_value = rbtree_inorder_iter_node->value; \
 \
                    rb_travel_direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
            }


#define rbtree_iter_end } }

#endif