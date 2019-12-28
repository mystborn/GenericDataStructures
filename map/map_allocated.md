# map_allocated

Gets the number of allocated elements in the maps internal buffer.

## Syntax

```c
uint32_t map_allocated(Map* map);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |

## Remarks

This is not the same as the number of elements a map can hold without resizing (for that, check out [map_capacity]({{site.baseurl/map/map_capacity}})). Rather this is the number of cells allocated for the map. To get the number of total bytes, use the expression `sizeof(<TypeName>Cell) * map_allocated(map)`.

Generally this function is used to determine if you want to reset the capacity when using [map_clear]({{site.baseurl}}/map/map_clear).

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap* map = si_map_create();

uint32_t cells = si_map_allocated(map);

printf("# of Cells: %u\n", cells);
printf("# of Bytes: %u\n", sizeof(SIMapCell) * cells);

si_map_free(map);

// The output depends on the size of various elements +
// struct padding, so assume sizeof(SIMapCell) is 24.

// Output:
// # of Cells: 8
// # of Bytes: 192
```