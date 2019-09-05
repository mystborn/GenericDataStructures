#ifndef GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_RED_BLACK_TREE_ITERATOR_H
#define GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_RED_BLACK_TREE_ITERATOR_H

typedef enum rbtree_travel_direction {
    RBTREE_TRAVEL_LEFT,
    RBTREE_TRAVEL_RIGHT,
    RBTREE_TRAVEL_UP
} rbtree_travel_direction;

/*
    This iterator is far more complicated than the others, so I'll try and
    describe what's happening step by step.

    0.  This process needs a couple of variables, so we start a new scope to
        avoid name collisions. 

    1.  The current node is set to the root of the tree.
    2.  While the node is not NULL, it iterates. This is important because
        it will stop the iteration early if the root is NULL.
    3.  Starting with left, it performs one of the iteration steps.
        - Left: This step will only happen once. It goes as far left as possible,
                sets the key and value to the nodes contents, then chooses the
                next diection.
        -Right: This step will only be reached if there was a right node. If
                so, it moves to the right node, then travels all the way to
                left. It sets the key and value, then chooses a direction.
                Because this step also moves left, the left direction
                will not be chosen again.
        - Up:   First this step makes sure we're not finished by checking to
                see if the parent node is not NULL. If it is, we've reached
                the root node from the right and have finished the iteration.
                Then, as long as we're coming from the right, the parent node
                will have already been processed, so we just go up a node.
                Finally, we're coming from the left. When this happens,
                the parent has not been processed, so we set the key and value
                and chooses the next direction.

    4.  Choosing a direction: Each step ends with this. All this does is check
        if there is any nodes to the right that need to be processed, and if so
        the next step will move right, otherwise we'll move up the tree.

    The macro is set up so that if a user wants to exit the iteration early,
    they can still use break.
*/

#define rbtree_iter_start(tree_type, tree, out_key, out_value) \
    { \
        rbtree_travel_direction direction = RBTREE_TRAVEL_LEFT; \
        tree_type ## Node* rbtree_inorder_iter_node = (tree)->root; \
 \
        while(rbtree_inorder_iter_node != NULL) { \
            switch(direction) { \
                case RBTREE_TRAVEL_LEFT: \
                { \
                    while(rbtree_inorder_iter_node->left != NULL) \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->left; \
 \
                    out_key = rbtree_inorder_iter_node->key; \
                    out_value = rbtree_inorder_iter_node->value; \
 \
                    direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
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
                    direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
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
                    direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
            }

#define rbtree_iter_keys_start(tree_type, tree, out_key) \
    { \
        rbtree_travel_direction direction = RBTREE_TRAVEL_LEFT; \
        tree_type ## Node* rbtree_inorder_iter_node = (tree)->root; \
 \
        while(rbtree_inorder_iter_node != NULL) { \
            switch(direction) { \
                case RBTREE_TRAVEL_LEFT: \
                { \
                    while(rbtree_inorder_iter_node->left != NULL) \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->left; \
 \
                    out_key = rbtree_inorder_iter_node->key; \
 \
                    direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
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
                    direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
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
                    direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
            }

#define rbtree_iter_values_start(tree_type, tree, out_value) \
    { \
        rbtree_travel_direction direction = RBTREE_TRAVEL_LEFT; \
        tree_type ## Node* rbtree_inorder_iter_node = (tree)->root; \
 \
        while(rbtree_inorder_iter_node != NULL) { \
            switch(direction) { \
                case RBTREE_TRAVEL_LEFT: \
                { \
                    while(rbtree_inorder_iter_node->left != NULL) \
                        rbtree_inorder_iter_node = rbtree_inorder_iter_node->left; \
 \
                    out_value = rbtree_inorder_iter_node->value; \
 \
                    direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
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
                    direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
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
                    direction = rbtree_inorder_iter_node->right == NULL ? RBTREE_TRAVEL_UP : RBTREE_TRAVEL_RIGHT; \
                    break; \
                } \
            }


#define rbtree_iter_end } }

#endif