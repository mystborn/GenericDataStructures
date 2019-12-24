# rbtree_get

Attempts to get the value associated with a key in a tree.

## Syntax

```c
bool rbtree_get(RBTree* tree, key_type key, value_type* out_value);
```

| Name | Type | Description |
| --- | --- | --- |
| tree | RBTree* | A pointer to the tree. |
| key | key_type | The key of the node to find. |
| out_value | value_type* | A pointer to be filled with the value if the key was found. |

**Returns:** `true` if a node with the specified key is found, `false` otherwise.

## Remarks

out_value is only set if it's not `NULL`. Therefore, this function can emulate an `rb_tree_contains` function if necessary.

## Example

```c
RBTREE_DEFINE_H(ISTree, is_tree, int, char*)
RBTREE_DEFINE_C(ISTree, is_tree, int, char*, int_cmp) // The definition of int_cmp can be found in the RedBlackTree main page.

ISTree* tree = is_tree_create();

is_tree_add(tree, 0, "zero");

char* value;
if(is_tree_get(tree, 0, &value))
    printf("%s\n", value);
else
    puts("0 not found");

if(is_tree_get(tree, 1, &value))
    printf("%s\n", value);
else
    puts("1 not found");

is_tree_free(tree, true);

// Output:
// zero
// 1 not found
```