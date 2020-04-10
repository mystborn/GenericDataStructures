# trie_free (Map)

Frees the resources used internally by a trie then frees the trie itself.

## Syntax

```c
void trie_free(TrieMap* trie);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

// Use the trie...

str_trie_free(trie);
```