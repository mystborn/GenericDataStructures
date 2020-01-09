#ifndef GENERIC_DATA_STRUCTURES_GENERIC_TRIE_H
#define GENERIC_DATA_STRUCTURES_GENERIC_TRIE_H

#include "generic_map.h"
#include "generic_iterators/map_iterator.h"
#include <stdlib.h>
#include <string.h>

#define ___TRIE_ARRAY_SIZE 20
#define ___TRIE_NODE_IS_LEAF 0x80000000
#define ___TRIE_NODE_NOT_FREE 0x40000000
#define ___TRIE_NODE_DEPTH_MASK 0x3FFFFFFF
#define ___TRIE_DEPTH(depth) (depth & ___TRIE_NODE_DEPTH_MASK)

#define TRIE_SET_DEFINE_H(type_name, function_prefix, value_type) \
    typedef struct type_name ## Node type_name ## Node; \
 \
    MAP_DEFINE_H(___ ## type_name ## Map, ___ ## function_prefix ## _map, value_type, type_name ## Node*) \
 \
    struct type_name ## Node { \
        ___ ## type_name ## Map* map; \
        type_name ## Node* array; \
        value_type value; \
        unsigned int count; \
        unsigned int depth; \
    }; \
 \
    struct type_name ## IterState { \
        type_name ## Node* node; \
        unsigned int index; \
    }; \
 \
    typedef struct type_name { \
        type_name ## Node* root; \
        unsigned int count; \
        unsigned int max_depth; \
    } type_name; \
 \
    type_name* function_prefix ## _create(void); \
    bool function_prefix ## _init(type_name* trie); \
    void function_prefix ## _free(type_name* trie); \
    void function_prefix ## _free_resources(type_name* trie); \
    bool function_prefix ## _add(type_name* trie, value_type* value); \
    bool function_prefix ## _contains(type_name* trie, value_type* value); \
    bool function_prefix ## _remove(type_name* trie, value_type* value); \
 \
    static inline unsigned int function_prefix ## _count(type_name* trie) { return trie->count; } \
 \
    static inline bool function_prefix ## _clear(type_name* trie) { \
        function_prefix ## _free_resources(trie); \
        return function_prefix ## _init(trie); \
    } \


