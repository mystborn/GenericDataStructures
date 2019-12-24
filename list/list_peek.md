# list_peek

Gets the last item in the list without removing it.

It checks to see if any items are in the list via assert, so if it's needed in a production environment, it will need to be handled by the caller.

## Syntax

```c
value_type list_peek(List* list);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |

**Returns:** The item at the end of the list.

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();

string_list_add(list, "first");
string_list_add(list, "last");

char* last = string_list_peek(list);
```