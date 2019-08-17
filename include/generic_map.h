#ifndef GENERIC_DATA_STRUCTURES_MAP_H
#define GENERIC_DATA_STRUCTURES_MAP_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "hash_utils.h"

#define MAP_DEFINE_H(type_name, function_prefix, key_type, value_type) \
    typedef struct type_name ## Cell { \
        uint32_t hash; \
        key_type key; \
        value_type value; \
        bool active; \
    } type_name ## Cell; \
    \
    typedef struct { \
        type_name ## Cell* cells; \
        uint32_t count; \
        uint32_t capacity; \
        uint32_t load_factor; \
        uint32_t shift; \
    } type_name;\
    \
    static inline uint32_t function_prefix ## _count(type_name* map) { return map->count; } \
    static void function_prefix ## _free(type_name* map) { free(map->cells); free(map); } \
    static void function_prefix ## _free_resources(type_name* map) { free(map->cells); } \
    type_name* function_prefix ## _create(void); \
    void* function_prefix ## _init(type_name* map); \
    bool function_prefix ## _add(type_name* map, key_type key, value_type value); \
    void function_prefix ## _set(type_name* map, key_type key, value_type value); \
    value_type function_prefix ## _get(type_name* map, key_type key); \
    bool function_prefix ## _remove(type_name* map, key_type key);

#define MAP_DEFINE_C(type_name, function_prefix, key_type, value_type, hash_fn, compare_fn, default_value) \
    type_name* function_prefix ## _create(void) { \
        type_name* map = malloc(sizeof(type_name)); \
        if(!map) \
            return NULL; \
        if(!function_prefix ## _init(map)) { \
            free(map); \
            return NULL; \
        } \
        return map; \
    } \
    \
    void* function_prefix ## _init(type_name* map) { \
        map->shift = 29; \
        map->capacity = 8; \
        map->count = 0; \
        map->load_factor = 4; \
        return (map->cells = calloc(8, sizeof(type_name ## Cell))); \
    } \
 \
    static void function_prefix ## _resize(type_name* map) { \
        int capacity = map->load_factor = map->capacity; \
        map->capacity = 1 << (32 - (--map->shift)); \
        type_name ## Cell* old = map->cells; \
        type_name ## Cell* new = calloc(map->capacity, sizeof(type_name ## Cell)); \
        assert(new); \
 \
        for(int i = 0; i < capacity; i++) { \
            if(old[i].active) { \
                uint32_t cell; \
                old[i].hash = cell = ___fib_hash(hash_fn(old[i].key), map->shift); \
                while(new[cell].active) { \
                    if(++cell > map->capacity) \
                        cell = 0; \
                } \
                new[cell] = old[i]; \
            } \
        } \
        free(old); \
        map->cells = new; \
    } \
 \
    bool function_prefix ## _add(type_name* map, key_type key, value_type value) { \
        uint32_t hash, cell; \
 \
        if(map->count == map->load_factor) \
            function_prefix ## _resize(map); \
 \
        hash = cell = ___fib_hash(hash_fn(key), map->shift); \
 \
        while(true) { \
            if(!map->cells[cell].active) { \
                map->cells[cell].active = true; \
                map->cells[cell].key = key; \
                map->cells[cell].value = value; \
                map->cells[cell].hash = hash; \
                map->count++; \
                return true; \
            } else if(map->cells[cell].hash == hash && compare_fn(map->cells[cell].key, key) == 0) \
                return false; \
            if(++cell == map->capacity) \
                cell = 0; \
        } \
 \
        return false; \
    } \
 \
    void function_prefix ## _set(type_name* map, key_type key, value_type value) { \
        uint32_t hash, cell; \
 \
        if(map->count == map->load_factor) \
            function_prefix ## _resize(map); \
 \
        hash = cell = ___fib_hash(hash_fn(key), map->shift); \
 \
        while(true) { \
            if(!map->cells[cell].active) { \
                map->cells[cell].active = true; \
                map->cells[cell].key = key; \
                map->cells[cell].value = value; \
                map->cells[cell].hash = hash; \
                map->count++; \
                break; \
            } else if(map->cells[cell].hash == hash && compare_fn(map->cells[cell].key, key) == 0) { \
                map->cells[cell].value = value; \
                break; \
            } \
            if(++cell == map->capacity) \
                cell = 0; \
        } \
    } \
 \
    value_type function_prefix ## _get(type_name* map, key_type key) { \
        uint32_t cell, hash; \
        hash = cell = ___fib_hash(hash_fn(key), map->shift); \
 \
        while(true) { \
            if(!map->cells[cell].active) \
                break; \
 \
            if(map->cells[cell].hash == hash && compare_fn(map->cells[cell].key, key) == 0) \
                return map->cells[cell].value; \
 \
            if(++cell == map->capacity) \
                cell = 0; \
        } \
 \
        return default_value; \
    } \
 \
    bool function_prefix ## _remove(type_name* map, key_type key) { \
        int last = -1; \
        uint32_t start, cell, hash; \
 \
        hash = cell = ___fib_hash(hash_fn(key), map->shift); \
 \
        while(true) { \
            if(!map->cells[cell].active) \
                return false; \
 \
            if(map->cells[cell].hash == hash && compare_fn(map->cells[cell].key, key) == 0) \
                break; \
 \
            if(++cell == map->capacity) \
                cell = 0; \
        } \
 \
        start = cell; \
        while(true) { \
            if(++cell == map->capacity) \
                cell = 0; \
 \
            if(!map->cells[cell].active) \
                break; \
 \
            if(map->cells[cell].hash <= hash) \
                last = cell; \
        } \
 \
        if(last != -1) { \
            map->cells[start] = map->cells[last]; \
            map->cells[last].active = false; \
        } else \
            map->cells[start].active = false; \
        map->count--; \
        return true; \
    }


#endif //GENERIC_MAP_GENERIC_MAP_H