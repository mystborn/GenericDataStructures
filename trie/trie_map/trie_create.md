# trie_create (Map)

Allocates and initializes a new trie.

## Syntax

```c
TrieMap* trie_create(void);
```

**Returns:** The newly created trie on success, `NULL` if there was an allocation failure.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

// Use the trie...

str_trie_free(trie);
```