# Map

A map is a collection that associates a key to a value. In other words, it uses the key to find a value. It's sometimes called a dictionary, because a dictionary associates a word (key) to a definition (value). This collection is similar to the `unordered_map` in c++ or `Dictionary<K, V>` in C#.

## Syntax

```c
MAP_DEFINE_H(type_name, function_prefix, key_type, value_type)
MAP_DEFINE_C(type_name, function_prefix, key_type, value_type, hash_fn, compare_fn)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the map functions with. |
| key_type | The key of the association. |
| value_type | The value of the association. |
| hash_fn | A function that takes a key and hashes it. |
| compare_fn | A function that compares two keys. |

The function parameters should have the following signatures:

```c
uint32_t hash_fn(key_type key)

int compare_fn(key_type left, key_type right)
``` 

The compare function should return -1 if left < right. It should return 1 if left > right. It should return 0 if the two keys are determined to be equal.

## Remarks

Unlike most of the other collections, if you wish to just use the map header, you must also copy the `generic_hash_utils.h` header as well. It contains some utility functions shared by a couple of the data structures, as well as a string hash function (`gds_fnv32`) so you don't have to write one when using `char*` as the map key.

## Fields

These shouldn't be accessed directly (instead use the corresponding functions. They should be inlined), but they're documented in case they're needed. This data type actually creates two structs. The first one is `<type_name>Cell` where `<type_name>` will be replaced by the name of the map type.

__Cell:__

| Name | Type | Description |
| --- | --- | --- |
| key | key_type | The key held by the cell. |
| value | value_type | The value held by the cell. |
| hash | uint32_t | The hash value of the key. |
| active | bool | Determines if the cell is in use. |

__Map:__

| Name | Type | Description |
| --- | --- | --- |
| cells | &lt;type_name&gt;Cell* | An array of cells. |
| count | uint32_t | The number of items in the map. |
| capacity | uint32_t | The number of allocated cells. |
| load_factor | uint32_t | The number of active cells that can be held by the map before resizing. |
| shift | uint32_t | *reserved* |

## Example

The following creates a dictionary that associates number words with their literal value, then corrects a few mistakes during the initial construction.

```c
#include <stdlib.h>
#include <string.h>

#include <generic_map.h>

MAP_DEFINE_H(NumberMap, num_map, char*, int)

// gds_fnv32 is a hash function for strings that is included with this library. 
MAP_DEFINE_C(NumberMap, num_map, char*, int, gds_fnv32, strcmp)

int main(void) {
    NumberMap* map = num_map_create();

    // Make sure the map allocated properly.
    if(map == NULL) {
        puts("Map failed to initialize");
        return EXIT_FAILURE;
    }

    // Add correct pairs to the map.
    num_map_add(map, "zero", 0);
    num_map_add(map, "one", 1);

    // Add incorrect pairs to the map.
    num_map_add(map, "two", 22);
    num_map_add(map, "NaN", 0);

    // Get the literal for one.
    int one = num_map_get(map, "one");

    // Fix the mistake made with two by overriding the previous value.
    num_map_set(map, "two", 2);

    // Fix the mistake made with NaN by removing it completely.
    num_map_remove(map, "NaN");

    // Free the memory
    num_map_free(map);

    return EXIT_SUCCESS;
}
```

### Iterating

There are a couple of extensions for iterating over the items in a map. One iterates over the keys, one over the values, and finally one iterates over both the keys and values together. They always iterate in a random order. The extensions are meant to be used like a for loop.

In the following, we create a map that associates first names to last names, the iterates over them in all of the possible ways.

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <generic_map.h>
#include <generic_iterators/map_iterator.h>

MAP_DEFINE_H(NameMap, name_map, char*, char*)
MAP_DEFINE_C(NameMap, name_map, char*, char*, gds_fnv32, strcmp)

// The number of names that we use.
#define NAME_COUNT 3

// Here we define the names themselves. I was listening to Hamilton.
char* names[NAME_COUNT][2] = { { "George", "Washington" }, { "Alexander", "Hamilton" }, { "Aaron", "Burr" } };

int main(void) {
    NameMap* map = name_map_create();

    for(int i = 0; i < NAME_COUNT; i++) {
        // Add the names to the map.
        name_map_add(map, names[i][0], names[i][1]);
    }

    // These will be set by the loops.
    char* first_name, last_name;

    // We start by getting both the key and value from the map.
    puts("Full Names:");

    map_iter_start(map, first_name, last_name) {
        printf("%s %s\n", first_name, last_name);
    }
    map_iter_end

    printf("\n");

    // Then we just get the key.
    puts("First Names:");

    map_iter_key_start(map, first_name) {
        puts(first_name);
    }
    map_iter_end

    printf("\n");

    // Finally we just get the value.
    puts("Last Names:");

    map_iter_value_start(map, last_name) {
        puts(last_name);
    }
    map_iter_end

    name_map_free(map);
    return EXIT_SUCCESS;
}

// The output won't necessarily be the same every time, it depends on your hash function.
// This is one possible output.

// Output:
// Full Names:
// Alexander Hamilton
// Aaron Burr
// George Washington
// 
// First Names:
// Full Names:
// Alexander
// Aaron
// George
//
// Last Names:
// Full Names:
// Hamilton
// Burr
// Washington
```

It is safe to nest an iteration block inside of another.

Is it __not__ safe to add or remove items from a map while iterating. It is undefined behaviour.