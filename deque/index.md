---
layout: default
title: Deque
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
<button class="nav-dropdown active"></button>
<ul class="nav-dropdown-container" style="display: block;">
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

# Deque

A [deque (double ended queue)](https://en.wikipedia.org/wiki/Double-ended_queue) is a collection that can efficiently add or remove items from both the start and the end of it.

## Syntax

```c
DEQUE_DEFINE_H(type_name, function_prefix, value_type)
DEQUE_DEFINE_C(type_name, function_prefix, value_type)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the deque functions with. |
| value_type | The value to be held by the deque. |

## Fields

The fields of this type generally should not be modified directly. If you need to iterate over the deque, please use the `generic_iterators/deque_iterator.h` header instead of doing it manually.

| Name | Type | Description |
| --- | --- | --- |
| buffer | value_type* | The backing array of the deque. These are not necessarily in the order that the items were added. |
| count | unsigned int | The number of items in the deque. |
| capacity | unsigned int | The number of items the deque can potentially hold without resizing. |
| start | unsigned int | *reserved* |
| end | unsigned int | *reserved* |

## Example

```c
#include <stdio.h>

#include <generic_deque.h>

DEQUE_DEFINE_H(StringDeque, str_deque, char*)
DEQUE_DEFINE_C(StringDeque, str_deque, char*)

StringDeque* deque = str_deque_create();

str_deque_push_back("world!");

str_deque_push_front(" ");
str_deque_push_front("Hello");

printf("Count: %d\n", str_deque_count(deque));
printf("Front: %s\n", str_deque_peek_front(deque));
printf("Back: %s\n", str_deque_peek_back(deque));

while(str_deque_count(deque) > 0) {
    printf("%s", str_deque_pop_front(deque));
}

printf("Count: %d\n", str_deque_count(deque));

str_deque_free(deque);

// Output:
// Count: 3
// Front: Hello
// Back: world!
// Hello world!
// Count: 0
```

### Iterating

There is an extension that allows iterating over all of the values in the deque from front to back. This will not remove any of the values.

```c
#include <stdio.h>

#include <generic_deque.h>

// The extension is located here.
#include <generic_iterators/deque_iterator.h>

DEQUE_DEFINE_H(StringDeque, str_deque, char*)
DEQUE_DEFINE_C(StringDeque, str_deque, char*)

StringDeque* deque = str_deque_create();

str_deque_push_back(deque, "three");
str_deque_push_back(deque, "four");

str_deque_push_front(deque, "two");
str_deque_push_front(deque, "one");

// This will be set by the loop.
char* value;


// Start the iteration
deque_iter_start(deque, value) {
    printf("%s\n", value);
}
deque_iter_end // End the iteration

str_deque_free(deque);

// Output:
// one
// two
// three
// four
```

Just like with the other iterators, you can use `break` and `continue` like you would with any c loop.

{% include footer.html %}

</div>
</div>
