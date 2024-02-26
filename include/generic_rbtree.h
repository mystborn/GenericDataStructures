#ifndef GENERIC_DATA_STRUCTURES_RED_BLACK_TREE_H
#define GENERIC_DATA_STRUCTURES_RED_BLACK_TREE_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "generic_alloc.h"

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
    static inline type_name* function_prefix ## _create(void); \
    static inline void function_prefix ## _init(type_name* tree); \
    static inline void function_prefix ## _free(type_name* tree, bool free_nodes); \
                  GDS_EXPORT void function_prefix ## _free_resources(type_name* tree); \
    static inline type_name ## Node* function_prefix ## _root(type_name* tree); \
    static inline unsigned int function_prefix ## _count(type_name* tree); \
    static inline type_name ## Node* function_prefix ## _add(type_name* tree, key_type key, value_type value); \
    static inline bool function_prefix ## _get(type_name* tree, key_type key, value_type* out_value); \
    static inline bool function_prefix ## _get_min(type_name* tree, value_type* out_value); \
    static inline bool function_prefix ## _get_max(type_name* tree, value_type* out_value); \
    static inline bool function_prefix ## _remove(type_name* tree, key_type key, value_type* out_value); \
    static inline bool function_prefix ## _remove_min(type_name* tree, value_type* out_value); \
    static inline bool function_prefix ## _remove_max(type_name* tree, value_type* out_value); \
                  GDS_EXPORT void function_prefix ## _add_node(type_name* tree, type_name ## Node* node); \
                  GDS_EXPORT type_name ## Node* function_prefix ## _get_node(type_name* tree, key_type key); \
    static inline type_name ## Node* function_prefix ## _get_min_node(type_name* tree); \
    static inline type_name ## Node* function_prefix ## _get_max_node(type_name* tree); \
                  GDS_EXPORT type_name ## Node* function_prefix ## _remove_node(type_name* tree, type_name ## Node* node); \
    static inline type_name ## Node* function_prefix ## _remove_min_node(type_name* tree); \
    static inline type_name ## Node* function_prefix ## _remove_max_node(type_name* tree); \
    \
    static inline type_name* function_prefix ## _create(void) { \
        type_name* tree = gds_malloc(sizeof(type_name)); \
        if(!tree) \
            return NULL; \
        tree->root = NULL; \
        tree->count = 0; \
        return tree; \
    } \
    \
    static inline void function_prefix ## _init(type_name* tree) { \
        tree->root = NULL; \
        tree->count = 0; \
    } \
    \
    static inline void function_prefix ## _free(type_name* tree, bool free_nodes) { \
        if(free_nodes) \
            function_prefix ## _free_resources(tree); \
        gds_free(tree); \
    } \
    \
    static inline type_name ## Node* function_prefix ## _root(type_name* tree) { \
        return tree->root; \
    } \
    \
    static inline unsigned int function_prefix ## _count(type_name* tree) { \
        return tree->count; \
    } \
    \
    static inline type_name ## Node* function_prefix ## _add(type_name* tree, key_type key, value_type value) { \
        type_name ## Node* node = gds_malloc(sizeof(type_name ## Node)); \
        if(!node) \
            return NULL; \
        node->key = key; \
        node->value = value; \
        function_prefix ## _add_node(tree, node); \
        return node; \
    } \
    \
    static inline bool function_prefix ## _get(type_name* tree, key_type key, value_type* out_value) { \
        type_name ## Node* node = function_prefix ## _get_node(tree, key); \
        if(!node) \
            return false; \
 \
        if(out_value != NULL) *out_value = node->value; \
 \
        return true; \
    } \
    \
    static inline bool function_prefix ## _get_min(type_name* tree, value_type* out_value) { \
        type_name ## Node* node = function_prefix ## _get_min_node(tree); \
        if(!node) \
            return false; \
 \
        if(out_value != NULL) *out_value = node->value; \
 \
        return true; \
    } \
    \
    static inline bool function_prefix ## _get_max(type_name* tree, value_type* out_value) { \
        type_name ## Node* node = function_prefix ## _get_max_node(tree); \
        if(!node) \
            return false; \
 \
        if(out_value != NULL) *out_value = node->value; \
 \
        return true; \
    } \
    \
    static inline bool function_prefix ## _remove(type_name* tree, key_type key, value_type* out_value) { \
        type_name ## Node* node = function_prefix ## _get_node(tree, key); \
        if(node == NULL) \
            return false; \
 \
        if(out_value != NULL) *out_value = node->value; \
        gds_free(function_prefix ## _remove_node(tree, node)); \
        return true; \
    } \
    \
    static inline bool function_prefix ## _remove_min(type_name* tree, value_type* out_value) { \
        type_name ## Node* node = function_prefix ## _get_min_node(tree); \
        if(!node) \
            return false; \
 \
        if(out_value != NULL) *out_value = node->value; \
        gds_free(function_prefix ## _remove_node(tree, node)); \
        return true; \
    } \
    \
    static inline bool function_prefix ## _remove_max(type_name* tree, value_type* out_value) { \
        type_name ## Node* node = function_prefix ## _get_max_node(tree); \
        if(!node) \
            return false; \
 \
        if(out_value != NULL) *out_value = node->value; \
        gds_free(function_prefix ## _remove_node(tree, node)); \
        return true; \
    } \
    \
    static inline type_name ## Node* function_prefix ## _get_min_node(type_name* tree) { \
        if(tree->root == NULL) \
            return NULL; \
        type_name ## Node* node = tree->root; \
        while(node->left) \
            node = node->left; \
        return node; \
    } \
    \
    static inline type_name ## Node* function_prefix ## _get_max_node(type_name* tree) { \
        if(tree->root == NULL) \
            return NULL; \
        type_name ## Node* node = tree->root; \
        while(node->right) \
            node = node->right; \
        return node; \
    } \
    \
    static inline type_name ## Node* function_prefix ## _remove_min_node(type_name* tree) { \
        type_name ## Node* node = function_prefix ## _get_min_node(tree); \
        if(!node) \
            return NULL; \
 \
        return function_prefix ## _remove_node(tree, node); \
    } \
    \
    static inline type_name ## Node* function_prefix ## _remove_max_node(type_name* tree) { \
        type_name ## Node* node = function_prefix ## _get_max_node(tree); \
        if(!node) \
            return NULL; \
 \
        return function_prefix ## _remove_node(tree, node); \
    } \


