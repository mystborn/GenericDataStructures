# trie_init (Set)

Initializes an existing trie.

## Syntax

```c
bool trie_init(TrieSet* trie);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieSet* | A pointer to the trie. |

**Returns:** `true` on success, `false` if there wasn't enough memory.

## Example

```c
TRIE_SET_DEFINE_H(StringTrie, str_trie, char)
TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

StringTrie trie;
trie_init(&trie);

// Use the trie...

str_trie_free_resources(&trie);
```