#ifndef GENERIC_DATA_STRUCTURES_HASH_UTILS_H
#define GENERIC_DATA_STRUCTURES_HASH_UTILS_H

/*
    Defines some utility functions used by both the map and set structures.
*/

#include <stdint.h>

// A detailed explanation of this can be found here: 
// https://probablydance.com/2018/06/16/fibonacci-hashing-the-optimization-that-the-world-forgot-or-a-better-alternative-to-integer-modulo/

// The specific constant was found here:
// http://book.huihoo.com/data-structures-and-algorithms-with-object-oriented-design-patterns-in-c++/html/page214.html

static inline uint32_t ___fib_hash(uint32_t hash, uint32_t shift) {
    return (hash * 2654435769) >> shift;
}

#define FNV_PRIME_32 0x01000193
#define FNV_OFFSET_32 0x811c9dc5

static uint32_t fnv32(const char* data) {
    uint32_t hash = FNV_OFFSET_32;
    while(*data != 0)
        hash = (*data++ ^ hash) * FNV_PRIME_32;

    return hash;
}

#endif