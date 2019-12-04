---
tags: c map dictionary
---
# map_count

Gets the number of items in a map.

## Syntax

```c
uint32_t map_count(Map* map);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |

**Returns:** The number of items in the map.

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap* map = si_map_create();

si_map_add(map, "one", 1);
si_map_add(map, "zero", 0);

uint32_t count = si_map_count(map);
assert(count == 2);

si_map_free(map);
```