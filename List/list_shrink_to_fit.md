# list_shrink_to_fit

Shrinks the allocated capacity to match the current count of the list. Cannot shrink the capacity below 1.

## Syntax

```c
void list_shrink_to_fit(List* list);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList list;
string_init_capacity(&list, 1000);

string_list_add("moo");

assert(list.capacity == 1000);

string_shrink_to_fit(&list);

assert(list.capacity == 1);
```