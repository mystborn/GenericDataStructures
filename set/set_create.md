# set_create

Allocates and initializes a new set.

## Syntax

```c
Set* set_create(void);
```

**Returns:** A pointer to a new set on success, `NULL` on failure.

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

// Use the set...

str_set_free(set);
```