---
tags: c map dictionary
---
# map_remove

Removes a key and it's associated value from a map.

## Syntax

```c
bool map_remove(Map* map, key_type key);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |
| key | key_type | The key to remove from the map. |

**Returns:** `true` if the value was found and removed, `false` if the value wasn't found.

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap* map = si_map_create();

si_map_add(map, "one", 1);

if(si_map_remove(map, "zero"))
    puts("Removed zero from the map");
else
    puts("Didn't remove zero from the map");

if(si_map_remove(map, "one"))
    puts("Removed one from the map");
else
    puts("Didn't remove one from the map");

si_map_free(map);

// Output:
// Didn't remove zero from the map
// Removed one from the map
```