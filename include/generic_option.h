#ifndef GENERIC_DATA_STRUCTURES_GENERIC_OPTIONAL_H
#define GENERIC_DATA_STRUCTURES_GENERIC_OPTIONAL_H

#include <assert.h>
#include <stdbool.h>

#include "generic_alloc.h"

#define OPTION_DEFINE_H(type_name, function_prefix, value_type) \
    typedef struct type_name { \
        value_type value; \
        bool has_value; \
    } type_name; \
 \
    static inline type_name function_prefix ## _make(value_type value) { return (type_name){ value, true }; } \
    static inline type_name function_prefix ## _default(void) { return (type_name){ .has_value = false }; } \
    static inline bool function_prefix ## _has_value(type_name optional) { return optional.has_value; } \
    static inline value_type function_prefix ## _value(type_name optional) { gds_assert_arg(optional.has_value); return optional.value; } \
    static inline value_type function_prefix ## _value_or_default(type_name optional) { return optional.value; } \


#define gds_option_make(type_name, value) ((type_name){ value, true })
#define gds_option_default(type_name) ((type_name){ .has_value = false })
#define gds_option_has_value(optional) ((optional).has_value)
#define gds_option_value(optional) (gds_assert_arg((optional).has_value), (optional).value)
#define gds_option_value_or_default(optional) ((optional).value)

#endif