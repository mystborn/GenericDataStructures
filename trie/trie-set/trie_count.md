# trie_count (Set)

Gets the number of items in the trie.

## Syntax

```c
unsigned int trie_count(TrieSet* trie);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieSet* | A pointer to the trie. |

**Returns:** The number of items currently in the trie.

## Example

```c
TRIE_SET_DEFINE_H(StringTrie, str_trie, char)
TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "moo");
str_trie_add(trie, "caw");
str_trie_add(trie, "oink");

unsigned int count = str_trie_count(trie);
printf("Count: %u\n", count);

str_trie_free(trie);

// Output:
// Count: 3
```