---
tags: c list
---
# list_free_resources

Frees the resources used internally by the list, without freeing the list itself. Can be used for list variables on the stack or just to reuse a list without reallocating the variable.

## Syntax

```c
void list_free_resources(List* list);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList list;
string_list_init(&list);

// Use the list...

string_list_free_resources(&list);
```