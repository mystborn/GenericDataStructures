---
tags: c rb-tree tree
---
# rbtree_create

Allocates and initializes a new tree.

## Syntax

```c
RBTree* rbtree_create(void);
```

**Returns:** A new tree if successful, `NULL` on allocation failure.

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();

// Use the tree...

is_tree_free(tree, true);
```