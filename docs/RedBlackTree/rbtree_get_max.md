---
tags: c rb-tree tree
---
# rbtree_get_max

Gets the value with the maximum key in a tree.

## Syntax

```c
bool rbtree_get_max(RBTree* tree, value_type* out_value);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |
| out_value | value_type* | A pointer to be filled with the value of the maximum node. |

**Returns:** `true` if there were any nodes in the tree, `false` otherwise.

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();

is_tree_add(tree, 0, "zero");
is_tree_add(tree, 1, "one");
is_tree_add(tree, -1, "negative one");

char* value;
rbtree_get_max(tree, &out_value);

printf("Maximum value: %s\n", value);

is_tree_free(tree, true);

// Output:
// Maximum value: one
```