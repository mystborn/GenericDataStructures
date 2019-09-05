#ifndef GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_LIST_ITERATOR_H
#define GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_LIST_ITERATOR_H

#define list_iter_start(list, out_value) \
    for(int list_iter_i = 0; list_iter_i < (list)->capacity; list_iter_i++) { \
        out_value = (list)->buffer[list_iter_i];

#define list_iter_end }

#endif