# set_capacity

Gets the number of elements a set can hold without resizing.

## Syntax

```c
uint32_t set_capacity(Set* set);
```

| Name | Type | Description |
| --- | --- | --- |
| set | Set* | A pointer to the set. |

## Remarks

This is not the same as the allocated size of the sets internal buffer. To get that, see [set_allocated]({{site.baseurl}}/set/set-allocated).

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

uint32_t capacity = str_set_capacity(set);

printf("Capacity: %u\n", capacity);

str_set_free(set);

// Output:
// Capacity: 4
```