# rbtree_get_node

Gets a node with the specified key in a tree.

## Syntax

```c
RBTreeNode* rbtree_get_node(RBTree* tree, key_type key);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |
| key | key_type | The key of the node to get. |

**Returns:** A node with the key if found, `NULL` otherwise.

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();

is_tree_add(tree, 0, "zero");
is_tree_add(tree, 1, "one");

ISTreeNode* zero_node = is_tree_get_node(tree, 0);

// Print out the nodes members.
printf("{ %d, %s }\n", zero_node->key, zero_node->value);

ISTreeNode* two_node = is_tree_get_node(tree, 2);

if(two_node == NULL)
    puts("Could not find a node with the key 2.");
else
    printf("{ %d, %s }\n", two_node->key, two_node->value);

is_tree_free(tree, true);

// Output:
// { 0, zero }
// Could not find a node with the key 2
```