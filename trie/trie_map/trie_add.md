# trie_add (Map)

Adds key-value pair to the trie.

## Syntax

```c
bool trie_add(TrieMap* trie, key_type* key, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |
| key | key_type* | An array of values that make a key (e.g. a string). |
| value | value_type | The value to add. |

**Returns:** `true` on success, `false` if the key was already added or if there was an allocation failure.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

bool result = str_trie_add(trie, "one", 1);
printf("Added? %s\n", result ? "true" : "false");

result = str_trie_add(trie, "one", 1);
printf("Added? %s\n", result ? "true" : "false");

str_trie_free(trie);

// Output:
// Added? true
// Added? false
```