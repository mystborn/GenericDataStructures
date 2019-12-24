# rbtree_free

Frees a tree, optionally freeing the nodes in the tree.

## Syntax

```c
void rbtree_free(RBTree* tree, bool free_nodes);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |
| free_nodes | bool | Determines whether the nodes in the tree are freed by this function. |

## Remarks

Beacuse the Red-Black Tree data structure exposes the Node api (e.g. rbtree_add_node), it may not always be correct for this function to free the nodes owned by the tree. For those special circumstances, pass `false` for `free_nodes`. For most general use cases, this `free_nodes` should be `true` to avoid a memory leak.

## Example

```c
// Example where free_nodes should be true

RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();

is_tree_add(tree, 0, "zero");

// Use the tree...

is_tree_free(tree, true);
```

```c
// Example where free_nodes should be false

RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();


// The node is created on the stack.
// Freeing it would most likely cause a segfault.
ISTreeNode zero = { .key = 0, .value = "zero" };
is_tree_add_node(&tree, &zero);

// Use the tree...

// Free the tree itself, but don't free the nodes.
is_tree_free(tree, false);
```