#define TRIE_SET_DEFINE_C(type_name, function_prefix, value_type) \
    static inline uint32_t ___ ## function_prefix ## _hash(value_type value) { \
        return (uint32_t)value; \
    } \
 \
    static inline int ___ ## function_prefix ## _cmp(value_type left, value_type right) { \
        return left < right ? -1 : (left > right ? 1 : 0); \
    } \
 \
    MAP_DEFINE_C(___ ## type_name ## Map,  \
                 ___ ## function_prefix ## _map,  \
                 value_type,  \
                 type_name ## Node*,  \
                 ___ ## function_prefix ## _hash,  \
                 ___ ## function_prefix ## _cmp) \
 \
    static inline void function_prefix ## _node_activate(type_name ## Node* node) { \
        node->depth |= ___TRIE_NODE_IS_LEAF; \
    } \
 \
    static inline bool function_prefix ## _node_is_active(type_name ## Node* node) { \
        return (node->depth & ___TRIE_NODE_IS_LEAF) == ___TRIE_NODE_IS_LEAF; \
    } \
 \
    static inline void function_prefix ## _node_init(type_name ## Node* node, unsigned int depth) { \
        node->map = NULL; \
        node->array = NULL; \
        node->count = 0; \
        node->depth = depth; \
    } \
 \
    static type_name ## Node* function_prefix ## _add_child(type_name ## Node* node, value_type value) { \
        if(node->count == 0 && node->array == NULL) { \
            node->array = malloc(sizeof(type_name ## Node) * ___TRIE_ARRAY_SIZE); \
            for(int i = 0; i < ___TRIE_ARRAY_SIZE; i++) \
                function_prefix ## _node_init(&node->array[i], ___TRIE_DEPTH(node->depth + 1) | ___TRIE_NODE_NOT_FREE); \
        } else if(node->count == ___TRIE_ARRAY_SIZE) { \
            if(!node->map) { \
                node->map = ___ ## function_prefix ## _map_create(); \
                if(!node->map) \
                    return NULL; \
            } \
 \
            for(int i = 0; i < ___TRIE_ARRAY_SIZE; i++) \
                ___ ## function_prefix ## _map_add(node->map, node->array[i].value, &node->array[i]); \
        } \
 \
        type_name ## Node* result; \
 \
        if(node->count < ___TRIE_ARRAY_SIZE) { \
            result = node->array + node->count; \
        } else { \
            result = malloc(sizeof(*result)); \
            function_prefix ## _node_init(result, ___TRIE_DEPTH(node->depth + 1)); \
            ___ ## function_prefix ## _map_add(node->map, value, result); \
        } \
 \
        result->value = value; \
        node->count++; \
 \
        return result; \
    } \
 \
    static type_name ## Node* function_prefix ## _get_node(type_name ## Node* node, value_type value) { \
        if(node->count <= ___TRIE_ARRAY_SIZE) { \
            for(int i = 0; i < node->count; i++) { \
                if(node->array[i].value == value) \
                    return &node->array[i]; \
            } \
        } else { \
            type_name ## Node* result; \
            if(___ ## function_prefix ## _map_try_get(node->map, value, &result)) \
                return result; \
        } \
 \
        return NULL; \
    } \
 \
    static inline type_name ## Node* function_prefix ## _get_or_create(type_name ## Node* node, value_type value) { \
        type_name ## Node* result = function_prefix ## _get_node(node, value); \
        if(result == NULL) \
            result = function_prefix ## _add_child(node, value); \
 \
        return result; \
    } \
 \
    static void function_prefix ## _free_node(type_name ## Node* node) { \
        if(node->count == 0)  \
            goto cleanup; \
 \
        if(node->count > ___TRIE_ARRAY_SIZE) { \
            type_name ## Node* value; \
 \
            map_iter_value_start(node->map, value) \
                function_prefix ## _free_node(value); \
            map_iter_end \
            ___ ## function_prefix ## _map_free(node->map); \
        } else {\
            for(int i = 0; i < node->count; i++) { \
                function_prefix ## _free_node(&node->array[i]); \
            } \
        } \
 \
        cleanup: \
 \
        free(node->array); \
        node->array = NULL; \
 \
        if((node->depth & ___TRIE_NODE_NOT_FREE) == 0) {\
            free(node); \
        } \
    } \
 \
    type_name* function_prefix ## _create(void) { \
        type_name* trie = malloc(sizeof(*trie)); \
        if(!trie) \
            return NULL; \
 \
        if(!function_prefix ## _init(trie)) { \
            free(trie); \
            return NULL; \
        } \
 \
        return trie; \
    } \
 \
    bool function_prefix ## _init(type_name* trie) { \
        trie->root = malloc(sizeof(*trie->root)); \
        if(!trie->root) \
            return false; \
        function_prefix ## _node_init(trie->root, 0); \
        trie->count = 0; \
        trie->max_depth = 0; \
        return true; \
    } \
 \
    void function_prefix ## _free(type_name* trie) { \
        function_prefix ## _free_resources(trie); \
        free(trie); \
    } \
 \
    void function_prefix ## _free_resources(type_name* trie) { \
        function_prefix ## _free_node(trie->root); \
    } \
 \
    bool function_prefix ## _add(type_name* trie, value_type* value) { \
        type_name ## Node* node = trie->root; \
 \
        while(*value != 0) { \
            node = function_prefix ## _get_or_create(node, *value); \
            if(!node) \
                return false; \
            value++; \
        } \
 \
        if(function_prefix ## _node_is_active(node)) \
            return false; \
 \
        function_prefix ## _node_activate(node); \
        trie->count++; \
        if(trie->max_depth < ___TRIE_DEPTH(node->depth)) \
            trie->max_depth = ___TRIE_DEPTH(node->depth); \
        return true; \
    } \
 \
    bool function_prefix ## _contains(type_name* trie, value_type* value) { \
        type_name ## Node* node = trie->root; \
 \
        while(*value != 0) { \
            node = function_prefix ## _get_node(node, *value); \
            if(!node) \
                return false; \
            value++; \
        } \
 \
        return function_prefix ## _node_is_active(node); \
    } \
 \
    bool function_prefix ## _remove(type_name* trie, value_type* value) { \
        if(*value == 0) \
            return false; \
 \
        type_name ## Node *parent, *child; \
        parent = child = trie->root; \
 \
        while(*value != 0) { \
            parent = child; \
            type_name ## Node* node = function_prefix ## _get_node(child, *value); \
            if(!node) \
                return false; \
 \
            child = node; \
            value++; \
        } \
 \
        if(!function_prefix ## _node_is_active(child)) \
            return false; \
 \
        child->depth &= ~___TRIE_NODE_IS_LEAF; \
 \
        trie->count--; \
 \
        return true; \
    } \


