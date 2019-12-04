---
tags: c set
---
# set_get

A special operation to get the actual version of a value inside of a set.

By "value", it means the value that was initially added to the set. This function was created to allow users to get dynamically allocated values from the set when they were done if the compare function compared on data or members instead of the memory address. I imagine the most common use case for this function will be to free dynamically allocated strings that are retrieved using a string literal. You can see what I mean in the example section.

## Syntax

```c
bool set_get(Set* set, value_type value, value_type* out_value);
```

| Name | Type | Description |
| --- | --- | --- |
| set | Set* | A pointer to the set. |
| value | value_type | The value to find in the set. |
| out_value | value_type* | A pointer to be filled with the original value if found. |

**Returns:** `true` if the value was found, `false` otherwise.

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

// Allocate and initialize a string dynamically.
char* heap_string = malloc(4);
strcpy(heap_string, "owl");

// Add the dynamic string to the set.
str_set_add(set, heap_string);

// To simulate the variable going out of scope,
// NULL it out.
heap_string = NULL;

// Get the original string that was added to the map.
char* value;
bool success = str_set_get(set, "owl", &value);

// Finish using the map.
str_set_free(set);

// If the value was found, free the dynamic version of it.
if(success) {
    free(value);
}
```