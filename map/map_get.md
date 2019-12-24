# map_get

Gets the value associated with a key in a map.

## Syntax

```c
value_type map_get(Map* map, key_type key);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |
| key | key_type | The key of the value to get. |

**Returns:** Gets the value associated with the specified key.

If the key does not exist in the map, it will return a default-initialized value using the following expression: `(value_type){0}`. If you want to make sure the key is actually in the map, use `map_try_get` instead.

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

#define MAP_QUESTION "What is the answer to life?"

SIMap* map = si_map_create();

si_map_add(map, MAP_QUESTION, 42);
int answer = si_map_get(map, MAP_QUESTION);

printf("%s %d\n", MAP_QUESTION, answer);

si_map_free(map);
```