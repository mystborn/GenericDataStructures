---
layout: default
title: map_try_get
---
<div class="row">
<div class="col-md-3 side-nav text-light">
<nav class="navbar-dark">
<div class="d-inline-flex justify-content-between justify-content-md-center align-items-center w-100 py-2">
<b><a href="{{site.url}}/">Generic Data Structures</a></b>
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
<a href="{{site.url}}/grid">Grid</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.url}}/grid/grid-clear">grid_clear</a>
</li>
<li>
<a href="{{site.url}}/grid/grid-create">grid_create</a>
</li>
<li>
<a href="{{site.url}}/grid/grid-free">grid_free</a>
</li>
<li>
<a href="{{site.url}}/grid/grid-free-resources">grid_free_resources</a>
</li>
<li>
<a href="{{site.url}}/grid/grid-get">grid_get</a>
</li>
<li>
<a href="{{site.url}}/grid/grid-height">grid_height</a>
</li>
<li>
<a href="{{site.url}}/grid/grid-init">grid_init</a>
</li>
<li>
<a href="{{site.url}}/grid/grid-set">grid_set</a>
</li>
<li>
<a href="{{site.url}}/grid/grid-width">grid_width</a>
</li>
</ul>
</li>
<li>
<a href="{{site.url}}/list">List</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.url}}/list/list-add">list_add</a>
</li>
<li>
<a href="{{site.url}}/list/list-clear">list_clear</a>
</li>
<li>
<a href="{{site.url}}/list/list-count">list_count</a>
</li>
<li>
<a href="{{site.url}}/list/list-create">list_create</a>
</li>
<li>
<a href="{{site.url}}/list/list-free">list_free</a>
</li>
<li>
<a href="{{site.url}}/list/list-free-resources">list_free_resources</a>
</li>
<li>
<a href="{{site.url}}/list/list-get">list_get</a>
</li>
<li>
<a href="{{site.url}}/list/list-init">list_init</a>
</li>
<li>
<a href="{{site.url}}/list/list-init-capacity">list_init_capacity</a>
</li>
<li>
<a href="{{site.url}}/list/list-insert">list_insert</a>
</li>
<li>
<a href="{{site.url}}/list/list-peek">list_peek</a>
</li>
<li>
<a href="{{site.url}}/list/list-pop">list_pop</a>
</li>
<li>
<a href="{{site.url}}/list/list-remove">list_remove</a>
</li>
<li>
<a href="{{site.url}}/list/list-set">list_set</a>
</li>
<li>
<a href="{{site.url}}/list/list-shrink-to-fit">list_shrink_to_fit</a>
</li>
</ul>
</li>
<li>
<a href="{{site.url}}/map">Map</a>
<button class="nav-dropdown active"></button>
<ul class="nav-dropdown-container" style="display: block;">
<li>
<a href="{{site.url}}/map/map-add">map_add</a>
</li>
<li>
<a href="{{site.url}}/map/map-count">map_count</a>
</li>
<li>
<a href="{{site.url}}/map/map-create">map_create</a>
</li>
<li>
<a href="{{site.url}}/map/map-free">map_free</a>
</li>
<li>
<a href="{{site.url}}/map/map-free-resources">map_free_resources</a>
</li>
<li>
<a href="{{site.url}}/map/map-get">map_get</a>
</li>
<li>
<a href="{{site.url}}/map/map-get-and-remove">map_get_and_remove</a>
</li>
<li>
<a href="{{site.url}}/map/map-init">map_init</a>
</li>
<li>
<a href="{{site.url}}/map/map-remove">map_remove</a>
</li>
<li>
<a href="{{site.url}}/map/map-set">map_set</a>
</li>
<li>
<a href="{{site.url}}/map/map-try-get">map_try_get</a>
</li>
</ul>
</li>
<li>
<a href="{{site.url}}/queue">Queue</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.url}}/queue/queue-clear">queue_clear</a>
</li>
<li>
<a href="{{site.url}}/queue/queue-count">queue_count</a>
</li>
<li>
<a href="{{site.url}}/queue/queue-create">queue_create</a>
</li>
<li>
<a href="{{site.url}}/queue/queue-create-capacity">queue_create_capacity</a>
</li>
<li>
<a href="{{site.url}}/queue/queue-dequeue">queue_dequeue</a>
</li>
<li>
<a href="{{site.url}}/queue/queue-enqueue">queue_enqueue</a>
</li>
<li>
<a href="{{site.url}}/queue/queue-free">queue_free</a>
</li>
<li>
<a href="{{site.url}}/queue/queue-free-resources">queue_free_resources</a>
</li>
<li>
<a href="{{site.url}}/queue/queue-init">queue_init</a>
</li>
<li>
<a href="{{site.url}}/queue/queue-init-capacity">queue_init_capacity</a>
</li>
<li>
<a href="{{site.url}}/queue/queue-peek">queue_peek</a>
</li>
</ul>
</li>
<li>
<a href="{{site.url}}/redblacktree">RedBlackTree</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.url}}/redblacktree/rbtree-add">rbtree_add</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-add-node">rbtree_add_node</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-count">rbtree_count</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-create">rbtree_create</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-free">rbtree_free</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-free-resources">rbtree_free_resources</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-get">rbtree_get</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-get-max">rbtree_get_max</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-get-min">rbtree_get_min</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-get-node">rbtree_get_node</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-init">rbtree_init</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-remove">rbtree_remove</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-remove-max">rbtree_remove_max</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-remove-max-node">rbtree_remove_max_node</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-remove-min">rbtree_remove_min</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-remove-min-node">rbtree_remove_min_node</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-remove-node">rbtree_remove_node</a>
</li>
<li>
<a href="{{site.url}}/redblacktree/rbtree-root">rbtree_root</a>
</li>
</ul>
</li>
<li>
<a href="{{site.url}}/set">Set</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.url}}/set/set-add">set_add</a>
</li>
<li>
<a href="{{site.url}}/set/set-contains">set_contains</a>
</li>
<li>
<a href="{{site.url}}/set/set-count">set_count</a>
</li>
<li>
<a href="{{site.url}}/set/set-create">set_create</a>
</li>
<li>
<a href="{{site.url}}/set/set-free">set_free</a>
</li>
<li>
<a href="{{site.url}}/set/set-free-resources">set_free_resources</a>
</li>
<li>
<a href="{{site.url}}/set/set-get">set_get</a>
</li>
<li>
<a href="{{site.url}}/set/set-get-and-remove">set_get_and_remove</a>
</li>
<li>
<a href="{{site.url}}/set/set-init">set_init</a>
</li>
<li>
<a href="{{site.url}}/set/set-remove">set_remove</a>
</li>
</ul>
</li>
</ul>
</div>
</nav>
</div>
<div class="col-md-3"></div>
<div class="col-md-8" markdown="1">

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

<div class="py-2 border-top">
<div class="col-sm">
<ul class="list-inline">
<li class="list-inline-item">
&copy; 2019 Precisamento LLC
</li>
<li class="list-inline-item">
<a class="footer-link" href="https://github.com/mystborn">Github</a>
</li>
<li class="list-inline-item">
<a class="footer-link" href="mailto:precisamento@gmail.com">Email</a>
</li>
</ul>
</div>
</div>
</div>
</div>