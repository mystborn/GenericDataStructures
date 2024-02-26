#ifndef GENERIC_DATA_STRUCTURES_GENERIC_POOL_H
#define GENERIC_DATA_STRUCTURES_GENERIC_POOL_H

/* 
 *  Defines a special type of allocator that creates objects 
 *  with the intent of reusing them in the future.
 */

#include <stdbool.h>
#include <stdlib.h>

#include "generic_alloc.h"


#define POOL_DEFINE_H(type_name, function_prefix, value_type) \
    struct type_name ## Node { \
        value_type* buffer; \
        struct type_name ## Node* next; \
    }; \
 \
    typedef struct type_name { \
        struct type_name ## Node* node; \
        value_type** open; \
        unsigned int open_count; \
        unsigned int open_capacity; \
        unsigned int next; \
        unsigned int node_capacity; \
        unsigned int total; \
    } type_name; \
 \
    type_name* function_prefix ## _create(void); \
    bool function_prefix ## _init(type_name* pool); \
    void function_prefix ## _free(type_name* pool); \
    void function_prefix ## _free_resources(type_name* pool); \
 \
    value_type* function_prefix ## _get(type_name* pool); \
    bool function_prefix ## _release(type_name* pool, value_type* value); \

#ifndef POOL_SKIP_RELEASE_ASSERT

// This verifies that a released pointer is actually owned by the pool,
// but is not actually a necessary step in the release process,
// so it can optionally be optionally be defined away.

#define ___POOL_RELEASE_ASSERT(node_type) \
    long long buffer_size = pool->total; \
    node_type node = pool->node; \
 \
    while(node != NULL) { \
        ptrdiff_t offset = value - node->buffer; \
        if(offset >= 0 && offset < buffer_size) \
            break; \
 \
        node = node->next; \
        buffer_size >>= 1; \
    } \
 \
    if(!node) \
        return false;

#else

#define ___POOL_RELEASE_ASSERT(node_type)

#endif

#define POOL_DEFINE_C(type_name, function_prefix, value_type, init_fn, free_resources_fn) \
    type_name* function_prefix ## _create(void) { \
        type_name* pool = gds_malloc(sizeof(*pool)); \
        if(!pool) \
            return NULL; \
 \
        if(!function_prefix ## _init(pool)) { \
            gds_free(pool); \
            return NULL; \
        } \
 \
        return pool; \
    } \
 \
    bool function_prefix ## _init(type_name* pool) { \
        struct type_name ## Node* node = gds_malloc(sizeof(*node)); \
        if(!node) \
            return false; \
        node->buffer = gds_malloc(16 * sizeof(*node->buffer)); \
        if(!node->buffer) { \
            gds_free(node); \
            return false; \
        } \
        node->next = NULL; \
        pool->node = node; \
        pool->open = NULL; \
        pool->open_count = 0; \
        pool->open_capacity = 0; \
        pool->next = 0; \
        pool->node_capacity = 16; \
        pool->total = 16; \
        return true; \
    } \
 \
    void function_prefix ## _free(type_name* pool) { \
        function_prefix ## _free_resources(pool); \
        gds_free(pool); \
    } \
 \
    void function_prefix ## _free_resources(type_name* pool) { \
        struct type_name ## Node* node = pool->node; \
 \
        while(node != NULL) { \
            struct type_name ## Node* next = node->next; \
            gds_free(node->buffer); \
            gds_free(node); \
            node = next; \
        } \
 \
        gds_free(pool->open); \
    } \
 \
    value_type* function_prefix ## _get(type_name* pool) { \
        value_type* result; \
        if(pool->open_count == 0) { \
            if(pool->next == pool->node_capacity) { \
                struct type_name ## Node* node = gds_malloc(sizeof(*node)); \
                if(!node) \
                    return NULL; \
 \
                node->buffer = gds_malloc(pool->total * sizeof(*node->buffer)); \
                if(!node->buffer) { \
                    gds_free(node); \
                    return NULL; \
                } \
 \
                node->next = pool->node; \
 \
                pool->node_capacity = pool->total; \
                pool->total *= 2; \
                pool->node = node; \
                pool->next = 0; \
            } \
 \
            result = &pool->node->buffer[pool->next++]; \
        } else { \
            result = pool->open[--pool->open_count]; \
        } \
 \
        init_fn(result); \
        return result; \
    } \
 \
    bool function_prefix ## _release(type_name* pool, value_type* value) { \
        ___POOL_RELEASE_ASSERT(struct type_name ## Node*) \
 \
        if(pool->open_count == pool->open_capacity) { \
            unsigned int capacity = pool->open_capacity; \
            capacity = capacity == 0 ? 4 : capacity * 2; \
            void* buffer = gds_realloc(pool->open, capacity * sizeof(*pool->open)); \
            if(!buffer) \
                return false; \
 \
            pool->open_capacity = capacity; \
            pool->open = buffer; \
        } \
 \
        pool->open[pool->open_count++] = value; \
 \
        free_resources_fn(value); \
        return true; \
    } \


// This is a simpler implementation that allocates new objects
// on the fly rather than batching them.
// Needs testing to see if/when it's faster before switching implmentations.


// #define POOL_DEFINE_H(type_name, function_prefix, value_type) \
//     typedef struct type_name { \
//         value_type** buffer; \
//         unsigned int pool_count; \
//         unsigned int pool_capacity; \
//     } type_name; \
// 
// 
// #define POOL_DEFINE_C(type_name, function_prefix, value_type, init_fn, free_resources_fn) \
//     value_type* function_prefix ## _get(type_name* pool) { \
//         value_type* result; \
//         if(pool->pool_count == 0) \
//             result = malloc(sizeof(*result)); \
//         else \
//             result = buffer[--pool->pool_count]; \
//  \
//         init_fn(result); \
//         return result; \
//     } \
//  \
//     bool function_prefix ## _release(type_name* pool, value_type* value) { \
//         if(pool->pool_count == pool->pool_capacity) { \
//             unsigned int capacity = pool->capacity == 0 ? 4 : pool->capacity * 2; \
//             void* buffer = realloc(pool->buffer, capacity); \
//             if(!buffer) \
//                 return false; \
//  \
//             pool->buffer = buffer; \
//             pool->capacity = capacity; \
//         } \
//  \
//         pool->buffer[pool->pool_count++] = value; \
//         return true; \
//     } \


#endif