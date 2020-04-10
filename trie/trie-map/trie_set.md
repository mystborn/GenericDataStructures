# trie_set (Map)

Adds or replaces a key-value pair in a trie.

## Syntax

```c
bool trie_set(TrieMap* trie, key_type* key, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |
| key | key_type* | An array of values that make a key (e.g. a string). |
| value | value_type | The value to set in the trie. |

**Returns:** `true` on success, `false` on allocation failure.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "one", 1);

bool result = str_trie_add(trie, "one", 2);
printf("Replaced? %s\n", result ? "true" : "false");

result = str_trie_set(trie, "one", 2);
printf("Replaced? %s\n", result ? "true" : "false");

str_trie_free(trie);

// Output:
// Replaced? false
// Replaced? true
```