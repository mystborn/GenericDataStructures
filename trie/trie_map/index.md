# Trie (Map Version)

A [trie](https://en.wikipedia.org/wiki/Trie) is a data structure that specializes in fast array lookups. This implementation can only use strings as the map key. They can, however be of type `char*` or `wchar_t*` or some compiler specific string type.

# Syntax

```c
TRIE_MAP_DEFINE_H(type_name, function_prefix, key_type, value_type)
TRIE_MAP_DEFINE_C(type_name, function_prefix, key_type, value_type)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the trie functions with. |
| key_type | The type of the key used for lookups. |
| value_type | The value associated with the key. |

## Fields

These generally shouldn't be accessed directly (instead use the corresponding functions. They should be inlined), but they're documented just in case they're needed. This data type creates a node type `struct <type_name>Node` where `<type_name>` will be the name of the trie type. It also creates a helper struct used to aid in iterating over the trie called `<type_name>IterState`. In addition, it creates a [map]({{site.baseurl/map}}) that is used internally as well.

__Node:__

| Name | Type | Description |
| --- | --- | --- |
| map | ___&lt;type_name&gt;Map* | A map used to store child nodes. |
| count | unsigned int | The number of children in this node. |
| depth | unsigned int | This nodes location in the key array. |
| key | key_type | Stores the raw key value at this location in the key array. |
| value | value_type | If this node has a value, stores the value. |

__Trie:__

| Name | Type | Description |
| --- | --- | --- |
| root | TrieNode | A blank root node that leads to all of the children. |
| count | unsigned int | The number of values in the trie. |
| max_depth | The maximum length of an array added to the trie so far. |

__IterState:__

| Name | Type | Description |
| --- | --- | --- |
| node | TrieNode | The current node visited by the iterating function. |
| index | unsigned int | The number of values found by the iterating function so far. |

__Map:__

```c
MAP_DEFINE_H(___<type_name>Map, ___<function_prefix>_map, key_type, <type_name>Node)
```

This may seem pretty complicated, but the actual api of the trie is relatively simple.

## Example

The following creates a trie that maps words to their definitions, gets some of the definitions, and then removes one of the words.

```c
#include <generic_trie.h>

TRIE_MAP_DEFINE_H(Dictionary, dict, char, char*)
TRIE_MAP_DEFINE_C(Dictionary, dict, char, char*)

Dictionary* dict = dict_create();

dict_add(dict, "abolish", "To do away with");
dict_add(dict, "abolition", "The act of abolishing");
dict_add(dict, "absolve", "To free from guilt");
dict_add(dict, "absolute", "Free from imperfection");

char* definition = dict_get("absolve");
printf("absolve: %s\n", definition);

definition = dict_get("abolish");
printf("abolish: %s\n", definition);

dict_remove(dict, "abolition");

dict_free(dict);

// Output:
// absolve: To free from guilt
// abolish: To do away with
```

### Iterating

There is a function that gets the values from either the whole trie, or just the values starting from a specific key called [trie_children]({{site.baseurl}}/trie/trie-map/trie-children). This can be used to efficiently iterate over the values. However, there is a set of macro-based extension that also allows iterating over the trie. These are meant to be used like a for-loop. Unfortunately, the extension requires the type of the trie to function properly, making it a little more cumbersome compared to the other iterators, but it's still useful.

This trie implementation is unordered.

Keep in mind that this extension does perform heap-based allocations. It's also a rather large macro, so use it sparingly, or else the output size will increase rapidly.

In the following, we map words to their definitions, then iterate over the trie in all of the possible ways.

```c
#include <generic_trie.h>

TRIE_MAP_DEFINE_H(Dictionary, dict, char, char*)
TRIE_MAP_DEFINE_C(Dictionary, dict, char, char*)

Dictionary* dict = dict_create();

dict_add(dict, "abolish", "To do away with");
dict_add(dict, "abolition", "The act of abolishing");
dict_add(dict, "absolve", "To free from guilt");
dict_add(dict, "absolute", "Free from imperfection");

char* word;
char* definition;

trie_map_iter_key_start(Dictionary, dict, word) {
    puts(word);
}
trie_map_iter_end

// Output:
// abolish
// abolition
// absolve
// absolute

trie_map_iter_value_start(Dictionary, dict, definition)
    puts(definition);
trie_map_iter_end

// Output:
// To do away with
// The act of abolishing
// To free from guilt
// free from imperfection

trie_map_iter_start(Dictionary, dict, word, definition) {
    printf("%s: %s\n", word, definition);
}

// Output:
// abolish: To do away with
// abolition: The act of abolishing
// absolve: To free from guilt
// absolute: Free from imperfection

dict_free(dict);
```