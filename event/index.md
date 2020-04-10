---
layout: default
title: Event
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
<button class="nav-dropdown active"></button>
<ul class="nav-dropdown-container" style="display: block;">
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
<a href="{{site.baseurl}}/trie/trie-map">Trie (Map)</a>
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-set">Trie (Set)</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-add">trie_add</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-children">trie_children</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-children-count">trie_children_count</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-clear">trie_clear</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-count">trie_count</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-create">trie_create</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-free">trie_free</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-free-resources">trie_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-get">trie_get</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-get-and-remove">trie_get_and_remove</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-init">trie_init</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-remove">trie_remove</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-map/trie-try-get">trie_try_get</a>
</li>
</ul>
</li>
<li>
<button class="nav-dropdown">Trie (Set)</button>
<ul class="nav-dropdown-container">
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-add">trie_add</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-children">trie_children</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-children-count">trie_children_count</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-clear">trie_clear</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-contains">trie_contains</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-count">trie_count</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-create">trie_create</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-free">trie_free</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-free-resources">trie_free_resources</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-init">trie_init</a>
</li>
<li>
<a href="{{site.baseurl}}/trie/trie-set/trie-remove">trie_remove</a>
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

# Event

An event is a type used to implement the [observer pattern](https://en.wikipedia.org/wiki/Observer_pattern). It is similar to events in the C# language. Functions can [subscribe]({{site.baseurl}}/event/event-subscribe) to an event. When the event is [triggered]({{site.baseurl}}/event/event-trigger), those functions will be called. 

There is a strongly-typed version that uses macros similar to c++ templates, but there is also a weakly-typed implementation. In order to use the weakly-typed version, in one source file you __must__ define `GENERIC_EVENT_IMPLEMENTATION` before including the `generic_event.h` header.

## Syntax

```c
EVENT_DEFINE_<arg_count>_H(type_name, function_prefix, ...)
EVENT_DEFINE_C(type_name, function_prefix)
```

Here `<arg_count>` should be replaced with the number of arguments that the event will have. This implementation only supports 0-10 arguments.

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the generated functions with. |
| ... | If `arg_count` is greater than zero, the types of the arguments used to trigger the event. |

For example, an event that takes in one string argument would be defined like so:

```c
EVENT_DEFINE_1_H(StringEvent, str_event, char*)
EVENT_DEFINE_C(StringEvent, str_event)
```

## Remarks

All functions that will be subscribed to an event, whether it's strongly-typed or not, should have a `void*` as its first argument. This will be the context used to subscribe the function to the event. This does not count as one of the arguments when counting for `<arg_count>`. For example, a function that would be subscribed to the StringEvent defined above would have the following signature:

```c
void some_function(void* ctx, char* string_value);
```

## Fields

These generally shouldn't be accessed directly, but they're documented just in case they're needed. This data type defines an additional struct and a function typedef. They are `<type_name>Subscription` and `void <type_name>Delegate(void*, ...)` respectively. `<type_name>` will be replaced with the event type name.

__EventSubscription:__

| Name | Type | Description |
| --- | --- | --- |
| data | void* | The context passed to the function when the event is triggered. |
| function | EventDelegate | The function to call when the event is triggered. |

__Event:__

| Name | Type | Description |
| --- | --- | --- |
| subscriptions | EventSubscription* | A list of the functions subscribed to the event. |
| count | unsigned int | The number of subscriptions. |
| capacity | unsigned int | The number of subscriptions that can be added to the event before resizing. |

## Example

```c
#include <generic_event.h>

EVENT_DEFINE_1_H(StringEvent, str_event, char*)
EVENT_DEFINE_C(StringEvent, str_event)

static void print_string(void* ctx, char* str) {
    puts(str);
}

static void print_context_and_string(void* ctx, char* str) {
    printf("%s%s\n", (char*)ctx, str);
}

StringEvent* event = str_event_create();

char* context = "Hello ";

str_event_subscribe(event, NULL, print_string);
str_event_subscribe(event, context, print_context_and_string);

str_event_trigger(event, "World");

str_event_unsubscribe(event, context, print_context_and_string);

str_event_trigger(event, "String all alone");

str_event_free(event);

// Output:
// World
// Hello World
// String all alone
```

{% include footer.html %}

</div>
</div>
