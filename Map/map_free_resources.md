# map_free_resources

Frees the resources used by a map without freeing the map itself.

## Syntax

```c
void map_free_resources(Map* map);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap map;

if(!si_map_init(&map)) {
    puts("Map failed to initialize.");
    return;
}

// Use the map...

si_map_free_resources(&map);
```