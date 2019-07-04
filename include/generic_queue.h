#ifndef GENERIC_DATA_STRUCTURES_QUEUE_H
#define GENERIC_DATA_STRUCTURES_QUEUE_H

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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
    void* function_prefix ## _init(type_name* queue); \
    void* function_prefix ## _init_capacity(type_name* queue, unsigned int capacity); \
    void function_prefix ## _clear(type_name* queue); \
    void function_prefix ## _enqueue(type_name* queue, value_type value); \
    value_type function_prefix ## _dequeue(type_name* queue); \
    static inline value_type function_prefix ## _peek(type_name* queue) { \
        assert(queue->count); \
        return queue->buffer[queue->start]; \
    } \
    static inline unsigned int function_prefix ## _count(type_name* queue) { return queue->count; } \
    static inline void function_prefix ## _free_resources(type_name* queue) { free(queue->buffer); } \
    static inline void function_prefix ## _free(type_name* queue) { free(queue->buffer); free(queue); }

#define QUEUE_DEFINE_C(type_name, function_prefix, value_type) \
    type_name* function_prefix ## _create(void) { \
        type_name* queue = malloc(sizeof(type_name)); \
        function_prefix ## _init(queue); \
        return queue; \
    } \
    \
    type_name* function_prefix ## _create_capacity(unsigned int capacity) { \
        type_name* queue = malloc(sizeof(type_name)); \
        function_prefix ## _init_capacity(queue, capacity); \
        return queue; \
    } \
    \
    void* function_prefix ## _init(type_name* queue) { \
        queue->start = 0; \
        queue->end = 0; \
        queue->count = 0; \
        queue->capacity = 4; \
        return queue->buffer = malloc(queue->capacity * sizeof(value_type)); \
    } \
    \
    void* function_prefix ## _init_capacity(type_name* queue, unsigned int capacity) { \
        assert(capacity); \
        queue->start = 0; \
        queue->end = 0; \
        queue->count = 0; \
        queue->capacity = capacity; \
        return queue->buffer = malloc(queue->capacity * sizeof(value_type)); \
    } \
    \
    void function_prefix ## _clear(type_name* queue) { \
        queue->start = 0; \
        queue->end = 0; \
        queue->count = 0; \
    } \
    \
    void function_prefix ## _enqueue(type_name* queue, value_type value) { \
        if(queue->end == queue->capacity) \
            queue->end = 0; \
        if(queue->count == queue->capacity) { \
            unsigned int offset = queue->capacity - queue->start;  \
            queue->capacity *= 2; \
            queue->buffer = realloc(queue->buffer, queue->capacity * sizeof(value_type)); \
            assert(queue->buffer); \
            memmove(queue->buffer + queue->capacity - offset, queue->buffer + queue->start, offset * sizeof(value_type)); \
            queue->start = queue->capacity - offset; \
        } \
        queue->buffer[queue->end++] = value; \
        queue->count++; \
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