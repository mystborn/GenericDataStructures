#ifndef GENERIC_DATA_STRUCTURES_RED_BLACK_TREE_H
#define GENERIC_DATA_STRUCTURES_RED_BLACK_TREE_H

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

// Macros to define a strongly typed rb-tree data structure.
// TODO: Return error value if a new node fails to allocate.

typedef enum RBColor {
    RB_BLACK,
    RB_RED
} RBColor;

#define RBTREE_DEFINE_H(type_name, function_prefix, key_type, value_type) \
    typedef struct type_name ## Node type_name ## Node; \
    struct type_name ## Node { \
        type_name ## Node* left; \
        type_name ## Node* right; \
        type_name ## Node* parent; \
        key_type key; \
        value_type value; \
        RBColor color; \
    }; \
    \
    typedef struct type_name { \
        type_name ## Node* root; \
        unsigned int count; \
    } type_name; \
    \
    void function_prefix ## _init(type_name* tree); \
    void function_prefix ## _free(type_name* tree); \
    void function_prefix ## _add(type_name* tree, key_type key, value_type value); \
    value_type function_prefix ## _remove(type_name* tree, key_type key); \
    value_type function_prefix ## _remove_min(type_name* tree); \
    value_type function_prefix ## _remove_max(type_name* tree); \
    value_type function_prefix ## _get(type_name* tree, key_type key); \
    value_type function_prefix ## _get_min(type_name* tree); \
    value_type function_prefix ## _get_max(type_name* tree); \
    static inline type_name ## Node* function_prefix ## _root(type_name* tree) { return tree->root; } \
    static inline unsigned int function_prefix ## _count(type_name* tree) { return tree->count; }

