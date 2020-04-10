# trie_children (Map)

Gets the items in a trie whose keys start with the specified value.

## Syntax

```c
unsigned int trie_children(TrieMap* trie, key_type* key, key_type** keys, unsigned int keys_size, value_type* values, unsigned int values_size, unsigned int max_length, bool allocate_keys);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieMap* | A pointer to the trie. |
| key | key_type* | The starting value of the children keys. |
| keys | key_type** | An array to store the keys in. |
| keys_size | unsigned int | The length of `keys`. |
| values | value_type* | An array to store the values in. |
| values_size | unsigned int | The length of `values`. |
| max_length | unsigned int | The maximum length of a key to be added. |
| allocate_keys | bool | Determines if the keys in `keys` are allocated by the function or the user. |

**Returns:** If `keys` or `values` are not `NULL`, the number of items added to them. Otherwise, returns the number of keys that start with `key` and are no longer than `max_length`.

## Remarks

If `key` is `NULL`, gets all of the children. Consider using the trie_iter extension.

`keys` or `values` can be `NULL` to only get one or the other.

The key and value at an index in `keys` and `values` correlate to the item in the map. For example if `keys[0]` is `"one"` and `values[0]` is `1`, the item was added to the trie like so `trie_add(trie, "one", 1)`.

The sizes of `keys` and `values` can be different.

If both `keys` and `values` are `NULL`, returns the result of [trie_children_count]({{site.baseurl}}/trie/trie-map/trie_children_count).

If `allocate_keys` is `true`, the values in `keys` will be allocated by the function. In this case, it's up to the called to free the memory. Otherwise, it's expected that each item in `keys` should be big enough to a fit a key as large as `max_length`  + 1 (to null-terminate).

When the function allocates a key, it uses the minimum amount of space necessary to hold the value, so it is more memory efficient, but it the memory has alread been allocated, might as well use the existing space.

## Example

```c
TRIE_MAP_DEFINE_H(StringTrie, str_trie, char, int)
TRIE_MAP_DEFINE_C(StringTrie, str_trie, char, int)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "one", 1);
str_trie_add(trie, "two", 2);
str_trie_add(trie, "three", 3);

unsigned int size = 4;
char** keys = malloc(size * sizeof(*keys));
int* values = malloc(size * sizeof(*values));

unsigned int count = str_trie_childre(trie, "t", keys, size, values, size, INT_MAX, true);

printf("Count: %u\n", count);

for(int i = 0; i < count; i++) {
    printf("Key: %s, Value: %d\n", keys[i], values[i]);
}

// Make sure to clean up the memory allocated by the function.

for(int i = 0; i < count; i++) {
    free(keys[i]);
}

str_trie_free(trie);

// Output:
// Count: 2
// Key: two, Value: 2
// Key: three, Value: 3
```