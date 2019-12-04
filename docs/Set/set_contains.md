---
tags: c set
---
# set_contains

Determines if a set contains the specified value.

## Syntax

```c
bool set_contains(Set* set, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| set | Set* | A pointer to the set. |
| value | value_type | The value to check for inclusion in the set. |

**Returns:** `true` if the set contains the value, `false` otherwise.

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

str_set_add(set, "owl");
str_set_add(set, "cow");

bool success = str_set_contains(set, "owl");
printf("Set contains owl? %s\n", success ? "True" : "False");

success = str_set_contains(set, "raven");
printf("Set contains raven? %s\n", success ? "True" : "False");

str_set_free(set);

// Output:
// Set contains owl? True
// Set contains raven? False
```