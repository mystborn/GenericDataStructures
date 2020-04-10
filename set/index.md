---
layout: default
title: Set
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
<a href="{{site.baseurl}}/deque">Deque</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/deque/deque-capacity">deque_capacity</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-clear">deque_clear</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-count">deque_count</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-create">deque_create</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-create-capacity">deque_create_capacity</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-free">deque_free</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-free-resources">deque_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-init">deque_init</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-init-capacity">deque_init_capacity</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-peek-back">deque_peek_back</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-peek-front">deque_peek_front</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-pop-back">deque_pop_back</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-pop-front">deque_pop_front</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-push-back">deque_push_back</a>
</li>
<li>
<a href="{{site.baseurl}}/deque/deque-push-front">deque_push_front</a>
</li>
</ul>
</li>
<li>
<a href="{{site.baseurl}}/event">Event</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/event/event-create">event_create</a>
</li>
<li>
<a href="{{site.baseurl}}/event/event-free">event_free</a>
</li>
<li>
<a href="{{site.baseurl}}/event/event-free-resources">event_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/event/event-init">event_init</a>
</li>
<li>
<a href="{{site.baseurl}}/event/event-subscribe">event_subscribe</a>
</li>
<li>
<a href="{{site.baseurl}}/event/event-trigger">event_trigger</a>
</li>
<li>
<a href="{{site.baseurl}}/event/event-unsubscribe">event_unsubscribe</a>
</li>
</ul>
</li>
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
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
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
<a href="{{site.baseurl}}/option">Option</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/option/option-default">option_default</a>
</li>
<li>
<a href="{{site.baseurl}}/option/option-has-value">option_has_value</a>
</li>
<li>
<a href="{{site.baseurl}}/option/option-make">option_make</a>
</li>
<li>
<a href="{{site.baseurl}}/option/option-value">option_value</a>
</li>
<li>
<a href="{{site.baseurl}}/option/option-value-or-default">option_value_or_default</a>
</li>
</ul>
</li>
<li>
<a href="{{site.baseurl}}/pool">Pool</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/pool/pool-create">pool_create</a>
</li>
<li>
<a href="{{site.baseurl}}/pool/pool-free">pool_free</a>
</li>
<li>
<a href="{{site.baseurl}}/pool/pool-free-resources">pool_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/pool/pool-get">pool_get</a>
</li>
<li>
<a href="{{site.baseurl}}/pool/pool-init">pool_init</a>
</li>
<li>
<a href="{{site.baseurl}}/pool/pool-release">pool_release</a>
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
<button class="nav-dropdown active"></button>
<ul class="nav-dropdown-container" style="display: block;">
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
<li>
<a href="{{site.baseurl}}/trie">Trie</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map">trie\trie_map</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-add">trie_add</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-children">trie_children</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-children-count">trie_children_count</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-clear">trie_clear</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-count">trie_count</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-create">trie_create</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-free">trie_free</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-free-resources">trie_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-get">trie_get</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-get-and-remove">trie_get_and_remove</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-init">trie_init</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-remove">trie_remove</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-set">trie_set</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-map/trie-try-get">trie_try_get</a>
</li>
</ul>
</li>
<li>
<button class="nav-dropdown">trie\trie_set</button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-add">trie_add</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-children">trie_children</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-children-count">trie_children_count</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-clear">trie_clear</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-contains">trie_contains</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-count">trie_count</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-create">trie_create</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-free">trie_free</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-free-resources">trie_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-init">trie_init</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie/trie-set/trie-remove">trie_remove</a>
</li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</nav>
</div>
<div class="col-md-3"></div>
<div class="col-md-8" markdown="1">

# Set

