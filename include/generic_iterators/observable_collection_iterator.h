#ifndef GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_OBSERVABLE_COLLECTION_ITERATOR_H
#define GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_OBSERVABLE_COLLECTION_ITERATOR_H

#define observable_collection_iter_start(observable, out_value) \
    for(int observable_iter_i = 0; observable_iter_i < (observable)->count; observable_iter_i++) { \
        out_value = (observable)->buffer[observable_iter_i];

#define observable_collection_iter_end }

#endif