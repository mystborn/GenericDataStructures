---
tags: c rb-tree tree
---
# rbtree_remove_node

Removes the specified node from the tree.

## Syntax

```c
void rbtree_remove_node(RBTree* tree, RBTreeNode* node);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |
| node | RBTreeNode* | The node to remove. |

## Remarks

Take extreme care to make sure the tree used by the function actually owns the node. It is never checked, and assumes that the it is.

As with the other rbtree_*_node functions, this rarely needs to be used directly. The main use case is to remove nodes allocated outside of rbtree_add.

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