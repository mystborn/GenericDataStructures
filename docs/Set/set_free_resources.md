---
tags: c set
---
# set_free_resources

Frees the resources used by a set without freeing the set itself.

## Syntax

```c
void set_free_resources(Set* set);
```

| Name | Type | Description |
| --- | --- | --- |
| set | Set* | A pointer to the set. |

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet set;
str_set_init(&set);

// Use the set...

str_set_free_resources(&set);
```