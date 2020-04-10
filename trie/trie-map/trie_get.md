# trie_get (Map)

Gets the value mapped to a key in a trie.

## Syntax

```c
value_type trie_get(TrieMap* trie, key_type* key);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |
| key | key_type* | An array of values that make a key (e.g. a string). |

**Returns:** The value mapped to the key.

## Remarks

If the key did not exist in the trie, the returned value is equal to `(value_type){0}`.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "one", 1);

printf("Value: %d\n", str_trie_get(trie, "one"));

str_trie_free(trie);

// Output:
// Value: 1
```