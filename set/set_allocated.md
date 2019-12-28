# set_allocated

Gets the number of allocated elements in the sets internal buffer.

## Syntax

```c
uint32_t set_allocated(Set* map);
```

| Name | Type | Description |
| --- | --- | --- |
| set | Set* | A pointer to the map. |

## Remarks

This is not the same as the number of elements a set can hold without resizing (for that, check out [set_capacity]({{site.baseurl/set/set-capacity}})). Rather this is the number of cells allocated for the set. To get the number of total bytes, use the expression `sizeof(<TypeName>Cell) * set_allocated(set)`.

Generally this function is used to determine if you want to reset the capacity when using [set_clear]({{site.baseurl}}/set/set-clear).

## Example

```c
SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

uint32_t cells = str_set_allocated(set);

printf("# of Cells: %u\n", cells);
printf("# of Bytes: %u\n", sizeof(StringSetCell) * cells);

str_set_free(set);

// The output depends on the size of various elements +
// struct padding, so assume sizeof(StringSetCell) is 16.

// Output:
// # of Cells: 8
// # of Bytes: 128
```