#define RBTREE_DEFINE_C(type_name, function_prefix, key_type, value_type, compare_fn, default_value) \
    static inline type_name ## Node* function_prefix ## _parent(type_name ## Node* node) { \
        return node->parent; \
    } \
    \
    static inline type_name ## Node* function_prefix ## _grandparent(type_name ## Node* node) { \
        type_name ## Node* parent = function_prefix ## _parent(node); \
        if(parent == NULL) \
            return NULL; \
        return function_prefix ## _parent(parent); \
    } \
    \
    static inline type_name ## Node* function_prefix ## _sibling(type_name ## Node* node) { \
        type_name ## Node* parent = function_prefix ## _parent(node);\
        if(parent == NULL) \
            return NULL; \
        if(node == parent->left) \
            return parent->right; \
        else \
            return parent->left; \
    } \
    \
    static inline type_name ## Node* function_prefix ## _uncle(type_name ## Node* node) { \
        type_name ## Node* parent = function_prefix ## _parent(node); \
        type_name ## Node* grandparent = function_prefix ## _grandparent(node); \
        if(grandparent == NULL) \
            return NULL; \
        return function_prefix ## _sibling(parent); \
    } \
    \
    static inline RBColor function_prefix ## _color(type_name ## Node* node) { \
        return node == NULL ? RB_BLACK : node->color; \
    } \
    \
    void function_prefix ## _init(type_name* tree) { \
        tree->root = NULL; \
        tree->count = 0; \
    } \
    \
    static type_name ## Node* function_prefix ## _max_node(type_name ## Node* node) { \
        while(node->right != NULL) \
            node = node->right; \
        \
        return node; \
    } \
    \
    static type_name ## Node* function_prefix ## _min_node(type_name ## Node* node) { \
        while(node->left != NULL) \
            node = node->left; \
        \
        return node; \
    } \
    \
    static type_name ## Node* function_prefix ## _get_node(type_name* tree, key_type key) { \
        type_name ## Node* node = tree->root; \
        while(node != NULL) { \
            int result = compare_fn(key, node->key); \
            if(result == 0) \
                return node; \
            else if(result < 0) \
                node = node->left; \
            else \
                node = node->right; \
        } \
        return NULL; \
    } \
    \
    value_type function_prefix ## _get(type_name* tree, key_type key) { \
        type_name ## Node* node = function_prefix ## _get_node(tree, key); \
        if(node != NULL) \
            return node->value; \
         \
        return default_value; \
    } \
    \
    value_type function_prefix ## _get_min(type_name* tree) { \
        if(tree->root == NULL) \
            return default_value; \
        return function_prefix ## _min_node(tree->root)->value; \
    } \
    \
    value_type function_prefix ## _get_max(type_name* tree) { \
        if(tree->root == NULL) \
            return default_value; \
        return function_prefix ## _max_node(tree->root)->value; \
    } \
    \
    static void function_prefix ## _insert_repair_tree(type_name* tree, type_name ## Node* node); \
    \
    static void function_prefix ## _replace_node(type_name* tree, type_name ## Node* old_node, type_name ## Node* new_node) { \
        if(old_node->parent == NULL) { \
            tree->root = new_node;\
        } else {\
            if(old_node == old_node->parent->left) \
                old_node->parent->left = new_node; \
            else \
                old_node->parent->right = new_node; \
        } \
        if(new_node != NULL) \
            new_node->parent = old_node->parent; \
    } \
    \
    static void function_prefix ## _rotate_left(type_name* tree, type_name ## Node* node) { \
        type_name ## Node* right = node->right; \
        function_prefix ## _replace_node(tree, node, right); \
        node->right = right->left; \
        if(right->left != NULL) \
            right->left->parent = node; \
        right->left = node; \
        node->parent = right; \
    } \
    \
    static void function_prefix ## _rotate_right(type_name* tree, type_name ## Node* node) { \
        type_name ## Node* left = node->left; \
        function_prefix ## _replace_node(tree, node, left); \
        node->left = left->right; \
        if(left->right != NULL) \
            left->right->parent = node; \
        left->right = node; \
        node->parent = left; \
    } \
    \
    static void function_prefix ## _rotate_left_(type_name* tree, type_name ## Node* node) { \
        type_name ## Node* right = node->right; \
        type_name ## Node* parent = function_prefix ## _parent(node); \
        node->right = right->left; \
        right->left = node; \
        node->parent = right; \
        if(node->right != NULL) \
            node->right->parent = node; \
        function_prefix ## _replace_node(tree, node, right); \
    } \
    \
    static void function_prefix ## _rotate_right_(type_name* tree, type_name ## Node* node) { \
        type_name ## Node* left = node->left; \
        type_name ## Node* parent = function_prefix ## _parent(node); \
        node->left = left->right; \
        left->right = node; \
        node->parent = left; \
        if(node->left != NULL) \
            node->left->parent = node; \
        function_prefix ## _replace_node(tree, node, left); \
    } \
    \
    static void function_prefix ## _insert_case1(type_name ## Node* node) { \
        if(function_prefix ## _parent(node) == NULL) \
            node->color = RB_BLACK; \
    } \
    \
    static void function_prefix ## _insert_case2(type_name ## Node* node) { \
        return; \
    } \
    \
    static void function_prefix ## _insert_case3(type_name* tree, type_name ## Node* node) { \
        function_prefix ## _parent(node)->color = RB_BLACK; \
        function_prefix ## _uncle(node)->color = RB_BLACK; \
        type_name ## Node* grandparent = function_prefix ## _grandparent(node); \
        grandparent->color = RB_RED; \
        function_prefix ## _insert_repair_tree(tree, grandparent); \
    } \
    \
    static void function_prefix ## _insert_case4(type_name* tree, type_name ## Node* node) { \
        if(node == node->parent->right && node->parent == function_prefix ## _grandparent(node)->left) { \
            function_prefix ## _rotate_left(tree, node->parent); \
            node = node->left; \
        } else if(node == node->parent->left && node->parent == function_prefix ## _grandparent(node)->right) { \
            function_prefix ## _rotate_right(tree, node->parent); \
            node = node->right; \
        } \
        \
        node->parent->color = RB_BLACK; \
        function_prefix ## _grandparent(node)->color = RB_RED; \
        if(node == node->parent->left && node->parent == function_prefix ## _grandparent(node)->left) \
            function_prefix ## _rotate_right(tree, function_prefix ## _grandparent(node)); \
        else {\
            function_prefix ## _rotate_left(tree, function_prefix ## _grandparent(node)); \
        } \
    } \
    \
    static void function_prefix ## _insert_repair_tree(type_name* tree, type_name ## Node* node) { \
        if(function_prefix ## _parent(node) == NULL) \
            function_prefix ## _insert_case1(node); \
        else if(function_prefix ## _color(node->parent) == RB_BLACK) \
            function_prefix ## _insert_case2(node); \
        else if(function_prefix ## _color(function_prefix ## _uncle(node)) == RB_RED) \
            function_prefix ## _insert_case3(tree, node); \
        else \
            function_prefix ## _insert_case4(tree, node); \
    } \
    \
    static type_name ## Node* function_prefix ## _new_node(key_type key, value_type value, RBColor color, type_name ## Node* left, type_name ## Node* right) { \
        type_name ## Node* node = malloc(sizeof(struct type_name ## Node)); \
        node->key = key; \
        node->value = value; \
        node->color = color; \
        node->left = left; \
        node->right = right; \
        if(left != NULL) \
            left->parent = node; \
        if(right != NULL) \
            right->parent = node; \
        node->parent = NULL; \
        return node; \
    } \
    \
    void function_prefix ## _add(type_name* tree, key_type key, value_type value) { \
        type_name ## Node* node = malloc(sizeof(type_name ## Node)); \
        assert(node); \
        node->key = key; \
        node->value = value; \
        node->color = RB_RED; \
        node->parent = NULL; \
        node->left = NULL; \
        node->right = NULL; \
        if(tree->root == NULL) \
            tree->root = node; \
        else { \
            type_name ## Node* parent = NULL; \
            type_name ## Node* current = tree->root; \
            while(current != NULL) { \
                parent = current; \
                \
                if(compare_fn(key, current->key) < 0) \
                    current = current->left; \
                else \
                    current = current->right; \
            } \
            \
            node->parent = parent; \
            \
            if(compare_fn(key, parent->key) < 0) \
                parent->left = node; \
            else \
                parent->right = node; \
        } \
        tree->count++; \
        function_prefix ## _insert_repair_tree(tree, node); \
    } \
    \
    static void function_prefix ## _delete_case1(type_name* tree, type_name ## Node* node); \
    static void function_prefix ## _delete_case2(type_name* tree, type_name ## Node* node); \
    static void function_prefix ## _delete_case3(type_name* tree, type_name ## Node* node); \
    static void function_prefix ## _delete_case4(type_name* tree, type_name ## Node* node); \
    static void function_prefix ## _delete_case5(type_name* tree, type_name ## Node* node); \
    static void function_prefix ## _delete_case6(type_name* tree, type_name ## Node* node); \
    \
    static void function_prefix ## _delete_case1(type_name* tree, type_name ## Node* node) { \
        if(node->parent == NULL) \
            return; \
        else \
            function_prefix ## _delete_case2(tree, node); \
    } \
    \
    static void function_prefix ## _delete_case2(type_name* tree, type_name ## Node* node) { \
        if (function_prefix ## _color(function_prefix ## _sibling(node)) == RB_RED) { \
            node->parent->color = RB_RED; \
            function_prefix ## _sibling(node)->color = RB_BLACK; \
            if(node == node->parent->left) \
                function_prefix ## _rotate_left(tree, node->parent); \
            else \
                function_prefix ## _rotate_right(tree, node->parent); \
        } \
        function_prefix ## _delete_case3(tree, node); \
    } \
    \
    static void function_prefix ## _delete_case3(type_name* tree, type_name ## Node* node) { \
        if (function_prefix ## _color(node->parent) == RB_BLACK && \
            function_prefix ## _color(function_prefix ## _sibling(node)) == RB_BLACK &&  \
            function_prefix ## _color(function_prefix ## _sibling(node)->left) == RB_BLACK && \
            function_prefix ## _color(function_prefix ## _sibling(node)->right) == RB_BLACK) \
        { \
            function_prefix ## _sibling(node)->color = RB_RED; \
            function_prefix ## _delete_case1(tree, node->parent); \
        } \
        else \
            function_prefix ## _delete_case4(tree, node); \
    }\
    \
    static void function_prefix ## _delete_case4(type_name* tree, type_name ## Node* node) { \
        if (function_prefix ## _color(node->parent) == RB_RED && \
            function_prefix ## _color(function_prefix ## _sibling(node)) == RB_BLACK &&  \
            function_prefix ## _color(function_prefix ## _sibling(node)->left) == RB_BLACK && \
            function_prefix ## _color(function_prefix ## _sibling(node)->right) == RB_BLACK) \
        { \
            function_prefix ## _sibling(node)->color = RB_RED; \
            node->parent->color = RB_BLACK; \
        } \
        else \
            function_prefix ## _delete_case5(tree, node); \
    } \
    \
    static void function_prefix ## _delete_case5(type_name* tree, type_name ## Node* node) {\
        if (node == node->parent->left && \
            function_prefix ## _color(function_prefix ## _sibling(node)) == RB_BLACK && \
            function_prefix ## _color(function_prefix ## _sibling(node)->left) == RB_RED && \
            function_prefix ## _color(function_prefix ## _sibling(node)->right) == RB_BLACK)  \
        { \
            function_prefix ## _sibling(node)->color = RB_RED; \
            function_prefix ## _sibling(node)->left->color = RB_BLACK; \
            function_prefix ## _rotate_right(tree, function_prefix ## _sibling(node)); \
        } \
        else if(node == node->parent->right && \
                function_prefix ## _color(function_prefix ## _sibling(node)) == RB_BLACK && \
                function_prefix ## _color(function_prefix ## _sibling(node)->right) == RB_RED && \
                function_prefix ## _color(function_prefix ## _sibling(node)->left) == RB_BLACK)  \
        { \
            function_prefix ## _sibling(node)->color = RB_RED; \
            function_prefix ## _sibling(node)->right->color = RB_BLACK; \
            function_prefix ## _rotate_left(tree, function_prefix ## _sibling(node)); \
        } \
        function_prefix ## _delete_case6(tree, node); \
    } \
    \
    static void function_prefix ## _delete_case6(type_name* tree, type_name ## Node* node) { \
        function_prefix ## _sibling(node)->color = function_prefix ## _color(node->parent); \
        node->parent->color = RB_BLACK; \
        if(node == node->parent->left) { \
            function_prefix ## _sibling(node)->right->color = RB_BLACK; \
            function_prefix ## _rotate_left(tree, node->parent); \
        } else { \
            function_prefix ## _sibling(node)->left->color = RB_BLACK; \
            function_prefix ## _rotate_right(tree, node->parent); \
        } \
    } \
    \
    static void function_prefix ## _remove_node(type_name* tree, type_name ## Node* node) { \
        if(node->left != NULL && node->right != NULL) { \
            type_name ## Node* pred = function_prefix ## _max_node(node->left); \
            node->key = pred->key; \
            node->value = pred->value; \
            node = pred; \
        } \
 \
        type_name ## Node* child = node->right == NULL ? node->left : node->right; \
        if(function_prefix ## _color(node) == RB_BLACK) { \
            node->color = function_prefix ## _color(child); \
            function_prefix ## _delete_case1(tree, node); \
        } \
        function_prefix ## _replace_node(tree, node, child); \
        if(node->parent == NULL && child != NULL) \
            child->color = RB_BLACK; \
        \
        free(node); \
        \
        tree->count--; \
    } \
    \
    value_type function_prefix ## _remove(type_name* tree, key_type key) { \
        type_name ## Node* node = function_prefix ## _get_node(tree, key); \
        if(node == NULL) \
            return default_value; \
        value_type result = node->value; \
        function_prefix ## _remove_node(tree, node); \
        return result; \
    } \
    \
    value_type function_prefix ## _remove_min(type_name* tree) { \
        if(tree->root == NULL) \
            return default_value; \
        type_name ## Node* node = function_prefix ## _min_node(tree->root); \
        value_type result = node->value; \
        function_prefix ## _remove_node(tree, node); \
        return result; \
    } \
    \
    value_type function_prefix ## _remove_max(type_name* tree) { \
        if(tree->root == NULL) \
            return default_value; \
        type_name ## Node* node = function_prefix ## _max_node(tree->root); \
        value_type result = node->value; \
        function_prefix ## _remove_node(tree, node); \
        return result; \
    } \
    \
    void function_prefix ## _free(type_name* tree) { \
        if(tree->root == NULL)  \
            return; \
        \
        type_name ## Node* current = tree->root; \
        type_name ## Node* temp; \
        while(current != NULL) { \
            if(current->left != NULL) \
                current = current->left; \
            else if(current->right != NULL) \
                current = current->right; \
            else { \
                if(current->parent != NULL) { \
                    if(current == current->parent->left) \
                        current->parent->left = NULL; \
                    else \
                        current->parent->right = NULL; \
                } \
                tree->count--; \
                temp = current->parent; \
                free(current); \
                current = temp; \
            } \
        } \
    }

#endif