# set_clear

Clears all elements from the set.

## Syntax

```c
void set_clear(Set* set, bool reset_capacity);
```

| Name | Type | Description |
| --- | --- | --- |
| set | Set* | A pointer to the set. |
| reset_capacity | bool | Determines whether to reset the internal size of the set or leave it as is. |

## Remarks

Resetting the capacity of the set can create more space for the application, but leaving it as is will make it faster (no need to resize, less likely hash collisions).

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

si_map_add(set, "one");
si_map_add(set, "two");
si_map_add(set, "three");

// Clears the values in the set without resetting it's internal storage.
str_set_clear(set, false);
```