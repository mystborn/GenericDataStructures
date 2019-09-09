#ifndef GENERIC_DATA_STRUCTURES_LIST_H
#define GENERIC_DATA_STRUCTURES_LIST_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define LIST_DEFINE_H(type_name, function_prefix, value_type) \
    typedef struct type_name { \
        value_type* buffer; \
        unsigned int count; \
        unsigned int capacity; \
    } type_name; \
    \
    type_name* function_prefix ## _create(void); \
    bool function_prefix ## _init(type_name* list); \
    bool function_prefix ## _init_capacity(type_name* list, unsigned int capacity); \
    bool function_prefix ## _add(type_name* list, value_type value); \
    bool function_prefix ## _insert(type_name* list, unsigned int index, value_type value); \
    \
    static inline void function_prefix ## _clear(type_name* list) { list->count = 0; } \
    \
    static inline unsigned int function_prefix ## _count(type_name* list) { return list->count; } \
    \
    static inline void function_prefix ## _free_resources(type_name* list) { free(list->buffer); } \
    \
    static inline void function_prefix ## _free(type_name* list) { free(list->buffer); free(list); } \
    \
    static inline value_type function_prefix ## _get(type_name* list, unsigned int index) {  \
        assert(index < list->count); \
        return list->buffer[index]; \
    } \
    \
    static inline void function_prefix ## _set(type_name* list, unsigned int index, value_type value) { \
        assert(index <= list->count); \
        if(index == list->count) \
            function_prefix ## _add(list, value); \
        else \
            list->buffer[index] = value; \
    } \
    \
    static inline void function_prefix ## _remove(type_name* list, unsigned int index) { \
        assert(index < list->count); \
        if(index == --list->count) \
            return; \
        else \
            memmove(list->buffer + index, list->buffer + index + 1, (list->count - index) * sizeof(value_type)); \
    } \
    \
    static inline value_type function_prefix ## _peek(type_name* list) { \
        assert(list->count); \
        return list->buffer[list->count - 1]; \
    } \
    \
    static inline value_type function_prefix ## _pop(type_name* list) {  \
        assert(list->count); \
        return list->buffer[--list->count]; \
    } \
    \
    static inline void function_prefix ## _shrink_to_fit(type_name* list) { \
        list->buffer = realloc(list->buffer, (list->count == 0 ? 1 : list->count) * sizeof(value_type)); \
        list->capacity = list->count == 0 ? 1 : list->count; \
    } \


#define LIST_DEFINE_C(type_name, function_prefix, value_type) \
    type_name* function_prefix ## _create(void) { \
        type_name* list = malloc(sizeof(type_name)); \
        if(!list) \
            return list; \
        if(!function_prefix ## _init(list)) { \
            free(list); \
            return NULL; \
        } \
        return list; \
    } \
    \
    bool function_prefix ## _init(type_name* list) { \
        list->capacity = 4; \
        list->count = 0; \
        return (list->buffer = malloc(4 * sizeof(value_type))) != NULL; \
    } \
    \
    bool function_prefix ## _init_capacity(type_name* list, unsigned int capacity) { \
        assert(capacity); \
        list->capacity = capacity; \
        list->count = 0; \
        return (list->buffer = malloc(capacity * sizeof(value_type))) != NULL; \
    } \
    \
    bool function_prefix ## _add(type_name* list, value_type value) { \
        if(list->count == list->capacity) { \
            list->capacity *= 2; \
            value_type* buffer = realloc(list->buffer, list->capacity * sizeof(value_type)); \
            if(!buffer) \
                return false; \
            list->buffer = buffer; \
        } \
        list->buffer[list->count++] = value; \
        return true; \
    } \
    \
    bool function_prefix ## _insert(type_name* list, unsigned int index, value_type value) { \
        if(index > list->count) return false; \
        if(index == list->count) \
            return function_prefix ## _add(list, value); \
        if(list->count == list->capacity) { \
            list->capacity *= 2; \
            value_type* buffer = realloc(list->buffer, list->capacity * sizeof(value_type)); \
            if(!buffer) \
                return false; \
            list->buffer = buffer; \
        } \
        memmove(list->buffer + index + 1, list->buffer + index, (list->count++ - index) * sizeof(value_type)); \
        list->buffer[index] = value; \
        return true; \
    } \



#endif