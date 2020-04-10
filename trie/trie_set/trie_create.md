# trie_create (Set)

Allocates and initializes a new trie.

## Syntax

```c
TrieSet* trie_create(void);
```

**Returns:** The newly created trie on success, NULL on allocation failure.

## Example

```c
TRIE_SET_DEFINE_H(StringTrie, str_trie, char)
TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

StringTrie* trie = str_trie_create();

// Use the trie...

str_trie_free(trie);
```