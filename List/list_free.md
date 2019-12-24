# list_free

Frees the resources used by a list, then frees the list itself.

## Syntax

```c
void list_free(List* list);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();

// Use the list...

string_list_free(list);
```