# rbtree_add_node

Adds the specified node to the tree.

## Syntax

```c
void rbtree_add_node(RBTree* tree, RBTreeNode* node);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |

**Returns:**

## Remarks

This function does not check if the node has already been added to the tree, but the same node __can't be added to any tree twice__. It also can't be added to two seperate trees at the same time. Once removed from one tree, it can be freely used again though.

This function generally shouldn't be called directly unless you're using a set of preallocated nodes. Unless you're ok with freeing the nodes, make sure to pass `false` to the second parameter in `rb_tree_free` to make sure it doesn't free any of your nodes. If the tree is on the stack, you don't need to use any free function, just let it go out of scope naturally.

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

// This example keeps the entire tree on the
// stack.

ISTree tree;
is_tree_init(&tree);

// The best way to initialize a node is using a designated initializer.
ISTreeNode zero_node = { .key = 0, .value = "zero" };
ISTreeNode one_node = { .key = 1, .value = "one" };

// Add the nodes to the tree.
is_tree_add_node(&tree, &zero_node);
is_tree_add_node(&tree, &one_node);

// Use the tree...

// At the end of the scope, don't call any free function.
// The tree value itself doesn't need to be freed, and neither
// do any of the nodes, so we can just let them get cleaned up
// with the rest of the stack frame.
```