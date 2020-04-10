# trie_remove (Set)

Removes an item from the trie.

## Syntax

```c
bool trie_remove(TrieSet* trie, value_type* item);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieSet* | A pointer to the trie. |
| item | value_type* | An array of values that make an item (e.g. a string). |

**Returns:** `true` on success, `false` if the item has not been added.

## Example

```c
TRIE_SET_DEFINE_H(StringTrie, str_trie, char)
TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "moo");
str_trie_add(trie, "caw");

printf("Count: %u\n", str_trie_count(trie));
printf("Conains moo? %s\n", str_trie_contains(trie, "moo") ? "true" : "false");

str_trie_remove(trie, "moo");

printf("Count: %u\n", str_trie_count(trie));
printf("Conains moo? %s\n", str_trie_contains(trie, "moo") ? "true" : "false");

str_trie_free(trie);

// Output:
// Count: 2
// Conains moo? true
// Count 1
// Contains moo? false
```