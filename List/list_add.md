# list_add

Adds an item to the end of a list.

## Syntax

```c
bool list_add(List* list, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |
| value | value_type | The item to add to the end of the list. |

**Returns:** `true` on success, `false` on failure, which should only occur if the list capacity was full and it failed to resize due to being out of memory.

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();

string_list_add(list, "Hello");
string_list_add(list, " world");
string_list_add(list, "!");

for(int i = 0; i < string_list_count(list); i++)
    printf("%s\n", string_list_get(list, i));
```