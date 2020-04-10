# trie_add (Set)

Adds an item to the trie.

## Syntax

```c
bool trie_add(TrieSet* trie, value_type* item);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieSet* | A pointer to the trie. |
| item | value_type* | An array of values that make an item (e.g. a string). |

**Returns:** `true` on success, `false` if the item was already added or if there was an allocation failure.

## Example

```c
TRIE_SET_DEFINE_H(StringTrie, str_trie, char)
TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

StringTrie* trie = str_trie_create();

bool result = str_trie_add(trie, "moo");
printf("Added? %s\n", result ? "true", "false");

result = str_trie_add(trie, "caw");
printf("Added? %s\n", result ? "true", "false");

// Output:
// Added? true
// Added? false

str_trie_free(trie);
```