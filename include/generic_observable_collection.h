#ifndef GENERIC_DATA_STRUCTURES_GENERIC_OBSERVABLE_COLLECTION_H
#define GENERIC_DATA_STRUCTURES_GENERIC_OBSERVABLE_COLLECTION_H

/*
    More or less an implementation of C#'s observable collection.
    https://docs.microsoft.com/en-us/dotnet/api/system.collections.objectmodel.observablecollection-1
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "generic_event.h"

typedef enum GdsNotifyCollectionChangedAction {
    /// One or more items were added to the collection.
    GDS_OBSERVABLE_COLLECTION_CHANGED_ADD,
    GDS_OBSERVABLE_COLLECTION_CHANGED_REMOVE,
    GDS_OBSERVABLE_COLLECTION_CHANGED_REPLACE,
    GDS_OBSERVABLE_COLLECTION_CHANGED_MOVE,
    GDS_OBSERVABLE_COLLECTION_CHANGED_CLEAR
} GdsNotifyCollectionChangedAction;

#define OBSERVABLE_COLLECTION_DEFINE_H(type_name, function_prefix, value_type) \
    typedef struct type_name type_name; \
 \
    typedef struct type_name ## ChangedData { \
        value_type old_item; \
        value_type new_item; \
        unsigned int old_index; \
        unsigned int new_index; \
        GdsNotifyCollectionChangedAction action; \
    } type_name ## ChangedData; \
 \
    EVENT_DEFINE_2_H(type_name ## ChangedEvent, function_prefix ## _changed_event, type_name*, type_name ## ChangedData*) \
 \
    struct type_name { \
        value_type* buffer; \
        type_name ## ChangedEvent* collection_changed; \
        unsigned int count; \
        unsigned int capacity; \
        int block_reentrance_count; \
    }; \
 \
    type_name* function_prefix ## _create(void); \
    bool function_prefix ## _init(type_name* observer); \
    void function_prefix ## _free(type_name* observer); \
    void function_prefix ## _free_resources(type_name* observer); \
 \
    bool function_prefix ## _set(type_name* observer, unsigned int index, value_type value); \
    bool function_prefix ## _add(type_name* observer, value_type value); \
    bool function_prefix ## _insert(type_name* observer, unsigned int index, value_type value); \
    void function_prefix ## _clear(type_name* observer); \
    void function_prefix ## _remove(type_name* observer, unsigned int index); \
    void function_prefix ## _move(type_name* observer, unsigned int old_index, unsigned int new_index); \
 \
    static inline unsigned int function_prefix ## _count(type_name* observer) { return observer->count; } \
    static inline type_name ## ChangedEvent* function_prefix ## _collection_changed(type_name* observer) { return observer->collection_changed; } \
    static inline value_type* function_prefix ## _items(type_name* observer, int* out_count) { *out_count = observer->count; return observer->buffer; } \
    static inline void function_prefix ## _block_entrance(type_name* observer) { observer->block_reentrance_count++; } \
    static inline void function_prefix ## _free_entrance(type_name* observer) { observer->block_reentrance_count--; } \
 \
    static inline value_type function_prefix ## _get(type_name* observer, unsigned int index) { \
        assert(index < observer->count); \
        return observer->buffer[index]; \
    } \



#define OBSERVABLE_COLLECTION_DEFINE_C(type_name, function_prefix, value_type) \
    EVENT_DEFINE_C(type_name ## ChangedEvent, function_prefix ## _changed_event) \
 \
    static inline void function_prefix ## _check_reentrance(type_name* observer) { \
        if(observer->block_reentrance_count > 0) { \
            /* Changes are allowed if there's only one listener */ \
            assert(observer->collection_changed->count <= 1); \
        } \
    } \
 \
    static inline void function_prefix ## _on_collection_changed(type_name* observer, type_name ## ChangedData* data) { \
        function_prefix ## _block_entrance(observer); \
        function_prefix ## _changed_event_trigger(observer->collection_changed, observer, data); \
        function_prefix ## _free_entrance(observer); \
    } \
 \
    static bool function_prefix ## _resize(type_name* observer) { \
        unsigned int capacity = observer->capacity == 0 ? 4 : observer->capacity * 2; \
        void* buffer = realloc(observer->buffer, capacity * sizeof(*observer->buffer)); \
        if(!buffer) \
            return false; \
        observer->buffer = buffer; \
        observer->capacity = capacity; \
        return true; \
    } \
 \
    type_name* function_prefix ## _create(void) { \
        type_name* observer = malloc(sizeof(*observer)); \
        if(!observer) \
            return NULL; \
 \
        if(!function_prefix ## _init(observer)) { \
            free(observer); \
            return NULL; \
        } \
 \
        return observer; \
    } \
 \
    bool function_prefix ## _init(type_name* observer) { \
        type_name ## ChangedEvent* ev = function_prefix ## _changed_event_create(); \
        if(!ev) \
            return false; \
 \
        observer->buffer = NULL; \
        observer->collection_changed = ev; \
        observer->count = 0; \
        observer->capacity = 0; \
        observer->block_reentrance_count = 0; \
        return true; \
    } \
 \
    void function_prefix ## _free(type_name* observer) { \
        function_prefix ## _check_reentrance(observer); \
 \
        function_prefix ## _changed_event_free(observer->collection_changed); \
        free(observer->buffer); \
        free(observer); \
    } \
 \
    void function_prefix ## _free_resources(type_name* observer) { \
        function_prefix ## _check_reentrance(observer); \
 \
        function_prefix ## _changed_event_free(observer->collection_changed); \
        free(observer->buffer); \
    } \
 \
    bool function_prefix ## _set(type_name* observer, unsigned int index, value_type value) { \
        assert(index <= observer->count); \
 \
        if(index == observer->count) \
            return function_prefix ## _add(observer, value); \
 \
        function_prefix ## _check_reentrance(observer); \
        value_type old_item = function_prefix ## _get(observer, index); \
 \
        observer->buffer[index] = value; \
        type_name ## ChangedData data = { .old_item = old_item,  \
                                          .new_item = value,  \
                                          .old_index = index, \
                                          .new_index = index, \
                                          .action = GDS_OBSERVABLE_COLLECTION_CHANGED_REPLACE }; \
 \
        function_prefix ## _on_collection_changed(observer, &data); \
        return true; \
    } \
 \
    bool function_prefix ## _add(type_name* observer, value_type value) { \
        function_prefix ## _check_reentrance(observer); \
 \
        if(observer->count == observer->capacity) { \
            if(!function_prefix ## _resize(observer)) \
                return false; \
        } \
 \
        observer->buffer[observer->count] = value; \
        type_name ## ChangedData data = { .new_item = value,  \
                                          .new_index = observer->count++,  \
                                          .action = GDS_OBSERVABLE_COLLECTION_CHANGED_ADD }; \
 \
        function_prefix ## _on_collection_changed(observer, &data); \
        return true; \
    } \
 \
    bool function_prefix ## _insert(type_name* observer, unsigned int index, value_type value) { \
        if(index > observer->count) return false; \
        if(index == observer->count) \
            return function_prefix ## _add(observer, value); \
 \
        function_prefix ## _check_reentrance(observer); \
 \
        if(observer->count == observer->capacity) { \
            if(!function_prefix ## _resize(observer)) \
                return false; \
        } \
 \
        memmove(observer->buffer + index + 1, observer->buffer + index, (observer->count++ - index) * sizeof(*observer->buffer)); \
        observer->buffer[index] = value; \
 \
        type_name ## ChangedData data = { .new_item = value,  \
                                          .new_index = index,  \
                                          .action = GDS_OBSERVABLE_COLLECTION_CHANGED_ADD }; \
 \
        function_prefix ## _on_collection_changed(observer, &data); \
        return true; \
    } \
 \
    void function_prefix ## _clear(type_name* observer) { \
        function_prefix ## _check_reentrance(observer); \
        type_name ## ChangedData data = { .action = GDS_OBSERVABLE_COLLECTION_CHANGED_CLEAR }; \
        function_prefix ## _on_collection_changed(observer, &data); \
        observer->count = 0; \
    } \
 \
    void function_prefix ## _remove(type_name* observer, unsigned int index) { \
        assert(index < observer->count); \
        function_prefix ## _check_reentrance(observer); \
 \
        value_type value = observer->buffer[index]; \
 \
        if(index != --observer->count) \
            memmove(observer->buffer + index, observer->buffer + index + 1, (observer->count - index) * sizeof(*observer->buffer)); \
 \
 \
        type_name ## ChangedData data = { .old_item = value,  \
                                          .old_index = index,  \
                                          .action = GDS_OBSERVABLE_COLLECTION_CHANGED_REMOVE }; \
 \
        function_prefix ## _on_collection_changed(observer, &data); \
    } \
 \
    void function_prefix ## _move(type_name* observer, unsigned int old_index, unsigned int new_index) { \
        assert(old_index < observer->count && new_index < observer->count); \
        function_prefix ## _check_reentrance(observer); \
 \
        value_type value = observer->buffer[old_index]; \
 \
        if(old_index != observer->count - 1) \
            memmove(observer->buffer + old_index, observer->buffer + old_index + 1, (observer->count - old_index - 1) * sizeof(*observer->buffer)); \
 \
        memmove(observer->buffer + new_index + 1, observer->buffer + new_index, (observer->count - new_index) * sizeof(*observer->buffer)); \
 \
        observer->buffer[new_index] = value; \
        type_name ## ChangedData data = { .old_item = value,  \
                                          .new_item = value,  \
                                          .old_index = old_index, \
                                          .new_index = new_index, \
                                          .action = GDS_OBSERVABLE_COLLECTION_CHANGED_MOVE }; \
 \
        function_prefix ## _on_collection_changed(observer, &data); \
    } \


#endif