#define RBTREE_DEFINE_C(type_name, function_prefix, key_type, value_type, compare_fn) \
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
    GDS_EXPORT type_name ## Node* function_prefix ## _get_node(type_name* tree, key_type key) { \
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
    static inline void function_prefix ## _insert_case1(type_name ## Node* node) { \
        if(function_prefix ## _parent(node) == NULL) \
            node->color = RB_BLACK; \
    } \
    \
    static inline void function_prefix ## _insert_case2(type_name ## Node* node) { \
        return; \
    } \
    \
    static inline void function_prefix ## _insert_case3(type_name* tree, type_name ## Node* node) { \
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
    GDS_EXPORT void function_prefix ## _add_node(type_name* tree, type_name ## Node* node) { \
        node->color = RB_RED; \
        node->parent = NULL; \
        node->left = NULL; \
        node->right = NULL; \
        if(tree->root == NULL) { \
            tree->root = node; \
        } else { \
            type_name ## Node* parent = NULL; \
            type_name ## Node* current = tree->root; \
            while(current != NULL) { \
                parent = current; \
                \
                if(compare_fn(node->key, current->key) < 0) \
                    current = current->left; \
                else \
                    current = current->right; \
            } \
            \
            node->parent = parent; \
            \
            if(compare_fn(node->key, parent->key) < 0) \
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
    GDS_EXPORT type_name ## Node* function_prefix ## _remove_node(type_name* tree, type_name ## Node* node) { \
        key_type temp_key = node->key; \
        value_type temp_value = node->value; \
        if(node->left != NULL && node->right != NULL) { \
            type_name ## Node* pred = node->left; \
            while(pred->right) \
                pred = pred->right; \
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
        tree->count--; \
        node->key = temp_key; \
        node->value = temp_value; \
        return node; \
    } \
    \
    GDS_EXPORT void function_prefix ## _free_resources(type_name* tree) { \
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
                gds_free(current); \
                current = temp; \
            } \
        } \
    }

#endif