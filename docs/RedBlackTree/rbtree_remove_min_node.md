---
tags: c rb-tree tree
---
# rbtree_remove_min_node

Removes the node with the minimum value from a tree.

## Syntax

```c
RBTreeNode* rbtree_remove_min_node(RBTree* tree);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |

**Returns:** The node with the minimum key if there were any nodes, otherwise `NULL`.

## Remarks

__Important:__ The nodes removed from the tree with this function will have to be manually freed! (Only if they were allocated dynamically to begin with (e.g. with rbtree_add or some user allocation method)).

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();

is_tree_add(tree, 0, "zero");
is_tree_add(tree, 1, "one");
is_tree_add(tree, -1, "negative one");

while(is_tree_count(tree) > 0) {
    ISTreeNode* node = is_tree_remove_min_node(tree);
    printf("{ %d, \"%s\" }\n", node->key, node->value);
    free(node);
}

is_tree_free(tree, true);

// Output:
// { -1, "negative one" }
// { 0, "zero" }
// { 1, "one" }
```