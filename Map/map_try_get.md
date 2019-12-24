# map_try_get

Attempts to get the value associated with the specified key in a map.

## Syntax

```c
bool map_try_get(Map* map, key_type key, value_type* out_value);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |
| key | key_type | The key of the value to get. |
| out_value | value_type* | A pointer to be filled with the value if the key is found. |

**Returns:** `true` if the key was found, `false` otherwise.

## Remarks

The out_value will only be assigned to if it's not NULL. Therefore, if you just need to check if the key exists in the map, you can use this function and just pass NULL for the last parameter.

## Example

```c
MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

SIMap* map = si_map_create();

si_map_add(map, "zero", 0);
si_map_add(map, "one", 1);

if(si_map_get(map, "zero", NULL))
    puts("Map had zero in it.");
else
    puts("Map did not have zero in it.");

if(si_map_try_get(map, "two", NULL))
    puts("Map had two in it.");
else
    puts("Map did not have two in it.");

int out_value;
if(si_map_try_get(map, "one", &out_value))
    printf("The value of one is %d.\n", out_value);

// Output:
// Map had zero in it.
// Map did not have two in it.
// The value of one is 1.
```