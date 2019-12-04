---
tags: c list
---
# list_init

Initializes a list.

## Syntax

```c
bool list_init(List* list);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to a list that will be initialized. |

**Returns:** `true` if the list was initialized, `false` if there wasn't enough memory.

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList list;
string_list_init(&list);

// use the list...


// Free the lists resources
string_list_free_resources(&list);
```