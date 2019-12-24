# list_insert

Inserts an item into the list. If the index is equal to the lists capacity, it is just added to the end.

## Syntax

```c
bool list_insert(List* list, unsigned int index, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |
| index | unsigned int | The 0-based index of the list to insert the item into. Can be <= capacity. |
| value | value_type | The item to insert into the list. |

**Returns:** `true` if the operation succeeded, `false` otherwise. It can be false if the index was outside of the lists capacity or if the list failed to resize due to being out of memory.

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();

string_list_add(list, "Hello");
string_list_add(list, "!");
string_list_insert(list, 1, " world")

for(int i = 0; i < string_list_count(list); i++)
    printf("%s\n", string_list_get(list, i));
```