---
tags: c rb-tree tree
---
# rbtree_init

Initializes a tree.

## Syntax

```c
void rbtree_init(RBTree* tree);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

RBTree tree;
rbtree_init(&tree);

rbtree_add(&tree, 0, "zero");

// Use the tree...

rbtree_free_resources(&tree);
```