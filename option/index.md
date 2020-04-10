# Option

An option is a type that can potentially hold a value. In other words, it is used to represent a situation where there may or may not be a value. It is similar to `Option<T>` in rust or `Nullable<T>` in C#. 

Unlike most of the other data structures included in this library, all of the functions related to Option pass their arguments by value instead of through a pointer.

## Syntax

```c
OPTION_DEFINE_H(type_name, function_prefix, value_type)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the map functions with. |
| value_type | The type that can potentially be held by the option. |

## Fields

These shouldn't be accessed directly. Instead, use the corresponding functions (which should be inlined) or macros. However, they're documented just in case.

| Name | Type | Description |
| --- | --- | --- |
| value | value_type | The value held by the option. |
| has_value | bool | Determines if the option has a value or not. |

## Example

```c
#include <generic_option.h>

OPTION_DEFINE_H(StringOption, str_opt, char*)

StringOption none = str_opt_default();
StringOption some = str_opt_make("Hello World");

printf("none has value? %s\n", str_opt_has_value(none) ? "true" : "false");
printf("some has value? %s\n", str_opt_has_value(some) ? "true" : "false");

printf("somes value: %s\n", str_opt_value(some));

// Output:
// none has value? false
// some has value? true
// somes value: Hello World
```