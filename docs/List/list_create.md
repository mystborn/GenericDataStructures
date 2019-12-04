---
tags: c list
---
# list_create

Allocates and initializes a new list.

## Syntax

```c
List* list_create();
```

**Returns:** A pointer to the newly allocated list, or `NULL` if there wasn't enough memory.

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();

// use the list...


// Free the list.
string_list_free(list);
```