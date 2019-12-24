# list_init_capacity

Initializes a list and allocates the backing array with the specified capacity.

## Syntax

```c
bool list_create_capactiy(List* list, unsigned int capacity);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to a list that will be initialized. |
| capacity | unsigned int | The initial capacity of the list. |

**Returns:** `true` if the list was initialized, `false` if there wasn't enough memory.

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList list;
string_list_init_capacity(&list, 10);

assert(string_list_capacity(&list) == 10);
```