# trie_children_count (Set)

Gets the number of items in a trie that start with the specified value.

## Syntax

```c
unsigned int trie_children_count(TrieSet* trie, value_type* value, unsigned int max_length);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieSet* | A pointer to the trie. |
| value | value_type* | The starting value of the items. |
| max_length | unsigned int | The maximum length of an item to be counted. |

**Returns:** The number of items in the trie that start with `value` and are no longer than `max_length`. Returns 0 if `item` is not in the trie.

## Remarks

If `value` is `NULL`, counts all children.

## Example

```c
TRIE_SET_DEFINE_H(StringTrie, str_trie, char)
TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "adam");
str_trie_add(trie, "alex");
str_trie_add(trie, "alejandro");

unsigned int count = str_trie_children_count(trie, "al", INT_MAX);

printf("Names starting with 'al': %u\n", count);

count = str_trie_children_count(trie, "al", 6);

printf("Names starting with 'al' with 6 characters or less: %u\n", count);

str_trie_free(trie);

// Output:
// Names starting with 'al': 2
// Names starting with 'al' with 6 characters or less: 1
```