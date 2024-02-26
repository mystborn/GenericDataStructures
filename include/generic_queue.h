#ifndef GENERIC_DATA_STRUCTURES_QUEUE_H
#define GENERIC_DATA_STRUCTURES_QUEUE_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "generic_alloc.h"

// Macros to define a strongly typed queue data structure implemented using a circular buffer.

#define QUEUE_DEFINE_H(type_name, function_prefix, value_type) \
    typedef struct type_name { \
        value_type* buffer; \
        unsigned int count; \
        unsigned int capacity; \
        unsigned int start; \
        unsigned int end; \
    } type_name; \
    \
    type_name* function_prefix ## _create(void); \
    type_name* function_prefix ## _create_capacity(unsigned int capacity); \
    bool function_prefix ## _init(type_name* queue); \
    bool function_prefix ## _init_capacity(type_name* queue, unsigned int capacity); \
    void function_prefix ## _clear(type_name* queue); \
    bool function_prefix ## _enqueue(type_name* queue, value_type value); \
    value_type function_prefix ## _dequeue(type_name* queue); \
    static inline value_type function_prefix ## _peek(type_name* queue) { \
        gds_assert_bounds(queue->count); \
        return queue->buffer[queue->start]; \
    } \
    static inline unsigned int function_prefix ## _count(type_name* queue) { return queue->count; } \
    static inline void function_prefix ## _free_resources(type_name* queue) { gds_free(queue->buffer); } \
    static inline void function_prefix ## _free(type_name* queue) { gds_free(queue->buffer); gds_free(queue); }

#define QUEUE_DEFINE_C(type_name, function_prefix, value_type) \
    /* todo: inline the create functions. */ \
    type_name* function_prefix ## _create(void) { \
        type_name* queue = gds_malloc(sizeof(type_name)); \
        if(!queue) \
            return NULL; \
        if(!function_prefix ## _init(queue)) { \
            gds_free(queue); \
            return NULL; \
        } \
        return queue; \
    } \
    \
    type_name* function_prefix ## _create_capacity(unsigned int capacity) { \
        type_name* queue = gds_malloc(sizeof(type_name)); \
        if(!queue) \
            return NULL; \
        if(!function_prefix ## _init_capacity(queue, capacity)) { \
            gds_free(queue); \
            return NULL; \
        } \
        return queue; \
    } \
    \
    bool function_prefix ## _init(type_name* queue) { \
        queue->start = 0; \
        queue->end = 0; \
        queue->count = 0; \
        queue->capacity = 4; \
        return (queue->buffer = gds_malloc(queue->capacity * sizeof(value_type))) != NULL; \
    } \
    \
    bool function_prefix ## _init_capacity(type_name* queue, unsigned int capacity) { \
        queue->start = 0; \
        queue->end = 0; \
        queue->count = 0; \
        queue->capacity = capacity == 0 ? 1 : capacity; \
        return (queue->buffer = gds_malloc(queue->capacity * sizeof(value_type))) != NULL; \
    } \
    \
    void function_prefix ## _clear(type_name* queue) { \
        queue->start = 0; \
        queue->end = 0; \
        queue->count = 0; \
    } \
    \
    bool function_prefix ## _enqueue(type_name* queue, value_type value) { \
        if(queue->end == queue->capacity) \
            queue->end = 0; \
        if(queue->count == queue->capacity) { \
            unsigned int offset = queue->capacity - queue->start;  \
            queue->capacity *= 2; \
            value_type* buffer = gds_realloc(queue->buffer, queue->capacity * sizeof(value_type)); \
            if(!buffer) { \
                queue->capacity /= 2; \
                return false; \
            } \
            queue->buffer = buffer; \
            memmove(queue->buffer + queue->capacity - offset, queue->buffer + queue->start, offset * sizeof(value_type)); \
            queue->start = queue->capacity - offset; \
        } \
        queue->buffer[queue->end++] = value; \
        queue->count++; \
        return true; \
    } \
    \
    value_type function_prefix ## _dequeue(type_name* queue) { \
        assert(queue->count); \
        queue->count--; \
        if(queue->start == queue->capacity - 1) { \
            queue->start = 0; \
            return queue->buffer[queue->capacity - 1]; \
        } \
        return queue->buffer[queue->start++]; \
    } 


#endif