# trie_ (Set)

Frees the resources used by the trie, then frees the trie itself.

## Syntax

```c
void trie_free(TrieSet* trie);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieSet* | A pointer to the trie. |

## Example

```c
TRIE_SET_DEFINE_H(StringTrie, str_trie, char)
TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

StringTrie* trie = str_trie_create();

// Use the trie...

str_trie_free(trie);
```