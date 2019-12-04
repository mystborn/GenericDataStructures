---
tags: c set
---
# set_add

Attempts to add an item to the set.

## Syntax

```c
bool set_add(Set* set, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| set | Set* | A pointer to the set. |
| value | value_type | The value to add to the set.

**Returns:** `true` if the item was successfully added, `false` if the set already contained the item.

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

bool added = str_set_add("owl");
printf("Added? %s\n", added ? "True" : "False");

bool added = str_set_add("owl");
printf("Added? %s\n", added ? "True" : "False");

str_set_free(set);

// Output:
// Added? True
// Added? False
```