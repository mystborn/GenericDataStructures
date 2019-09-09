#ifndef GENERIC_DATA_STRUCTURES_GRID_H
#define GENERIC_DATA_STRUCTURES_GRID_H

#include <assert.h>
#include <stdlib.h>

#define GRID_DEFINE_H(type_name, function_prefix, value_type) \
    typedef struct type_name { \
        value_type* grid; \
        unsigned int width; \
        unsigned int height; \
    } type_name; \
 \
    void function_prefix ## _init(type_name* grid, unsigned int width, unsigned int height); \
    type_name* function_prefix ## _create(unsigned int width, unsigned int height); \
    void function_prefix ## _free(type_name* grid); \
    void function_prefix ## _free_resources(type_name* grid); \
    void function_prefix ## _clear(type_name* grid, value_type default_value); \
 \
    static inline unsigned int function_prefix ## _width(type_name* grid) { \
        return grid->width; \
    } \
 \
    static inline unsigned int function_prefix ## _height(type_name* grid) { \
        return grid->height; \
    } \
 \
    static inline value_type function_prefix ## _get(type_name* grid, unsigned int x, unsigned int y) { \
        assert(x < grid->width); \
        assert(y < grid->height); \
        return grid->grid[y * grid->width + x]; \
    } \
 \
    static inline void function_prefix ## _set(type_name* grid, unsigned int x, unsigned int y, value_type value) { \
        assert(x < grid->width); \
        assert(y < grid->height); \
        grid->grid[y * grid->width + x] = value; \
    } \

#define GRID_DEFINE_C(type_name, function_prefix, value_type) \
    void function_prefix ## _init(type_name* grid, unsigned int width, unsigned int height) { \
        grid->width = width; \
        grid->height = height; \
        grid->grid = malloc(width * height * sizeof(value_type)); \
    } \
 \
    type_name* function_prefix ## _create(unsigned int width, unsigned int height) { \
        type_name* grid = malloc(sizeof(type_name)); \
        if(!grid) \
            return NULL; \
        grid->width = width; \
        grid->height = height; \
        if(!(grid->grid = malloc(width * height * sizeof(value_type)))) { \
            free(grid); \
            return NULL; \
        } \
        return grid; \
    } \
 \
    void function_prefix ## _free(type_name* grid) { \
        free(grid->grid); \
        free(grid); \
    } \
 \
    void function_prefix ## _free_resources(type_name* grid) { \
        free(grid->grid); \
    } \
    \
    void function_prefix ## _clear(type_name* grid, value_type default_value) { \
        for(unsigned int h = 0; h < grid->height; h++) { \
            for(unsigned int w = 0; w < grid->width; w++) { \
                grid->grid[h * grid->width + w] = default_value; \
            } \
        } \
    }

#endif