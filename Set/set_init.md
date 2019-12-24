# set_init

Initializes an existing set.

## Syntax

```c
bool set_init(Set* set);
```

| Name | Type | Description |
| --- | --- | --- |
| set | Set* | A pointer to the set. |

**Returns:** `true` on success, `false` on allocation failure.

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet set;
str_set_init(&set);

// Use the set...

str_set_free_resources(&set);
```