# list_count

Gets the current number of items in a list.

## Syntax

```c
unsigned int list_count(List* list);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |

**Returns:** The number of items in the list.

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();

string_list_add(list, "moo");
assert(string_count(list) == 1);

printf("%d\n", string_count(list));
```