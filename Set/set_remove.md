# set_remove

Attempts to remove a value from a set.

## Syntax

```c
bool set_remove(Set* set, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| set | Set* | A pointer to the set. |
| value | value_type | The value to remove. |

**Returns:** `true` if the value was removed, `false` if the value wasn't found.

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

str_set_add(set, "owl");
printf("Set contains owl? %s\n", str_set_contains(set, "owl") ? "True" : "False");

str_set_remove(set, "owl");
printf("Set contains owl? %s\n", str_set_contains(set, "owl") ? "True" : "False");

str_set_free(set);

// Output:
// Set contains owl? True
// Set contains owl? False
```