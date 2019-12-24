# map_init

Initializes a map.

## Syntax

```c
bool map_init(Map* map);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |

**Returns:** `true` if the map was initialized, `false` if there was an allocation error.

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap map;
si_map_init(&map);

// Use the map...

si_map_free_resources(&map);
```