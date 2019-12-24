# set_complement

Gets the [complement](https://en.wikipedia.org/wiki/Set_%28mathematics%29#Intersections) of two sets.

## Syntax

```c
bool set_complement(Set* left, Set* right, Set* result);
```

| Name | Type | Description |
| --- | --- | --- |
| left | Set* | A pointer to the left set. |
| right | Set* | A pointer to the right set. |
| result | Set* | A pointer to the result set. |

**Returns:** `true` if none of the sets were `NULL`, false otherwise.

## Remarks

This function gets the complement of the left and right sets and stores the values in the result set. The result set __cannot__ be the same as the left or right sets.

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* left = str_set_create();
StringSet* right = str_set_create();
StringSet* result = str_set_create();

str_set_add(left, "moo");
str_set_add(left, "nyan");
str_set_add(right, "caw");
str_set_add(right, "nyan");

str_set_complement(left, right, result);

printf("%d\n", str_set_contains(result, "moo"));
printf("%d\n", str_set_contains(result, "caw"));
printf("%d\n", str_set_contains(result, "nyan"));

// Output:
// 1
// 0
// 0
```