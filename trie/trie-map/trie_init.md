# trie_init (Map)

Initializes an existing trie.

## Syntax

```c
bool trie_init(TrieMap* trie);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |

**Returns:** `true` on success, `false` if there was an allocation failure.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie trie;
str_trie_init(&trie);

// Use the trie...

str_trie_free_resources(&trie);
```