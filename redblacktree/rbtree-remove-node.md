---
layout: default
title: rbtree_remove_node
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
<button class="nav-dropdown"></button>
<ul class="nav-dropdown-container">
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
<button class="nav-dropdown active"></button>
<ul class="nav-dropdown-container" style="display: block;">
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

# rbtree_remove_node

Removes the specified node from the tree.

## Syntax

```c
RBTreeNode* rbtree_remove_node(RBTree* tree, RBTreeNode* node);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |
| node | RBTreeNode* | The node to remove. |

**Returns:** The node that was removed.

## Remarks

Take extreme care to make sure the tree used by the function actually owns the node. It is never checked, and assumes that the it is.

In addition, the actual node that was removed might not be the node that was passed to the function. In these cases, make sure to use the return value, not the parameter in further operations to the removed node (i.e. freeing it or reusing it).

As with the other rbtree_*_node functions, this rarely needs to be used directly.

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree tree;
is_tree_init(&tree);

ISTreeNode zero = { .key = 0, .value = "zero" };
ISTreeNode one = { .key = 0, .value = "one" };
ISTreeNode negative_one = { .key = -1, .value = "negative_one" };

is_tree_add_node(&tree, &zero);
is_tree_add_node(&tree, &one);
is_tree_add_node(&tree, &negative_one);

// Wait a second...
// We actually only want positive values.
// Remove negative_one from the tree using it's node.

is_tree_remove_node(&tree, &negative_one);

// Use the tree...

// At the end of the scope, don't call any free function.
// The tree value itself doesn't need to be freed, and neither
// do any of the nodes, so we can just let them get cleaned up
// with the rest of the stack frame.
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
