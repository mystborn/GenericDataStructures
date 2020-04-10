# trie_count (Map)

Gets the number of items in a trie.

## Syntax

```c
unsigned int trie_count(TrieMap* trie);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |

**Returns:** The number of items.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "one", 1);
str_trie_add(trie, "two", 2);
str_trie_add(trie, "three", 3);

unsigned int count = str_trie_count(trie);
printf("Count: %u\n", count);

str_trie_free(trie);

// Output:
// Count: 3
```