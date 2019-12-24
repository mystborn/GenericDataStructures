# rbtree_count

Gets the number of nodes in the tree.

## Syntax

```c
unsigned int rbtree_count(RBTree* tree);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |

**Returns:** The number of nodes (Key-Value pairs) in the tree.

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();

is_tree_add(tree, 0, "zero");
is_tree_add(tree, 1, "one");

unsigned int count = is_tree_count(tree);
printf("Number of items in the tree: %d\n", count);

is_tree_free(tree, true);

// Output:
// Number of items in the tree: 2
```