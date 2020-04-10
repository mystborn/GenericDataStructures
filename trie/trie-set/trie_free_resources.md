# trie_free_resources (Set)

Frees the resources used internally by the trie without freeing the trie itself.

## Syntax

```c
void trie_free_resources(TrieSet* trie);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieSet* | A pointer to the trie. |

## Example

```c
TRIE_SET_DEFINE_H(StringTrie, str_trie, char)
TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

StringTrie trie;
trie_init(&trie);

// Use the trie...

str_trie_free_resources(&trie);
```