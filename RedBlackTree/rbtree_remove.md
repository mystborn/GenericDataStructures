# rbtree_remove

Removes the node with the specified key from a tree.

## Syntax

```c
bool rbtree_remove(RBTree* tree, key_type key, value_type* out_value);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |
| key | key_type | The key of the node to remove. |
| out_value | value_type* | A pointer to be filled with the removed nodes value. |

**Returns:** `true` if the node was found and removed, `false` otherwise.

## Remarks

`out_value` is only filled if it's not `NULL`.

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();

is_tree_add(tree, 0, "zero");

char* value;

if(is_tree_remove(tree, 0, &value))
    printf("Successfully removed { 0, \"%s\" } from the tree.\n", value);
else
    puts("Failed to remove 0 from the tree.");

if(is_tree_remove(tree, 1, &value))
    printf("Successfully removed { 1, \"%s\" } from the tree.\n", value);
else
    puts("Failed to remove 1 from the tree.");

is_tree_free(tree, true);

// Output:
// Successfully removed { 0, "zero" } from the tree.
// Failed to remove 1 from the tree.
```