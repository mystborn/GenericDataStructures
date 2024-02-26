#ifndef GENERIC_DATA_STRUCTURES_MAP_H
#define GENERIC_DATA_STRUCTURES_MAP_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "generic_hash_utils.h"
#include "generic_alloc.h"

#define MAP_DEFINE_H(type_name, function_prefix, key_type, value_type) \
    typedef struct type_name ## Cell { \
        key_type key; \
        value_type value; \
        uint32_t hash; \
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
    static inline uint32_t function_prefix ## _capacity(type_name* map) { return map->load_factor; } \
    static inline uint32_t function_prefix ## _allocated(type_name* map) { return map->capacity; } \
    static inline void function_prefix ## _free(type_name* map) { gds_free(map->cells); gds_free(map); } \
    static inline void function_prefix ## _free_resources(type_name* map) { gds_free(map->cells); } \
 \
    type_name* function_prefix ## _create(void); \
    bool function_prefix ## _init(type_name* map); \
    bool function_prefix ## _add(type_name* map, key_type key, value_type value); \
    void function_prefix ## _set(type_name* map, key_type key, value_type value); \
    value_type function_prefix ## _get(type_name* map, key_type key); \
    bool function_prefix ## _try_get(type_name* map, key_type key, value_type* out_value); \
    bool function_prefix ## _remove(type_name* map, key_type key); \
    bool function_prefix ## _get_and_remove(type_name* map, key_type key, key_type* out_key, value_type* out_value); \
    void function_prefix ## _clear(type_name* map, bool reset_capacity); \


// TODO: Add more safety in case the map fails to resize.

#define MAP_DEFINE_C(type_name, function_prefix, key_type, value_type, hash_fn, compare_fn) \
    type_name* function_prefix ## _create(void) { \
        type_name* map = gds_malloc(sizeof(type_name)); \
        if(!map) \
            return NULL; \
        if(!function_prefix ## _init(map)) { \
            gds_free(map); \
            return NULL; \
        } \
        return map; \
    } \
 \
    bool function_prefix ## _init(type_name* map) { \
        map->shift = 29; \
        map->capacity = 8; \
        map->count = 0; \
        map->load_factor = 4; \
        return (map->cells = gds_calloc(8, sizeof(type_name ## Cell))) != NULL; \
    } \
 \
    static void function_prefix ## _resize(type_name* map) { \
        int capacity = map->load_factor = map->capacity; \
        map->capacity = 1 << (32 - (--map->shift)); \
        type_name ## Cell* old = map->cells; \
        type_name ## Cell* new = gds_calloc(map->capacity, sizeof(type_name ## Cell)); \
        assert(new); \
 \
        for(int i = 0; i < capacity; i++) { \
            if(old[i].active) { \
                uint32_t cell = ___fib_hash(old[i].hash, map->shift); \
                while(new[cell].active) { \
                    cell = (cell + 1) % map->capacity; \
                } \
                new[cell] = old[i]; \
            } \
        } \
        gds_free(old); \
        map->cells = new; \
    } \
 \
    bool function_prefix ## _add(type_name* map, key_type key, value_type value) { \
        uint32_t hash, cell; \
 \
        if(map->count == map->load_factor) \
            function_prefix ## _resize(map); \
 \
        hash = hash_fn(key); \
        cell = ___fib_hash(hash, map->shift); \
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
        hash = hash_fn(key); \
        cell = ___fib_hash(hash, map->shift); \
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
    static inline bool function_prefix ## _find_cell(type_name* map, key_type key, uint32_t* out_hash, uint32_t* out_cell) { \
        uint32_t hash, cell; \
        hash = hash_fn(key); \
        cell = ___fib_hash(hash, map->shift); \
 \
        while(true) { \
            if(!map->cells[cell].active) \
                return false; \
 \
            if(map->cells[cell].hash == hash && compare_fn(map->cells[cell].key, key) == 0) { \
                *out_hash = hash; \
                *out_cell = cell; \
                return true; \
            } \
 \
            cell = (cell + 1) % map->capacity; \
        } \
    } \
 \
    value_type function_prefix ## _get(type_name* map, key_type key) { \
        uint32_t cell, hash; \
        if(function_prefix ## _find_cell(map, key, &hash, &cell)) \
            return map->cells[cell].value; \
        else \
            return (value_type){0}; \
    } \
 \
    bool function_prefix ## _try_get(type_name* map, key_type key, value_type* out_value) { \
        uint32_t cell, hash; \
        if(function_prefix ## _find_cell(map, key, &hash, &cell)) { \
            if(out_value != NULL) \
                *out_value = map->cells[cell].value; \
            return true; \
        } else { \
            return false; \
        } \
    } \
 \
    static inline void function_prefix ## _replace_cell(type_name* map, uint32_t cell, uint32_t hash) { \
        uint32_t start = cell; \
 \
        while(true) { \
            cell = (cell + 1) % map->capacity; \
 \
            if(!map->cells[cell].active) \
                break; \
 \
            uint32_t preferred_cell = ___fib_hash(map->cells[cell].hash, map->shift); \
            if(preferred_cell <= start || preferred_cell > cell) { \
                map->cells[start] = map->cells[cell]; \
                start = cell; \
            } \
        } \
        map->cells[start].active = false; \
    } \
 \
    bool function_prefix ## _remove(type_name* map, key_type key) { \
        uint32_t cell, hash; \
        if(!function_prefix ## _find_cell(map, key, &hash, &cell)) \
            return false; \
 \
        function_prefix ## _replace_cell(map, cell, hash); \
        map->count--; \
        return true; \
    } \
 \
    bool function_prefix ## _get_and_remove(type_name* map, key_type key, key_type* out_key, value_type* out_value) { \
        uint32_t cell, hash; \
        if(!function_prefix ## _find_cell(map, key, &hash, &cell)) \
            return false; \
 \
        if(out_key != NULL) \
            *out_key = map->cells[cell].key; \
        if(out_value != NULL) \
            *out_value = map->cells[cell].value; \
 \
        function_prefix ## _replace_cell(map, cell, hash); \
        map->count--; \
        return true; \
    } \
 \
    void function_prefix ## _clear(type_name* map, bool reset_capacity) { \
        if(reset_capacity) { \
            gds_free(map->cells); \
            function_prefix ## _init(map); \
        } else { \
            map->count = 0; \
            for(uint32_t i = 0; i < map->capacity; i++) \
                map->cells[i].active = false; \
        } \
    } \


#endif //GENERIC_MAP_GENERIC_MAP_H