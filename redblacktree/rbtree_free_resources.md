# rbtree_free_resources

Frees the nodes owned by a tree, but doesn't free the tree itself.

## Syntax

```c
void rbtree_free_resources(RBTree* tree);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |

## Remarks

Unlike the other \*\_free_resources functions, this should not be used to free _any_ tree's resources. It should only be used if the nodes owned by the tree were dynamically allocated in way that can be freed (e.g. with rbtree_add, or some user allocation method).

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree tree;
is_tree_init(&tree);

is_tree_add(&tree, 0, "zero");
is_tree_add(&tree, 1, "one");

// Use the tree...

// Free the nodes owned by the tree, but don't
// free the tree itself because it exists on the stack.
is_tree_free_resources(&tree);
```