#ifndef GENERIC_DATA_STRUCTURES_DEQUE_H
#define GENERIC_DATA_STRUCTURES_DEQUE_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define DEQUE_DEFINE_H(type_name, function_prefix, value_type) \
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
    bool function_prefix ## _init(type_name* deque); \
    bool function_prefix ## _init_capacity(type_name* deque, unsigned int capacity); \
    void function_prefix ## _clear(type_name* deque, bool reset_capacity); \
    bool function_prefix ## _push_front(type_name* deque, value_type value); \
    bool function_prefix ## _push_back(type_name* deque, value_type value); \
    value_type function_prefix ## _pop_front(type_name* deque); \
    value_type function_prefix ## _pop_back(type_name* deque); \
 \
    static inline value_type function_prefix ## _peek_front(const type_name* deque) { \
        assert(deque->count); \
        return deque->buffer[deque->start]; \
    } \
 \
    static inline value_type function_prefix ## _peek_back(const type_name* deque) { \
        assert(deque->count); \
        return deque->buffer[deque->end == 0 ? deque->capacity - 1 : deque->end - 1]; \
    } \
 \
    static inline unsigned int function_prefix ## _count(const type_name* deque) { return deque->count; } \
    static inline unsigned int function_prefix ## _capacity(const type_name* deque) { return deque->capacity; } \
    static inline void function_prefix ## _free_resources(type_name* deque) { free(deque->buffer); } \
    static inline void function_prefix ## _free(type_name* deque) { free(deque->buffer); free(deque); } \


#define DEQUE_DEFINE_C(type_name, function_prefix, value_type) \
    type_name* function_prefix ## _create(void) { \
        type_name* deque = malloc(sizeof(type_name)); \
        if(!deque) \
            return NULL; \
        if(!function_prefix ## _init(deque)) { \
            free(deque); \
            return NULL; \
        } \
        return deque; \
    } \
 \
    type_name* function_prefix ## _create_capacity(unsigned int capacity) { \
        type_name* deque = malloc(sizeof(type_name)); \
        if(!deque) \
            return NULL; \
        if(!function_prefix ## _init_capacity(deque, capacity)) { \
            free(deque); \
            return NULL; \
        } \
        return deque; \
    } \
 \
    bool function_prefix ## _init(type_name* deque) { \
        deque->start = 0; \
        deque->end = 0; \
        deque->count = 0; \
        deque->capacity = 4; \
        return (deque->buffer = malloc(deque->capacity * sizeof(value_type))) != NULL; \
    } \
 \
    bool function_prefix ## _init_capacity(type_name* deque, unsigned int capacity) { \
        deque->start = 0; \
        deque->end = 0; \
        deque->count = 0; \
        deque->capacity = capacity == 0 ? 1 : capacity; \
        return (deque->buffer = malloc(deque->capacity * sizeof(value_type))) != NULL; \
    } \
 \
    void function_prefix ## _clear(type_name* deque, bool reset_capacity) { \
        if(reset_capacity) { \
            function_prefix ## _free_resources(deque); \
            function_prefix ## _init(deque); \
        } else { \
            deque->start = 0; \
            deque->end = 0; \
            deque->count = 0; \
        } \
    } \
 \
    static bool function_prefix ## _resize(type_name* deque) { \
        unsigned int offset = deque->capacity - deque->start; \
        deque->capacity *= 2; \
        value_type* buffer = malloc(deque->capacity * sizeof(value_type)); \
        if(!buffer) { \
            deque->capacity /= 2; \
            return false; \
        } \
        if(deque->end > deque->start) { \
            memcpy(buffer, deque->buffer + deque->start, deque->count * sizeof(value_type)); \
        } else { \
            unsigned offset = deque->count - deque->start; \
            memcpy(buffer, deque->buffer + deque->start, offset * sizeof(value_type)); \
            memcpy(buffer + offset, deque->buffer, deque->end * sizeof(value_type)); \
        } \
        deque->buffer = buffer; \
        deque->start = 0; \
        deque->end = deque->count; \
        return true; \
    } \
 \
    bool function_prefix ## _push_front(type_name* deque, value_type value) { \
        if(deque->count == deque->capacity) { \
            if(!function_prefix ## _resize(deque)) \
                return false; \
        } \
        deque->start = deque->start == 0 ? deque->capacity - 1 : deque->start -1; \
        deque->buffer[deque->start] = value; \
        deque->count++; \
        return true; \
    } \
 \
    bool function_prefix ## _push_back(type_name* deque, value_type value) { \
        if(deque->count == deque->capacity) { \
            if(!function_prefix ## _resize(deque)) \
                return false; \
        } \
        deque->buffer[deque->end] = value; \
        deque->end = deque->end == deque->capacity - 1 ? 0 : deque->end + 1; \
        deque->count++; \
        return true; \
    } \
 \
    value_type function_prefix ## _pop_front(type_name* deque) { \
        assert(deque->count); \
        deque->count--; \
        value_type value = deque->buffer[deque->start]; \
        deque->start = deque->start == deque->capacity - 1 ? 0 : deque->start + 1; \
        return value; \
    } \
 \
    value_type function_prefix ## _pop_back(type_name* deque) { \
        assert(deque->count); \
        deque->count--; \
        deque->end = deque->end == 0 ? deque->capacity - 1 : deque->end - 1; \
        return deque->buffer[deque->end]; \
    } \




#endif