#ifndef GENERIC_DATA_STRUCTURES_GENERIC_EVENT_H
#define GENERIC_DATA_STRUCTURES_GENERIC_EVENT_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "generic_alloc.h"

// ============================================================================
// Generic Event via template-like macros
// ============================================================================

#define ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
    struct type_name ## Subscription { \
        void* data; \
        type_name ## Delegate function; \
    }; \
 \
    typedef struct type_name { \
        struct type_name ## Subscription* subscriptions; \
        unsigned int count; \
        unsigned int capacity; \
    } type_name; \
 \
    GDS_EXPORT bool function_prefix ## _subscribe(type_name* ev, void* ctx, type_name ## Delegate function); \
    GDS_EXPORT bool function_prefix ## _unsubscribe(type_name* ev, void* ctx, type_name ## Delegate function); \
 \
    static inline void function_prefix ## _init(type_name* ev) { \
        ev->count = 0; \
        ev->capacity = 0; \
        ev->subscriptions = NULL; \
    } \
 \
    static inline type_name* function_prefix ## _create(void) { \
        type_name* ev = gds_malloc(sizeof(*ev)); \
        if(!ev) \
            return NULL; \
 \
        function_prefix ## _init(ev); \
        return ev; \
    } \
 \
    static inline void function_prefix ## _free(type_name* ev) { \
        gds_free(ev->subscriptions); \
        gds_free(ev); \
    } \
 \
    static inline void function_prefix ## _free_resources(type_name* ev) { \
        gds_free(ev->subscriptions); \
    } \

#define EVENT_DEFINE_0_H(type_name, function_prefix) \
    typedef void (*type_name ## Delegate)(void*); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data); \
        } \
    } \


#define EVENT_DEFINE_1_H(type_name, function_prefix, arg1) \
    typedef void (*type_name ## Delegate)(void*, arg1); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev, arg1 a1) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data, a1); \
        } \
    } \


#define EVENT_DEFINE_2_H(type_name, function_prefix, arg1, arg2) \
    typedef void (*type_name ## Delegate)(void*, arg1, arg2); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev, arg1 a1, arg2 a2) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data, a1, a2); \
        } \
    } \


#define EVENT_DEFINE_3_H(type_name, function_prefix, arg1, arg2, arg3) \
    typedef void (*type_name ## Delegate)(void*, arg1, arg2, arg3); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev, arg1 a1, arg2 a2, arg3 a3) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data, a1, a2, a3); \
        } \
    } \


#define EVENT_DEFINE_4_H(type_name, function_prefix, arg1, arg2, arg3, arg4) \
    typedef void (*type_name ## Delegate)(void*, arg1, arg2, arg3, arg4); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev, arg1 a1, arg2 a2, arg3 a3, arg4 a4) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data, a1, a2, a3, a4); \
        } \
    } \


#define EVENT_DEFINE_5_H(type_name, function_prefix, arg1, arg2, arg3, arg4, arg5) \
    typedef void (*type_name ## Delegate)(void*, arg1, arg2, arg3, arg4, arg5); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev, arg1 a1, arg2 a2, arg3 a3, arg4 a4, arg5 a5) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data, a1, a2, a3, a4, a5); \
        } \
    } \


#define EVENT_DEFINE_6_H(type_name, function_prefix, arg1, arg2, arg3, arg4, arg5, arg6) \
    typedef void (*type_name ## Delegate)(void*, arg1, arg2, arg3, arg4, arg5, arg6); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev, arg1 a1, arg2 a2, arg3 a3, arg4 a4, arg5 a5, arg6 a6) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data, a1, a2, a3, a4, a5, a6); \
        } \
    } \


#define EVENT_DEFINE_7_H(type_name, function_prefix, arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    typedef void (*type_name ## Delegate)(void*, arg1, arg2, arg3, arg4, arg5, arg6, arg7); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev, arg1 a1, arg2 a2, arg3 a3, arg4 a4, arg5 a5, arg6 a6, arg7 a7) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data, a1, a2, a3, a4, a5, a6, a7); \
        } \
    } \


#define EVENT_DEFINE_8_H(type_name, function_prefix, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    typedef void (*type_name ## Delegate)(void*, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev, arg1 a1, arg2 a2, arg3 a3, arg4 a4, arg5 a5, arg6 a6, arg7 a7, arg8 a8) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data, a1, a2, a3, a4, a5, a6, a7, a8); \
        } \
    } \


#define EVENT_DEFINE_9_H(type_name, function_prefix, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    typedef void (*type_name ## Delegate)(void*, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev, arg1 a1, arg2 a2, arg3 a3, arg4 a4, arg5 a5, arg6 a6, arg7 a7, arg8 a8, arg9 a9) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data, a1, a2, a3, a4, a5, a6, a7, a8, a9); \
        } \
    } \


