# set_is_superset

Determines if one set is the [superset](https://en.wikipedia.org/wiki/Set_%28mathematics%29#Subsets) of another.

## Syntax

```c
bool set_is_superset(Set* superset, Set* subset);
```

| Name | Type | Description |
| --- | --- | --- |
| superset | Set* | A pointer to the set to determine is a superset. |
| subset | Set* | A pointer to the set to determine is a subset. |

**Returns:** `true` if superset contains subset, `false` if one of the parameters is `NULL` or superset does not conain subset.

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* left = str_set_create();
StringSet* right = str_set_create();

str_set_add(left, "nyan");
str_set_add(right, "caw");
str_set_add(right, "nyan");

// Left is not a superset of right...
printf("%d\n", str_set_is_superset(left, right));

// but right is a superset of left.
printf("%d\n", str_set_is_superset(right, left));

// Output:
// 0
// 1
```