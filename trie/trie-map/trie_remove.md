# trie_remove (Map)

Removes a key (and the value mapped to it) from a trie.

## Syntax

```c
bool trie_remove(TrieMap* trie, key_type* key);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |
| key | key_type* | An array of values that make a key (e.g. a string). |

**Returns:** `true` on success; `false` if the key wasn't added.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "one", 1);
str_trie_add(trie, "two", 2);
str_trie_add(trie, "three", 3)

printf("Count: %u\n", str_trie_count(trie));

bool removed = str_trie_remove(trie, "one");
printf("Removed? %s\n", removed ? "true" : "false");

printf("Count: %u\n", str_trie_count(trie));

removed = str_trie_remove(trie, "four");
printf("Removed? %s\n", removed ? "true" : "false");

str_trie_free(trie);

// Output:
// Count: 3
// Removed? true
// Count: 2
// Removed? false
```