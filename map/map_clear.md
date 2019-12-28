# map_clear

Clears all elements from the map.

## Syntax

```c
void map_clear(Map* map, bool reset_capacity);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |
| reset_capacity | bool | Determines whether to reset the internal size of the map or leave it as is. |

## Remarks

Resetting the capacity of the map can create more space for the application, but leaving it as is will make it faster (no need to resize, less likely hash collisions).

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap* map = si_map_create();

si_map_add(map, "one", 1);
si_map_add(map, "two", 2);
si_map_add(map, "three", 3);

// Clears the values in the map without resetting it's internal storage.
si_map_clear(map, false);
```