#define TRIE_MAP_DEFINE_H(type_name, function_prefix, key_type, value_type) \
    typedef struct type_name ## Node type_name ## Node; \
 \
    MAP_DEFINE_H(___ ## type_name ## Map, ___ ## function_prefix ## _map, key_type, type_name ## Node*) \
 \
    struct type_name ## Node { \
        ___ ## type_name ## Map* map; \
        type_name ## Node* array; \
        value_type value; \
        key_type key; \
        unsigned int count; \
        unsigned int depth; \
    }; \
 \
    struct type_name ## IterState { \
        type_name ## Node* node; \
        unsigned int index; \
    }; \
 \
    typedef struct type_name { \
        type_name ## Node* root; \
        unsigned int count; \
        unsigned int max_depth; \
    } type_name; \
 \
    type_name* function_prefix ## _create(void); \
    bool function_prefix ## _init(type_name* trie); \
    void function_prefix ## _free(type_name* trie); \
    void function_prefix ## _free_resources(type_name* trie); \
    bool function_prefix ## _add(type_name* trie, key_type* key, value_type value); \
    bool function_prefix ## _set(type_name* trie, key_type* key, value_type value); \
    value_type function_prefix ## _get(type_name* trie, key_type* key); \
    bool function_prefix ## _try_get(type_name* trie, key_type* key, value_type* out_value); \
    bool function_prefix ## _remove(type_name* trie, key_type* key); \
    bool function_prefix ## _get_and_remove(type_name* trie, key_type* key, value_type* out_value); \
 \
    static inline unsigned int function_prefix ## _count(type_name* trie) { return trie->count; } \
 \
    static inline bool function_prefix ## _clear(type_name* trie) { \
        function_prefix ## _free_resources(trie); \
        return function_prefix ## _init(trie); \
    } \
 \
    static inline value_type function_prefix ## _get(type_name* trie, key_type* key) { \
        value_type result; \
        if(!function_prefix ## _try_get(trie, key, &result)) \
            return (value_type){0}; \
 \
        return result; \
    } \


