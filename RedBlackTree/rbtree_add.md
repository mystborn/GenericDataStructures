# rbtree_add

## Syntax

```c
RBTreeNode* rbtree_add(RBTree* tree, key_type key, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |
| key | key_type | The key of the node to add. |
| value | value_type | The value of the node to add. |

**Returns:** The newly created and added node.

## Remarks

Unlike a map, multiple copies of the same key can be added to an Red-Black Tree. They are not necessarily added in a stable order (e.g. they may not be in the same order in which they were added), but they will otherwise be sorted correctly.

The return value can largely be ignored for most use cases. There is no builtin way to change the value associated with a key, so you must get the node with that key and directly change the `value`. The returned node can be used for that purpose. If that value is unavailable, you can always get the desired node by using rbtree_get_node.

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();

// Adds {0, "zero"} to the tree.
is_tree_add(tree, 0, "zero");

// Adds {1, "one"} and gets the resultant node.
ISTreeNode* node = is_tree_add(tree, 1, "one");

// Updates the value for the key 1.
node->value = "Invalid";

// Gets the value associated with 1.
// This will be "Invalid" because we changed it
// directly on the node earlier.
char* one;
is_tree_get(tree, 1, &one);

printf("The value of 1 is: %s\n", one);

is_tree_free(tree, true);

// Output:
// The value of 1 is: Invalid
```