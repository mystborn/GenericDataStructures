# trie_children (Set)

Gets the values in a trie that start with the specified value.

## Syntax

```c
unsigned int trie_children(TrieSet* trie, value_type* value, value_type** out_values, unsigned int size, unsigned int max_length, bool allocate_results);
```

| Name | Type | Description |
| --- | --- | --- |
| trie | TrieSet* | A pointer to the trie. |
| value | value_type* | The starting value of the items. |
| out_values | value_type** | An array to store the children in. |
| size | unsigned int | The length of `out_values`. |
| max_length | unsigned int | The maximum length of an item to be added. |
| allocate_results | bool | Determines if the items in out_values are allocated by the function or the user. |

**Returns:** If `out_values` is not `NULL`, the number of items added to `out_values`. Otherwise, this returns the number of items that start with `value` and are no longer than `max_length`.

## Remarks

If `value` is `NULL`, gets all of the children. Consider using the trie_iter extension.

If `out_values` is `NULL`, returns the result of [trie_children_count]({{site.baseurl}}/trie/trie-set/trie_children_count).

If `allocate_results` is `true`, the items in `out_values` will be allocated by this function. In this case, it's up to the caller to free the memory. Otherwise, it's expected that each item in `out_values` should be big enough to fit an item as large as `max_length` + 1 (to null-terminate).

When the function allocates the results, it uses the minimum amount of space necessary for each value, so it is more memory efficient, but if the memory is already allocated, might as well use the existing space.

## Example

```c
TRIE_SET_DEFINE_H(StringTrie, str_trie, char)
TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

StringTrie* trie = str_trie_create();

str_trie_add(trie, "adam");
str_trie_add(trie, "alex");
str_trie_add(trie, "alejandro");

unsigned int size = 4;
char** values = malloc(4 * sizeof(*values));

unsigned int count = str_trie_children(trie, "al", values, size, INT_MAX, true);

printf("Count: %u\n", count);

for(int i = 0; i < count; i++) {
    printf("%s\n", values[i]);
}

// Make sure to clean up the memory allocated by the function.
for(int i = 0; i < count; i++) {
    free(values[i]);
}

str_trie_free(trie);

// Output:
// Count: 2
// alex
// alejandro
```