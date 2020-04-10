# trie_get_and_remove (Map)

Gets the value mapped to a key in a trie, then removes both.

## Syntax

```c
bool trie_get_and_remove(TrieMap* trie, key_type* key, value_type* out_value);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |
| key | key_type* | An array of values that make a key (e.g. a string). |
| out_value | value_type* | A pointer to be filled with the value if the key is found. |

**Returns:** `true` if the key exists; `false` otherwise.

## Remarks

The `out_value` will only be assigned to if it's not NULL. `out_value` is not modified if the key was not found.

This function can be used to efficiently get a value for further use before removing it from the trie.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "one", 1);

int value = 0;
bool removed = str_trie_get_and_remove(trie, "one", &value);

printf("Removed? %s\n", removed ? "true" : "false");
printf("Value: %d\n", value);

str_trie_free(trie);

// Output:
// Removed? true
// Value: 1
```