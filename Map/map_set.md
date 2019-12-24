# map_set

Adds or overwrites a key and value to a map.

## Syntax

```c
void map_set(Map* map, key_type key, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |
| key | key_type | The key to set in the map. |
| value | value_type | The value to associate with the key. |

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap* map = si_map_create();

si_map_add(map, "one", 0);

printf("One: %s\n", si_map_get(map, "one"));
puts("Wait a minute...");
puts("That's not right!");
puts("Overwriting...")

// Overwrite the previously added key.
si_map_set(map, "one", 1);
printf("One: %s\n", si_map_get(map, "one"));
puts("That's much better.");

si_map_free(map);

// Output:
// One: 0
// Wait a minute...
// That's not right!
// Overwriting...
// One: 1
// That's much better.
```