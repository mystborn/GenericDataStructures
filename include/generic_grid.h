#ifndef GENERIC_DATA_STRUCTURES_GRID_H
#define GENERIC_DATA_STRUCTURES_GRID_H

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "generic_alloc.h"

#define GRID_DEFINE_H(type_name, function_prefix, value_type) \
    typedef struct type_name { \
        value_type* grid; \
        unsigned int width; \
        unsigned int height; \
    } type_name; \
 \
    type_name* function_prefix ## _create(unsigned int width, unsigned int height); \
    bool function_prefix ## _init(type_name* grid, unsigned int width, unsigned int height); \
    void function_prefix ## _free(type_name* grid); \
    void function_prefix ## _free_resources(type_name* grid); \
    void function_prefix ## _clear(type_name* grid, value_type default_value); \
    bool function_prefix ## _resize(type_name* grid, unsigned int width, unsigned int height, value_type default_value); \
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
    static inline value_type* function_prefix ## _get_ref(type_name* grid, unsigned int x, unsigned int y) { \
        assert(x < grid->width); \
        assert(y < grid->height); \
        return &grid->grid[y * grid->width + x]; \
    } \
 \
    static inline void function_prefix ## _set(type_name* grid, unsigned int x, unsigned int y, value_type value) { \
        assert(x < grid->width); \
        assert(y < grid->height); \
        grid->grid[y * grid->width + x] = value; \
    } \

// TODO: Optimize resize function
//       Especially try to avoid an extra malloc if unneeded.

#define GRID_DEFINE_C(type_name, function_prefix, value_type) \
    bool function_prefix ## _init(type_name* grid, unsigned int width, unsigned int height) { \
        grid->width = width; \
        grid->height = height; \
        return (grid->grid = gds_malloc(width * height * sizeof(value_type))) != NULL; \
    } \
 \
    type_name* function_prefix ## _create(unsigned int width, unsigned int height) { \
        type_name* grid = gds_malloc(sizeof(type_name)); \
        if(!grid) \
            return NULL; \
        if(!function_prefix ## _init(grid, width, height)) { \
            gds_free(grid); \
            return NULL; \
        } \
        return grid; \
    } \
 \
    void function_prefix ## _free(type_name* grid) { \
        gds_free(grid->grid); \
        gds_free(grid); \
    } \
 \
    void function_prefix ## _free_resources(type_name* grid) { \
        gds_free(grid->grid); \
    } \
    \
    void function_prefix ## _clear(type_name* grid, value_type default_value) { \
        for(unsigned int h = 0; h < grid->height; h++) { \
            for(unsigned int w = 0; w < grid->width; w++) { \
                grid->grid[h * grid->width + w] = default_value; \
            } \
        } \
    } \
 \
    bool function_prefix ## _resize(type_name* grid, unsigned int width, unsigned int height, value_type default_value) { \
        if(width == grid->width && height == grid->height) \
            return true; \
 \
        unsigned int min_width = width < grid->width ? width : grid->width; \
        unsigned int min_height = height < grid->height ? height : grid->height; \
        value_type* original = grid->grid; \
 \
        if(min_width != width || min_height != height) { \
            value_type* buffer = gds_malloc(width * height * sizeof(*buffer)); \
            if(!buffer) \
                return false; \
 \
            grid->grid = buffer; \
 \
            for(int y = 0; y < height; y++) { \
                for(int x = 0; x < width; x++) { \
                    if(x < min_width && y < min_height) \
                        continue; \
 \
                    grid->grid[y * width + x] = default_value; \
                } \
            } \
        } \
 \
        /* This will copy the rows over in chunks. */ \
        for(int y = 0; y < min_height; y++) \
            memmove(&grid->grid[y * width], &original[y * grid->width], min_width * sizeof(*grid->grid)); \
 \
        /* If the grid was smaller than before, prune excess memory. */ \
        if(width == min_width && height == min_height) \
            grid->grid = gds_realloc(grid->grid, width * height * sizeof(*grid->grid)); \
        else \
            gds_free(original); \
 \
        grid->width = width; \
        grid->height = height; \
 \
        return true; \
    } \


#endif