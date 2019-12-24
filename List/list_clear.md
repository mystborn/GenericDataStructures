# list_clear

Clears the contents of the list without changing the capacity.

## Syntax

```c
void list_clear(List* list);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();
string_list_add("moo");
string_list_add("caw");

printf("%d\n", string_list_count(list));

string_list_clear(list);

printf("%d\n", string_list_count(list));
```