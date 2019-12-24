# map_get_and_remove

Gets the actual key and values from the specified key within the map, then removes the key.

By "actual key and value", it means the value that was initially added to the map. This function was created to allow users to get dynamically allocated keys from the map when they were done if the compare function compared on data or members instead of the memory address. I imagine the most common use case for this function will be to free dynamically allocated strings that are retrieved using a string literal. You can see what I mean in the example section.

## Syntax

```c
bool map_get_and_remove(Map* map, key_type key, key_type* out_key, value_type* out_value);
```

| Name | Type | Description |
| --- | --- | --- |
| map | Map* | A pointer to the map. |
| key | key_type | The key to remove from the map. |
| out_key | key_type* | A pointer to fill with the key that was initially added to the map. |
| out_value | value_type* | A pointer to fill with the value that was associated with the key. |

**Returns:** `true` if the key was found and removed, `false` if the key was not found.

## Remarks

If you only need to get the key or the value, you can use `NULL` for the unwanted value.

## Example

```c
// This example uses a complete program because it is more
// complicated to illustrate.

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <generic_map.h>

MAP_DEFINE_H(SIMap, si_map, char*, int)
MAP_DEFINE_C(SIMap, si_map, char*, int, gds_fnv32, strcmp)

int main(void) {
    SIMap* map = si_map_create();
    
    // Allocate and initialize the key to add to the map.
    char* dynamic_key = malloc(sizeof(char) * 6);
    memcpy(dynamic_key, "hello", 5);

    // Make sure the key is terminated properly.
    dynamic_key[5] = 0;

    si_map_add(map, dynamic_key, strlen(dynamic_key));

    // Next we'll get the value using a string literal.
    int length = si_map_get(map, "hello");

    printf("The length of the key is: %d\n", length);

    // Next we need to clean up our resources.
    // Obviously here we still have the original reference to the dynamically
    // allocated string, but there are many scenarios where that variable is
    // long gone. To simulate those scenarios, dynamic_key will be NULLed out.

    dynamic_key = NULL;

    // Now we still need to free the key somehow. That's where
    // map_get_and_remove comes in handy.

    // We don't need our value, so we'll just pass in NULL for the
    // out_value parameter.

    char* out_key;
    if(si_map_get_and_remove(map, "hello", &out_key, NULL)) {
        // As long as the key was found, clean it up.
        free(out_key);
    }

    // Finally, we free the map.
    si_map_free(map);

    return 0;
}
```