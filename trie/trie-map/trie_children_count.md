# trie_children_count (Map)

Gets the number of keys in a trie that start with the specified value.

## Syntax

```c
unsigned int trie_children_count(TrieMap* trie, key_type* key, unsigned int max_length);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |
| key | key_type* | The starting value of the children keys. |
| max_length | unsigned int | The maximum length of a key to be counted. |

**Returns:** The number of keys in the trie that start with `key` and are no longer than `max_width`. Returns 0 if `key` is not in the trie.

## Remarks

If `key` is `NULL`, counts all children.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "one", 1);
str_trie_add(trie, "two", 2);
str_trie_add(trie, "three", 3);

unsigned int count = str_trie_children_count(trie, "t", INT_MAX);

printf("Keys starting with 't': %u", count);

str_trie_free(trie);

// Output:
// Keys starting with 't': 2
```