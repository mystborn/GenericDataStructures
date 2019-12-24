# map_free

Frees the resources used by a map, then frees the map itself.

## Syntax

```c
void map_free(Map* map);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap* map = si_map_create();

// Use the map...

si_map_free(map);
```