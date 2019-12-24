# rbtree_root

Gets the root node from the tree.

## Syntax

```c
RBTreeNode* rbtree_root(RBTree* tree);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |

**Returns:** The root node of the tree.

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();

is_tree_add(tree, 0, "zero");
is_tree_add(tree, 1, "one");
is_tree_add(tree, 2, "two");

ISTreeNode* root = is_tree_root(tree);

printf("Root Key: %d, Value: %s\n", root->key, root->value);

is_tree_free(tree, true);
```