# map_add

Attempts to add a key and value to a map.

## Syntax

```c
bool map_add(Map* map, key_type key, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |
| key | key_type | The key to add to the map. |
| value | value_type | The value to associate with the key. |

**Returns:** `true` if the key was added to the map, `false` if the key already existed in the map.

If you want to replace an existing value or make sure the value is added no matter what use map_set instead.

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap* map = si_map_create();

bool result = si_map_add(map, "one", 1);
printf("Added? %s\n", result ? "True" : "False");

result = si_map_add(map, "one", 0);
printf("Added? %s\n", result ? "True" : "False");

int one = si_map_get(map, "one");
printf("One: %d\n", one);

// Output:
// Added? True
// Added? False
// One: 1
```