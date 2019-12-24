# list_set

Replaces the value at the specified index in the list.

The bounds checking is done via `assert`, so if it's needed in a production environment, it will need to be handled by the caller.

## Syntax

```c
void list_set(List* list, unsigned int index, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| list | List* | A pointer to the list. |
| index | unsigned int | The index of the value to replace. |
| value | value_type | The new value. |

## Example

```c
LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList* list = string_list_create();

string_list_add(list, "caw");
string_list_add(list, "moo");
string_list_replace(list, 0, " caw");

for(int i = 0; i < string_list_count(list); i++)
    printf("%s\n", string_list_get(list, i));

// Output:
// caw caw
```