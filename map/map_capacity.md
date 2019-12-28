# map_capacity

Gets the number of elements a map can hold without resizing.

## Syntax

```c
uint32_t map_capacity(Map* map);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |

## Remarks

This is not the same as the allocated size of the maps internal buffer. To get that, see [map_allocated]({{site.baseurl}}/map/map_allocated).

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap* map = si_map_create();

uint32_t capacity = si_map_capacity(map);

printf("Capacity: %u\n", capacity);

si_map_free(map);

// Output:
// Capacity: 4
```