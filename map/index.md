---
layout: default
title: Map
---
<div class="row">
<div class="col-md-3 side-nav text-light">
<nav class="navbar-dark">
<div class="d-inline-flex justify-content-between justify-content-md-center align-items-center w-100 py-2">
<b><a href="{{site.baseurl}}/">Generic Data Structures</a></b>
<button class="side-nav-button" type="button" data-toggle="collapse" data-target="#sidenav-container">
<span class="side-nav-button-image"></span>
</button>
</div>
<div class="collapse" id="sidenav-container">
<div class="d-flex justify-content-center">
<input class="form - control" type="text" name="search" id="search" placeholder="Search..." aria-label="Search">
</div>
<ul id="search-results" style="display: hidden;"></ul>
<ul id="nav-items">
<li>
<a href="{{site.baseurl}}/grid">Grid</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/grid/grid-clear">grid_clear</a>
</li>
<li>
<a href="{{site.baseurl}}/grid/grid-create">grid_create</a>
</li>
<li>
<a href="{{site.baseurl}}/grid/grid-free">grid_free</a>
</li>
<li>
<a href="{{site.baseurl}}/grid/grid-free-resources">grid_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/grid/grid-get">grid_get</a>
</li>
<li>
<a href="{{site.baseurl}}/grid/grid-height">grid_height</a>
</li>
<li>
<a href="{{site.baseurl}}/grid/grid-init">grid_init</a>
</li>
<li>
<a href="{{site.baseurl}}/grid/grid-set">grid_set</a>
</li>
<li>
<a href="{{site.baseurl}}/grid/grid-width">grid_width</a>
</li>
</ul>
</li>
<li>
<a href="{{site.baseurl}}/list">List</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/list/list-add">list_add</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-clear">list_clear</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-count">list_count</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-create">list_create</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-free">list_free</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-free-resources">list_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-get">list_get</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-init">list_init</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-init-capacity">list_init_capacity</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-insert">list_insert</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-peek">list_peek</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-pop">list_pop</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-remove">list_remove</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-set">list_set</a>
</li>
<li>
<a href="{{site.baseurl}}/list/list-shrink-to-fit">list_shrink_to_fit</a>
</li>
</ul>
</li>
<li>
<a href="{{site.baseurl}}/map">Map</a>
<button class="nav-dropdown active"></button>
<ul class="nav-dropdown-container" style="display: block;">
<li>
<a href="{{site.baseurl}}/map/map-add">map_add</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-allocated">map_allocated</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-capacity">map_capacity</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-clear">map_clear</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-count">map_count</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-create">map_create</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-free">map_free</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-free-resources">map_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-get">map_get</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-get-and-remove">map_get_and_remove</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-init">map_init</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-remove">map_remove</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-set">map_set</a>
</li>
<li>
<a href="{{site.baseurl}}/map/map-try-get">map_try_get</a>
</li>
</ul>
</li>
<li>
<a href="{{site.baseurl}}/queue">Queue</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/queue/queue-clear">queue_clear</a>
</li>
<li>
<a href="{{site.baseurl}}/queue/queue-count">queue_count</a>
</li>
<li>
<a href="{{site.baseurl}}/queue/queue-create">queue_create</a>
</li>
<li>
<a href="{{site.baseurl}}/queue/queue-create-capacity">queue_create_capacity</a>
</li>
<li>
<a href="{{site.baseurl}}/queue/queue-dequeue">queue_dequeue</a>
</li>
<li>
<a href="{{site.baseurl}}/queue/queue-enqueue">queue_enqueue</a>
</li>
<li>
<a href="{{site.baseurl}}/queue/queue-free">queue_free</a>
</li>
<li>
<a href="{{site.baseurl}}/queue/queue-free-resources">queue_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/queue/queue-init">queue_init</a>
</li>
<li>
<a href="{{site.baseurl}}/queue/queue-init-capacity">queue_init_capacity</a>
</li>
<li>
<a href="{{site.baseurl}}/queue/queue-peek">queue_peek</a>
</li>
</ul>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree">Red Black Tree</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-add">rbtree_add</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-add-node">rbtree_add_node</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-count">rbtree_count</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-create">rbtree_create</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-free">rbtree_free</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-free-resources">rbtree_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-get">rbtree_get</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-get-max">rbtree_get_max</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-get-min">rbtree_get_min</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-get-node">rbtree_get_node</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-init">rbtree_init</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-remove">rbtree_remove</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-remove-max">rbtree_remove_max</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-remove-max-node">rbtree_remove_max_node</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-remove-min">rbtree_remove_min</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-remove-min-node">rbtree_remove_min_node</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-remove-node">rbtree_remove_node</a>
</li>
<li>
<a href="{{site.baseurl}}/redblacktree/rbtree-root">rbtree_root</a>
</li>
</ul>
</li>
<li>
<a href="{{site.baseurl}}/set">Set</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/set/set-add">set_add</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-allocated">set_allocated</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-capacity">set_capacity</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-clear">set_clear</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-complement">set_complement</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-contains">set_contains</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-count">set_count</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-create">set_create</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-free">set_free</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-free-resources">set_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-get">set_get</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-get-and-remove">set_get_and_remove</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-init">set_init</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-intersect">set_intersect</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-is-superset">set_is_superset</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-remove">set_remove</a>
</li>
<li>
<a href="{{site.baseurl}}/set/set-union">set_union</a>
</li>
</ul>
</li>
</ul>
</div>
</nav>
</div>
<div class="col-md-3"></div>
<div class="col-md-8" markdown="1">

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
| cells | MapCell* | An array of cells. |
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

{% include footer.html %}

</div>
</div>