#define TRIE_MAP_DEFINE_C(type_name, function_prefix, key_type, value_type) \
    static inline uint32_t ___ ## function_prefix ## _hash(key_type key) { \
        return (uint32_t)key; \
    } \
 \
    static inline int ___ ## function_prefix ## _cmp(key_type left, key_type right) { \
        return left < right ? -1 : (left > right ? 1 : 0); \
    } \
 \
    MAP_DEFINE_C(___ ## type_name ## Map,  \
                 ___ ## function_prefix ## _map,  \
                 key_type,  \
                 type_name ## Node*,  \
                 ___ ## function_prefix ## _hash,  \
                 ___ ## function_prefix ## _cmp) \
 \
    static inline void function_prefix ## _node_activate(type_name ## Node* node) { \
        node->depth |= ___TRIE_NODE_IS_LEAF; \
    } \
 \
    static inline bool function_prefix ## _node_is_active(type_name ## Node* node) { \
        return (node->depth & ___TRIE_NODE_IS_LEAF) == ___TRIE_NODE_IS_LEAF; \
    } \
 \
    static inline void function_prefix ## _node_init(type_name ## Node* node, unsigned int depth) { \
        node->map = NULL; \
        node->array = NULL; \
        node->count = 0; \
        node->depth = depth; \
    } \
 \
    static type_name ## Node* function_prefix ## _add_child(type_name ## Node* node, key_type key) { \
        if(node->count == 0 && node->array == NULL) { \
            node->array = malloc(sizeof(type_name ## Node) * ___TRIE_ARRAY_SIZE); \
            for(int i = 0; i < ___TRIE_ARRAY_SIZE; i++) \
                function_prefix ## _node_init(&node->array[i], ___TRIE_DEPTH(node->depth + 1) | ___TRIE_NODE_NOT_FREE); \
        } else if(node->count == ___TRIE_ARRAY_SIZE) { \
            if(!node->map) { \
                node->map = ___ ## function_prefix ## _map_create(); \
                if(!node->map) \
                    return NULL; \
            } \
 \
            for(int i = 0; i < ___TRIE_ARRAY_SIZE; i++) \
                ___ ## function_prefix ## _map_add(node->map, node->array[i].key, &node->array[i]); \
        } \
 \
        type_name ## Node* result; \
 \
        if(node->count < ___TRIE_ARRAY_SIZE) { \
            result = node->array + node->count; \
        } else { \
            result = malloc(sizeof(*result)); \
            function_prefix ## _node_init(result, ___TRIE_DEPTH(node->depth + 1)); \
            ___ ## function_prefix ## _map_add(node->map, key, result); \
        } \
 \
        result->key = key; \
        node->count++; \
 \
        return result; \
    } \
 \
    static type_name ## Node* function_prefix ## _get_node(type_name ## Node* node, key_type key) { \
        if(node->count <= ___TRIE_ARRAY_SIZE) { \
            for(int i = 0; i < node->count; i++) { \
                if(node->array[i].key == key) \
                    return &node->array[i]; \
            } \
        } else { \
            type_name ## Node* result; \
            if(___ ## function_prefix ## _map_try_get(node->map, key, &result)) \
                return result; \
        } \
 \
        return NULL; \
    } \
 \
    static inline type_name ## Node* function_prefix ## _get_or_create(type_name ## Node* node, key_type key) { \
        type_name ## Node* result = function_prefix ## _get_node(node, key); \
        if(result == NULL) \
            result = function_prefix ## _add_child(node, key); \
 \
        return result; \
    } \
 \
    static void function_prefix ## _free_node(type_name ## Node* node) { \
        if(node->count == 0)  \
            goto cleanup; \
 \
        if(node->count > ___TRIE_ARRAY_SIZE) { \
            type_name ## Node* value; \
 \
            map_iter_value_start(node->map, value) \
                function_prefix ## _free_node(value); \
            map_iter_end \
            ___ ## function_prefix ## _map_free(node->map); \
        } else {\
            for(int i = 0; i < node->count; i++) { \
                function_prefix ## _free_node(&node->array[i]); \
            } \
        } \
 \
        cleanup: \
 \
        free(node->array); \
        node->array = NULL; \
 \
        if((node->depth & ___TRIE_NODE_NOT_FREE) == 0) {\
            free(node); \
        } \
    } \
 \
    type_name* function_prefix ## _create(void) { \
        type_name* trie = malloc(sizeof(*trie)); \
        if(!trie) \
            return NULL; \
 \
        if(!function_prefix ## _init(trie)) { \
            free(trie); \
            return NULL; \
        } \
 \
        return trie; \
    } \
 \
    bool function_prefix ## _init(type_name* trie) { \
        trie->root = malloc(sizeof(*trie->root)); \
        if(!trie->root) \
            return false; \
        function_prefix ## _node_init(trie->root, 0); \
        trie->count = 0; \
        trie->max_depth = 0; \
        return true; \
    } \
 \
    void function_prefix ## _free(type_name* trie) { \
        function_prefix ## _free_resources(trie); \
        free(trie); \
    } \
 \
    void function_prefix ## _free_resources(type_name* trie) { \
        function_prefix ## _free_node(trie->root); \
    } \
 \
    bool function_prefix ## _add(type_name* trie, key_type* key, value_type value) { \
        type_name ## Node* node = trie->root; \
 \
        while(*key != 0) { \
            node = function_prefix ## _get_or_create(node, *key); \
            if(!node) \
                return false; \
            key++; \
        } \
 \
        if(function_prefix ## _node_is_active(node)) \
            return false; \
 \
        function_prefix ## _node_activate(node); \
        node->value = value; \
        trie->count++; \
        if(trie->max_depth < ___TRIE_DEPTH(node->depth)) \
            trie->max_depth = ___TRIE_DEPTH(node->depth); \
        return true; \
    } \
 \
    bool function_prefix ## _set(type_name* trie, key_type* key, value_type value) { \
        type_name ## Node* node = trie->root; \
 \
        while(*key != 0) { \
            node = function_prefix ## _get_or_create(node, *key); \
            if(!node) \
                return false; \
            key++; \
        } \
 \
        if(!function_prefix ## _node_is_active(node)) { \
            function_prefix ## _node_activate(node); \
            trie->count++; \
        } \
 \
        node->value = value; \
        if(trie->max_depth < ___TRIE_DEPTH(node->depth)) \
            trie->max_depth = ___TRIE_DEPTH(node->depth); \
        return true; \
    } \
 \
    bool function_prefix ## _try_get(type_name* trie, key_type* key, value_type* out_value) { \
        type_name ## Node* node = trie->root; \
 \
        while(*key != 0) { \
            node = function_prefix ## _get_node(node, *key); \
            if(!node) \
                return false; \
            key++; \
        } \
 \
        if(!function_prefix ## _node_is_active(node)) \
            return false; \
 \
        if(out_value != NULL) \
            *out_value = node->value; \
 \
        return true; \
    } \
 \
    bool function_prefix ## _remove(type_name* trie, key_type* key) { \
        if(*key == 0) \
            return false; \
 \
        type_name ## Node *parent, *child; \
        parent = child = trie->root; \
 \
        while(*key != 0) { \
            parent = child; \
            type_name ## Node* node = function_prefix ## _get_node(child, *key); \
            if(!node) \
                return false; \
 \
            child = node; \
            key++; \
        } \
 \
        if(!function_prefix ## _node_is_active(child)) \
            return false; \
 \
        child->depth &= ~___TRIE_NODE_IS_LEAF; \
 \
        trie->count--; \
 \
        return true; \
    } \
 \
    bool function_prefix ## _get_and_remove(type_name* trie, key_type* key, value_type* out_value) { \
        if(*key == 0) \
            return false; \
 \
        type_name ## Node *parent, *child; \
        parent = child = trie->root; \
 \
        while(*key != 0) { \
            parent = child; \
            type_name ## Node* node = function_prefix ## _get_node(child, *key); \
            if(!node) \
                return false; \
 \
            child = node; \
            key++; \
        } \
 \
        if(!function_prefix ## _node_is_active(child)) \
            return false; \
 \
        child->depth &= ~___TRIE_NODE_IS_LEAF; \
 \
        if(out_value != NULL) \
            *out_value = child->value; \
 \
        trie->count--; \
 \
        return true; \
    } \


#endif