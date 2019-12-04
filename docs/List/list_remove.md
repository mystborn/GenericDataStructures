---
tags: c list
---
# list_remove

Removes a value at the specified index within a list. All values after the index will be shifted down one.

Bounds checking is done via `assert`, so if it's needed in a production environment, it will need to be handled by the caller.

## Syntax

```c
void list_remove(List* list, unsigned int index);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |
| index | unsigned int | The index of the item to remove. |

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();
string_list_add(list, "Hello");
string_list_add(list, " garbage");
string_list_add(list, " world!");

string_list_remove(list, 1);
```