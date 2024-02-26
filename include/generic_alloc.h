#ifndef GENERIC_DATA_STRUCTURES_GENERIC_ALLOC_H
#define GENERIC_DATA_STRUCTURES_GENERIC_ALLOC_H

#ifdef GDS_BUILD
    #if defined(_WIN32)
        #define GDS_EXPORT __declspec(dllexport)
    #elif defined(__ELF__)
        #define GDS_EXPORT __attribute__((visibility ("default")))
    #else
        #define GDS_EXPORT
    #endif
#else
    #if defined(_WIN32)
        #define GDS_EXPORT __declspec(dllimport)
    #else
        #define GDS_EXPORT
    #endif
#endif

#ifndef gds_malloc
#define gds_malloc malloc
#endif

#ifndef gds_realloc
#define gds_realloc realloc
#endif

#ifndef gds_calloc
#define gds_calloc calloc
#endif

#ifndef gds_free
#define gds_free free
#endif

#ifndef gds_assert_arg
#define gds_assert_arg assert
#endif

#ifndef gds_assert_bounds
#define gds_assert_bounds assert
#endif

#endif