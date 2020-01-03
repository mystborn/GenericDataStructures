#ifndef GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_DEQUE_ITERATOR_H
#define GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_DEQUE_ITERATOR_H

#define deque_iter_start(deque, out_value) \
    { \
        unsigned int ___deque_iter_pos = deque->start, ___deque_iter_i = 0; \
        while(___deque_iter_i++ < deque->count) { \
            out_value = deque->buffer[___deque_iter_pos]; \
            ___deque_iter_pos = ___deque_iter_pos == deque->capacity - 1 ? 0 : ___deque_iter_pos + 1; \

#define deque_iter_end } }

#endif