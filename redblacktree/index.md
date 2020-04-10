# Red Black Tree

A [red black tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree) (rb-tree) is a self balancing binary tree. It's particularly useful for storing sorted data, even after insertions or removals. As such it can be used a priority queue and even traversed in order very easily. Similar to a [map]({{site.baseurl}}/map), its nodes have a key, which is used for sorting, and a value.

# Syntax

```c
RBTREE_DEFINE_H(type_name, function_prefix, key_type, value_type)
RBTREE_DEFINE_C(type_name, function_prefix, key_type, value_type, compare_fn)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the rb-tree functions with. |
| key_type | The key of each node. |
| value_type | The value of each node. |
| compare_fn | A function that compares two keys. |

## Fields

These generally don't need to be accessed directly, but there are functions for getting the nodes directly in order to make some operations easier (iterating over a subsection of the tree for example). The tree fields should be retrieved using the proper functions though.

__Tree:__

| Name | Type | Description |
| --- | --- | --- |
| root | RBTreeNode* | The root node of the tree. |
| count | unsigned int | The number of nodes in the tree. |

__Node Fields:__

| Name | Type | Description |
| --- | --- | --- |
| left | RBTreeNode* | The left child of the node. The child key is less than the parent key. |
| right | RBTreeNode* | The right child of the node. The child key is greater than the parent key. |
| parent | RBTreeNode* | The parent of this node. |
| key | key_type | The key used to sort this node. |
| value | value_type | The value of this node. |
| color | RBColor | Internal use only. Do not modify. |

## Example

The following creates a tree of people sorted by their ages. It then updates one of their names, gets the youngest person, and finally removes the oldest.

```c
#include <generic_rbtree.h>

// The comparison function used by the tree.
static int int_cmp(int left, int right) {
    return left < right ? -1 : (left > right ? 1 : 0); 
}

// Define the data structure
RBTREE_DEFINE_H(AgeTree, age_tree, int, char*)
RBTREE_DEFINE_C(AgeTree, age_tree, int, char*, int_cmp)

// Allocate and initialize the tree.
AgeTree* tree = age_tree_create(tree);

// Add the people to the tree.
age_tree_add(tree, 12, "Stacy");
age_tree_add(tree, 13, "Kenny");
AgeTreeNode* elizabeth = age_tree_add(tree, 13, "Elizabeth");
age_tree_add(tree, 35, "Stacy's Mom");

// Elizabeth wants to be called by Elise now, so we just update the value on the node directly.
// Currently this is the only way to update a value.
elizabeth->value = "Elise";

// Gets the youngest person
char* youngest_name;
age_tree_get_min(tree, &youngest_name);

printf("Youngest: %s\n", youngest_name);
// Output:
// Youngest: Stacy


// Removes and gets the oldest person by their node.
AgeTreeNode* oldest = age_tree_remove_max_node(tree);

printf("%s: %d\n", oldest->value, oldest->key);
// Output:
// Stacy's Mom: 35


// When you remove a node directly, it needs to be freed manually.
free(oldest);

// We're done with the tree, time to free it. The free function has an option to free the nodes along with the tree
// because it's possible that the user owns the nodes, not the tree.

// We let the function free the nodes for us.
age_tree_free(tree, true);
```

### Nodes

Sometimes you may want to have ownership or otherwise fine control over the nodes in the tree. One such example was used above, where the value of a node was changed. This is an advanced example that creates the nodes and tree on the stack, using the exact same keys and values as the ones above.

```c
#include <generic_rbtree.h>

// The comparison function used by the tree.
static int int_cmp(int left, int right) {
    return left < right ? -1 : (left > right ? 1 : 0); 
}

RBTREE_DEFINE_H(AgeTree, age_tree, int, char*)
RBTREE_DEFINE_C(AgeTree, age_tree, int, char*, int_cmp)

AgeTree tree;
age_tree_init(&tree);

#define PEOPLE 4

AgeTreeNode nodes[PEOPLE] = {
    { .key = 12, .value = "Stacy" },
    { .key = 13, .value = "Kenny" },
    { .key = 13, .value = "Elizabeth" },
    { .key = 35, .value = "Stacy's Mom" }
};

for(int i = 0; i < PEOPLE; i++)
    age_tree_add_node(&tree, nodes + i);

// Change Elizabeths name to Elise.
nodes[2].value = "Elise";

// Continue using the tree.

// Once you're done, since the entire data structure was allocated on the stack,
// there is no clean up to do.
```

### Iterating

There are a couple of extensions for iterating over the nodes in a rb-tree. All of them iterate over the tree in-order. One iterates over the keys, one over the values, and finally one iterates over both the keys and values together. It's meant to be used like a for loop. Unfortunately, the extension needs the type of the tree to function properly, making it a little more cumbersome compared to the other iterators, but it's still immensely useful.

```c
#include <generic_rbtree.h>

// The comparison function used by the tree.
static int int_cmp(int left, int right) {
    return left < right ? -1 : (left > right ? 1 : 0); 
}

RBTREE_DEFINE_H(AgeTree, age_tree, int, char*)
RBTREE_DEFINE_C(AgeTree, age_tree, int, char*, int_cmp)

AgeTree* tree = age_tree_create(tree);

age_tree_add(tree, 12, "Stacy");
age_tree_add(tree, 13, "Kenny");
age_tree_add(tree, 13, "Elise");
age_tree_add(tree, 35, "Stacy's Mom");

int age;
char* name;

// Iterate over both keys and values
rbtree_iter_start(AgeTree, tree, age, name) {
    printf("%s: %d\n", name, age);
}
rbtree_iter_end

// Output:
// Stacy: 12
// Kenny: 13
// Elise: 13
// Stacy's Mom: 35

// Iterate over just the keys
rbtree_iter_keys_start(AgeTree, tree, age) {
    printf("%d\n", age);
}
rbtree_iter_end

// Output
// 12
// 13
// 13
// 35

// Iterate over just the values
rbtree_iter_values_start(AgeTree, tree, name)
    printf("%s\n", name);
rbtree_iter_end

// Output:
// Stacy
// Kenny
// Elise
// Stacy's Mom

age_tree_free(tree, true);
```

#### Syntax

```c
rbtree_iter_start(type_name, tree, out_key, out_value)
rbtree_iter_keys_start(type_name, tree, out_key)
rbtree_iter_values_start(type_name, tree, out_value)
```

| Name | Type | Description |
| --- | --- | --- |
| type_name | type_name | The name of trees type. |
| tree | RBTree | The tree to iterate over. |
| out_key | key_type | A variable to be set by the iterator to the current key. |
| out_value | value_type | A variable to be set by the iterator to the current value. |

It is not safe to modify the tree at all during iteration.

It is safe to nest an iteration block inside of another.