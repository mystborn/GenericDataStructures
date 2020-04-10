# trie_contains (Set)

Determines if the trie contains the specified item.

## Syntax

```c
bool trie_contains(TrieSet* trie, value_type* item);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieSet* | A pointer to the trie. |
| item | value_type* | An array of values that make an item (e.g. a string). |

**Returns:** `true` if the item was previously added to the trie, `false` otherwise.

## Example

```c
TRIE_SET_DEFINE_H(StringTrie, str_trie, char)
TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "moo");

bool contains = str_trie_contains(trie, "moo");
printf("Contains moo? %s\n", contains ? "true" : "false");
printf("Contains caw? %s\n", contains ? "true" : "false");

str_trie_free(trie);

// Output:
// Contains moo? true
// Contains caw? false
```