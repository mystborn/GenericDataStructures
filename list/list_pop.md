# list_pop

Gets and removes the last item in the list.

It checks to see if any items are in the list via assert, so if it's needed in a production environment, it will need to be handled by the caller.

## Syntax

```c
value_type list_pop(List* list);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |

**Returns:** The last item in the list.

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();

string_list_add(list, "front");
string_list_add(list, " to ");
string_list_add(list, "back");

while(string_list_count(list) > 0) {
    char* item = string_list_pop(list);
    printf("%s", item);
}
printf("\n");

// Output
// back to front


```