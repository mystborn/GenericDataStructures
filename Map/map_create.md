# map_create

Allocates and initializes a new map.

## Syntax

```c
Map* map_create(void);
```

**Returns:** A new map if the operation was successful, `NULL` if there was an allocation failure.

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap* map = si_map_create();

if(map == NULL) {
    puts("Map failed to initialize");
    return;
}

// Use the map...

si_map_free(map);
```