A [set](https://en.wikipedia.org/wiki/Set_%28mathematics%29) is collection of unique values. It also has some [unique operations](https://en.wikipedia.org/wiki/Set_%28mathematics%29#Basic_operations) for creating new sets from given sets. These values are not sorted in any way, which allows for most operations to be performed quicker.

## Syntax

```c
SET_DEFINE_H(type_name, function_prefix, value_type)
SET_DEFINE_C(type_name, function_prefix, value_type, hash_fn, compare_fn)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the set functions with. |
| value_type | The values held in the set. |
| hash_fn | A function that takes a value and hashes it. |
| compare_fn | A function that compares two values. |

## Remarks

Unlike most of the other collections, if you wish to just use the set header, you must also copy the `generic_hash_utils.h` header as well. It contains some utility functions shared by a couple of the data structures, as well as a string hash function (`gds_fnv32`) so you don't have to write one when using `char*` as the set value.


## Fields

These shouldn't be accessed directly (instead use the corresponding functions. They should be inlined), but they're documented in case they're needed. This data type actually creates two structs. The first one is `<type_name>Cell` where `<type_name>` will be replaced by the name of the set type.

__Cell:__

| Name | Type | Description |
| --- | --- | --- |
| value | value_type | The value held by the cell. |
| hash | uint32_t | The hash value of the cells value. |
| active | bool | Determines if the cell is in use. |

__Map:__

| Name | Type | Description |
| --- | --- | --- |
| cells | SetCell* | An array of cells. |
| count | uint32_t | The number of items in the set. |
| capacity | uint32_t | The number of allocated cells. |
| load_factor | uint32_t | The number of active cells that can be held by the set before resizing. |
| shift | uint32_t | *reserved* |

## Example

The following creates a two sets of numbers, then performs some special operations using them.

```c
#include <generic_set.h>

// The comparison function used by the tree.
static int int_cmp(int left, int right) {
    return left < right ? -1 : (left > right ? 1 : 0); 
}

static uint32_t int_hash(int value) { return (uint32_t)value; }

SET_DEFINE_H(IntSet, int_set, int)
SET_DEFINE_C(IntSet, int_set, int, int_hash, int_cmp)

IntSet* left = int_set_create();
IntSet* right = int_set_create();

// Populate left
for(int i = 0; i < 7; i++)
    int_set_add(left, i);

// Populate right.
for(int i = 3; i < 10; i++)
    int_set_add(right, i);


// Get the union of the two sets (all of the numbers that are in either set)
IntSet* union_result = int_set_create();
int_set_union(left, right, union_result);

for(int i = 0; i < 10; i++) {
    // The union result contains all of these numbers.
    assert(int_set_contains(union_result, i));
}

int_set_free(union_result);

// Get the intersection of the two sets (all of the numbers that are in both sets)

IntSet* intersect = int_set_create();
int_set_intersect(left, right, intersect);

printf("%d\n", int_set_contains(intersect, 0));
printf("%d\n", int_set_contains(intersect, 5));
printf("%d\n", int_set_contains(intersect, 9));

int_set_free(intersect);

// Output:
// 0
// 1
// 0

// Get the complement of the two sets (all of the numbers only in left)
IntSet* complement = int_set_create();
int_set_complement(left, right, complement);

printf("%d\n", 0);
printf("%d\n", 5);
printf("%d\n", 9);

int_set_free(complement);

// Output:
// 1
// 0
// 0
```

### Iterating

There is an extension that allows for iterating over the items in a set in a random order. It's meant to be used like a for loop.

Mod

```c
#include <generic_set.h>
#include <generic_iterators/set_iterator.h>

SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

str_set_add(set, "moo");
str_set_add(set, "caw");
str_set_add(set, "nyan");
str_set_add(set, "woof");

// This will get set by the iterator
char* sound;

set_iter_start(set, sound) {
    printf("%s\n", sound);
}
set_iter_end

string_set_free(set);

// Possible Output:
// caw
// woof
// nyan
// moo
```

The first parameter is the set to iterate over and the second parameter should be a variable with the same type as the values held by the set. It should be safe to nest an iteration block inside of another.

It is not allowed to modify the set at all during iteration.

{% include footer.html %}

</div>
</div>
