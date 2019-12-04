---
tags: c set
---
# set_count

Gets the number of items in a set.

## Syntax

```c
uint32_t set_count(Set* set);
```

| Name | Type | Description |
| --- | --- | --- |
| set | Set* | A pointer to the set. |

**Returns:** The number of items in the set.

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

str_set_add(set, "owl");
str_set_add(set, "raven");

uint32_t count = str_set_count(set);
assert(count == 2);

str_set_free(set);
```