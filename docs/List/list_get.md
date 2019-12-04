---
tags: c list
---
# list_get

Gets the item at the specified index in the list. 

Bounds checking is done via `assert`, so if it's needed in a production environment, it will need to be handled by the caller.

## Syntax

```c
value_type list_get(List* list, unsigned int index);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |
| index | unsigned int | The index of the value to get. |

**Returns:** The value at the specified index.

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();
string_list_add(list, "moo");
string_list_add(list, "caw");
string_list_add(list, "oink");

char* crow_sound = string_list_get(list, 1);
```