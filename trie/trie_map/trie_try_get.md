# trie_try_get (Map)

Attempts to get the value mapped to a key in a trie.

## Syntax

```c
bool trie_try_get(TrieMap* trie, key_type* key, value_type* out_value);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |
| key | key_type* | An array of values that make a key (e.g. a string). |
| out_value | value_type* | A pointer to be filled with the value if the key is found. |

**Returns:** `true` if the key exists; `false` otherwise.

## Remarks

The `out_value` will only be assigned to if it's not NULL. Therefore, if you just need to check if the key exists in the trie, you can use this function and just pass NULL for the last parameter.

`out_value` is not modified if the key was not found.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "one", 1);

int value;
bool result;

result = str_trie_try_get(trie, "one", &value);
printf("Contains one? %s\n", result ? "true" : "false");
if(result)
    printf("Value: %d\n", value);

result = str_trie_try_get(trie, "two", &value);
printf("Contains two? %s\n", result ? "true" : "false");
if(result)
    printf("Value: %d\n", value);

str_trie_free(trie);

// Output:
// Contains one? true
// Value: 1
// Contains two? false
```