#define EVENT_DEFINE_10_H(type_name, function_prefix, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    typedef void (*type_name ## Delegate)(void*, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10); \
 \
    ___EVENT_DEFINE_H_SHARED(type_name, function_prefix) \
 \
    static inline void function_prefix ## _trigger(type_name* ev, arg1 a1, arg2 a2, arg3 a3, arg4 a4, arg5 a5, arg6 a6, arg7 a7, arg8 a8, arg9 a9, arg10 a10) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            struct type_name ## Subscription subscription = ev->subscriptions[i]; \
            (subscription.function)(subscription.data, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); \
        } \
    } \


#define EVENT_DEFINE_C(type_name, function_prefix) \
    GDS_EXPORT bool function_prefix ## _subscribe(type_name* ev, void* ctx, type_name ## Delegate function) { \
        if(ev->count == ev->capacity) { \
            unsigned int capacity = ev->capacity; \
            if(capacity == 0) \
                capacity = 2; \
            else \
                capacity *= 2; \
 \
            void* buffer = gds_realloc(ev->subscriptions, capacity * sizeof(*ev->subscriptions)); \
            if(!buffer) \
                return false; \
 \
            ev->capacity = capacity; \
            ev->subscriptions = buffer; \
        } \
 \
        ev->subscriptions[ev->count].data = ctx; \
        ev->subscriptions[ev->count++].function = function; \
 \
        return true; \
    } \
 \
    GDS_EXPORT bool function_prefix ## _unsubscribe(type_name* ev, void* ctx, type_name ## Delegate function) { \
        for(unsigned int i = 0; i < ev->count; i++) { \
            if(ev->subscriptions[i].data == ctx && ev->subscriptions[i].function == function) { \
                if(i != ev->count - 1) \
                    memmove(&ev->subscriptions[i], &ev->subscriptions[i + 1], (ev->count - i) * sizeof(*ev->subscriptions)); \
 \
                ev->count--; \
                return true; \
            } \
        } \
 \
        return false; \
    } \


// ============================================================================
// Generic Event via void*
// ============================================================================

struct GdsEventSubscription {
    void* data;
    void* function;
};

typedef struct GdsEvent {
    struct GdsEventSubscription* subscriptions;
    int count;
    int capacity;
} GdsEvent;

GDS_EXPORT bool gds_event_subscribe(GdsEvent* ev, void* ctx, void* function);
GDS_EXPORT bool gds_event_unsubscribe(GdsEvent* ev, void* ctx, void* function);

static inline void gds_event_init(GdsEvent* ev) {
    ev->subscriptions = NULL;
    ev->count = 0;
    ev->capacity = 0;
}

static inline GdsEvent* gds_event_create(void) {
    GdsEvent* ev = gds_malloc(sizeof(*ev));
    if(!ev)
        return NULL;

    gds_event_init(ev);
    return ev;
}

static inline void gds_event_free_resources(GdsEvent* ev) { gds_free(ev->subscriptions); }
static inline void gds_event_free(GdsEvent* ev) { gds_free(ev->subscriptions); gds_free(ev); }

#define GDS_EVENT_DEFAULT void (*)(void*)
#define GDS_EVENT_SIGNATURE(...) void (*)(void*, ## __VA_ARGS__ )

#define GDS_EVENT_TRIGGER(ev, event_signature, ...) \
    do { \
        for(int ___gds_event_index = 0; ___gds_event_index < (ev)->count; ++___gds_event_index) { \
            struct GdsEventSubscription ___gds_event_subscription = (ev)->subscriptions[___gds_event_index]; \
            ((event_signature)(___gds_event_subscription.function))(___gds_event_subscription.data, ## __VA_ARGS__ ); \
        } \
    } while(0)


#ifdef GENERIC_EVENT_IMPLEMENTATION
#ifndef GENERIC_EVENT_IMPLEMENTATION_ONCE
#define GENERIC_EVENT_IMPLEMENTATION_ONCE

GDS_EXPORT bool gds_event_subscribe(GdsEvent* ev, void* ctx, void* function) {
    if(ev->count == ev->capacity) {
        unsigned int capacity = ev->capacity;
        if(capacity == 0)
            capacity = 2;
        else
            capacity *= 2;

        void* buffer = gds_realloc(ev->subscriptions, capacity * sizeof(*ev->subscriptions));
        if(!buffer)
            return false;

        ev->capacity = capacity;
        ev->subscriptions = buffer;
    }

    ev->subscriptions[ev->count].data = ctx;
    ev->subscriptions[ev->count++].function = function;

    return true;
}

GDS_EXPORT bool gds_event_unsubscribe(GdsEvent* ev, void* ctx, void* function) {
    for(unsigned int i = 0; i < ev->count; i++) {
        if(ev->subscriptions[i].data == ctx && ev->subscriptions[i].function == function) {
            if(i != ev->count - 1) {
                memmove(&ev->subscriptions, 
                        &ev->subscriptions[i + 1], 
                        (ev->count - i) * sizeof(*ev->subscriptions));
            }

            ev->count--;
            return true;
        }
    }

    return false;
}

#endif // GENERIC_EVENT_IMPLEMENTATION_ONCE
#endif // GENERIC_EVENT_IMPLEMENTATION

#endif // GENERIC_DATA_STRUCTURES_GENERIC_EVENT_H