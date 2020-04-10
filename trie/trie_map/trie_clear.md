# trie_clear (Map)

Removes all items from a trie.

## Syntax

```c
bool trie_clear(TrieMap* trie);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |

**Returns:** `true` on success, `false` if there was an allocation error.

## Remarks

This function literally just calls [trie_free_resource]({{site.baseurl}}/trie/trie-map/trie_free_resources) then [trie_init]({{site.baseurl}}/trie/trie-map/trie_init), so the return value is just forwarded from `trie_init`.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "one", 1);
str_trie_add(trie, "two", 2);

printf("Count: %u\n", str_trie_count(trie));

str_trie_clear(trie);

printf("Count: %u\n", str_trie_count(trie));

str_trie_free(trie);

// Output:
// Count: 2
// Count: 0
```