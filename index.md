---
layout: default
title: Home
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

# Generic Data Structures

GenericDataStructures is a set of C header files that contain macros which generate strongly typed data structures in a fashion similar to C++ templates. Each data structure has two macros to generate the type: `<TYPE>\_DEFINE\_H` and `<TYPE>\_DEFINE_C` where `<TYPE>` corresponds to the data structure name. The first macro can can go in a header file if the functions are used across multiple compilation units. The second should only be used in a source file. If you only need the collection in one location, both macros can be in the same file, as long as the `\_H` one is placed first.

Those macros will generate a type and any functions needed to use the type. Each macro takes the desired type name as its first argument, then takes a name to prefix each function related to the type as its second. For example, when generating a list of ints (i.e. C++ `vector<int>` or C# `List<T>`), the macros will look something like this:

```c
#include <generic_list.h>


// The first argument is the name of the generated data structure,
// the second argument is a name to prefix each function with,
// and the final argument is the value stored by the list, in this
// case int.

LIST_DEFINE_H(IntList, int_list, int)
LIST_DEFINE_C(IntList, int_list, int)
```

This will create and define the necessary operations for a list of ints. It also makes it so instead of having a generic `list_add` function, it instead uses an `int_list_add` function. However, in the documentation for each type, they will be prefixed with the data structure name in order to as clear as possible what each function is referring to.

All of the generated functions use snake_case, and while none of the non-user types should generally be touched, they use PascalCase or camelCase, depending on the user defined name. The generated code should be valid under the C99 standard, and can be compiled using MSVC. (It's mostly C99 for `static inline` which I believe wasn't standardized until then). If you want to verify that the collections work on you platform, there is a set of unit tests available (under the tests directory), but they rely on the [Check](https://libcheck.github.io/check/) framework, so that will also have to compile on your platform.

## Initialization and Destruction

An important note about this library is that each generated type will have two forms of initialization and destruction.

For initialization there is `*_create` and `*_init`. The create function will actually allocate the data structure and initialize it, whereas the init function will take a pointer to the data structure and initialize the data inside of the structure. For destruction there is `*_free*` and `*_free_resources`. The free\* function will free the data structure as well as it's internal data, whereas the free_resources function will only free the internal data used by the data structure. There are two cases where this is particularly useful: When you want to reuse the data structure variable or when the data structure variable is a value, not a reference (e.g. a local variable or a struct member). Typically `create` and `free` are paired together, as are `init` and `free_resources`.

\* The destruction functions for Red-Black Trees are slightly different to accommodate its particular implementation. Please look at it's documentation for further details.

Using the list defined above, the following will illustrate the differences.

```c
// Allocates and initializes a list on the heap.
// Can be seen as a helper function to avoid
// having to allocate the list yourself.
IntList* heap_list = int_list_create();

// Use the list...

int_list_free(heap_list);

// Initializes a list variable that resides on the stack.
// Note that the data inside of the list (e.g. the value buffer)
// will still be allocated on the heap.
IntList stack_list;
int_list_init(&stack_list);

// Use the list...

int_list_free_resources(&stack_list);
```

## Extensions

This library also contains a set of extensions, either for the collections as a whole, or for specific data structures. Currently the library only has two extensions:
- A generic string hash function that can be used with maps and sets.
- A set of iterators for the various collections (excluding grid).

### String Hash Function

The function is called `gds_fnv32` where `gds` stands for Generic Data Structures and `fnv32` is the hash function used (specifically fnv1a). It is inside of the `include/generic_hash_utils.h` file, but that file is included by the map and set headers, so you generally don't need to include it yourself. It can be used anywhere a hash function is required inside of this library. Alternatively, if you just want to use that function on its own, it can be used like so:

```c
const char* string_to_hash = "Hello world";

uint32_t hash = gds_fnv32(string_to_hash);
```

### Iterators

Most of the data structures in this library also come with a generic iterator. These are macros that can be almost like the builtin loop constructs to iterate over a collection. They all start with a `*_iter_start` function-like macro, and must be ended using the respective `*_iter_end` variable-like macro. Using our list example again, its iterator can be used like so:

```c
#include <generic_iterators/list_iterator.h>

IntList* list = int_list_create();
int_list_add(list, 4);
int_list_add(list, 2);
int_list_add(list, 0);

// The iterators set a value defined outside of the block
int value;

// Start iteration block
list_iter_start(list, value) {
    // Use the current value.
    printf("%d", value);
}
list_iter_end // End the iteration block.

int_list_free(list);

// Output:
// 420
```

As you can see, none of the iterators need to be prefixed with the generated type names. They just start with the data structure type itself.

An important feature of these blocks is that you can also use the `break` and `continue` keywords inside of them like any other block.

For more information regarding the specific iterators, please refer to their types page.

{% include footer.html %}

</div>
</div>
