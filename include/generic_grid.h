#ifndef GENERIC_DATA_STRUCTURES_GRID_H
#define GENERIC_DATA_STRUCTURES_GRID_H

#include <stdlib.h>

#define GRID_DEFINE_H(type_name, function_prefix, value_type) \
    typedef struct type_name { \
        value_type* grid; \
        int width; \
        int height; \
    } type_name; \
 \
    void function_prefix ## _init(type_name* grid, int width, int height); \
    type_name* function_prefix ## _create(int width, int height); \
    void function_prefix ## _free(type_name* grid); \
    void function_prefix ## _free_resources(type_name* grid); \
    void function_prefix ## _clear(type_name* grid, value_type default_value); \
 \
    static inline int function_prefix ## _width(type_name* grid) { \
        return grid->width; \
    } \
 \
    static inline int function_prefix ## _height(type_name* grid) { \
        return grid->height; \
    } \
 \
    static inline value_type function_prefix ## _get(type_name* grid, int x, int y) { \
        assert((unsigned int)x < grid->width); \
        assert((unsigned int)y < grid->height); \
        return grid->grid[y * grid->width + x]; \
    } \
 \
    static inline void value_type function_prefix ## _set(type_name* grid, int x, int y, value_type value) { \
        assert((unsigned int)x < grid->width); \
        assert((unsigned int)y < grid->height); \
        grid->grid[y * grid->width + x] = value; \
    } \

#define GRID_DEFINE_C(type_name, function_prefix, value_type) \
    void function_prefix ## _init(Grid* grid, int width, int height) { \
        grid->width = width; \
        grid->height = height; \
        grid->grid = malloc(width * height * sizeof(value_type)); \
    } \
 \
    type_name* function_prefix ## _create(int width, int height) { \
        type_name* grid = malloc(sizeof(type_name)); \
        grid->width = width; \
        grid->height = height; \
        grid->grid = malloc(width * height * sizeof(value_type)); \
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
        for(int w = 0; w < grid->width; w++) { \
            for(int h = 0; h < grid->height; h++) { \
                grid->grid[h * grid->width + w] = default_value; \
            } \
        } \
    }

#endif