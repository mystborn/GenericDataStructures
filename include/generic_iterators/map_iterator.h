#ifndef GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_MAP_ITERATOR_H
#define GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_MAP_ITERATOR_H

#define map_iter_start(map, out_key, out_value) \
    for(int map_iter_i = 0; map_iter_i < map->capacity; map_iter_i++) {  \
        if(!map->cells[map_iter_i].active) \
            continue; \
        out_key = map->cells[map_iter_i].key; \
        out_value = map->cells[map_iter_i].value;

#define map_iter_key_start(map, out_key) \
    for(int map_iter_i = 0; map_iter_i < map->capacity; map_iter_i++) {  \
        if(!map->cells[map_iter_i].active) \
            continue; \
        out_key = map->cells[map_iter_i].key;

#define map_iter_value_start(map, out_value) \
    for(int map_iter_i = 0; map_iter_i < map->capacity; map_iter_i++) {  \
        if(!map->cells[map_iter_i].active) \
            continue; \
        out_value = map->cells[map_iter_i].value;

#define map_iter_end }

#endif