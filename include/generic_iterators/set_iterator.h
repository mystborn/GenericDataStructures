#ifndef GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_SET_ITERATOR_H
#define GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_SET_ITERATOR_H

#define set_iter_start(set, out_key) \
    for(int set_iter_i = 0; set_iter_i < (set)->capacity; set_iter_i++) {  \
        if(!(set)->cells[set_iter_i].active) \
            continue; \
        out_key = (set)->cells[set_iter_i].value;

#define set_iter_end }

#endif