#ifndef GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_QUEUE_ITERATOR
#define GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_QUEUE_ITERATOR

#define queue_iter_start(queue, out_value) \
    for(int queue_iter_i = (queue)->start; queue_iter_i != (queue)->end; queue_iter_i = (++queue_iter_i == (queue)->capacity ? 0 : queue_iter_i)) { \
        out_value = (queue)->buffer[queue_iter_i];

#define queue_iter_end }

#endif