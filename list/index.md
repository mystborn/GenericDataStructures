# List

A list is just like it sounds: a list of items that can be added to or removed from without concern for running out of space. It is a dynamically sized array essentially The list collection is similar to the `vector<T>` in C++ or `List<T>` in C#. It also defines `peek` and `pop` operations to be used as a stack if necessary.

## Syntax

```c
LIST_DEFINE_H(type_name, function_prefix, value_type)
LIST_DEFINE_C(type_name, function_prefix, value_type)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the list functions with. |
| value_type | The value to be held by the list. |

## Fields

These shouldn't be accessed directly (instead use the corresponding functions. They should be inlined), but they're documented in case they're needed (e.g. accessing the list size in a tight loop. Again, this should be inlined, so profile before accessing the field).

| Name | Type | Description |
| --- | --- | --- |
| buffer | value_type\* | The backing array of the list. |
| count | unsigned int | The number of items in the list. |
| capacity | unsigned int | The number of items the list can potentially hold. |

## Example

The following shows how to generate a list of strings, then add and get values from the list.

```c
#include <stdio.h>

#include <generic_list.h>

LIST_DEFINE_H(StringList, string_list, char*)
LIST_DEFINE_C(StringList, string_list, char*)

StringList list;
string_list_init(&list);
string_list_add(&list, "Hello");
string_list_add(&list, " World!");

for(int i = 0; i < string_list_count(&list); i++) {
    printf("%s", string_list_get(&list, i));
}
printf("\n");

string_list_free_resources(&list);

// Output
// Hello World!
```

### Iterating

There is an extension that allows for iterating over the items in a list in order. It's meant to be used like a for loop.

```c
#include <stdio.h>

#include <generic_list.h>
#include <generic_iterators/list_iterator.h>

LIST_DEFINE_H(IntList, int_list, int)
LIST_DEFINE_H(IntList, int_list, int)

IntList* list = int_list_create();

for(int i = 1; i <= 5; i++)
    int_list_add(list, i * i);

puts("First five squares:");

// This value will be set by the loop.
int out_value;

list_iter_start(list, out_value) {
    printf("%d\n", out_value);
}
list_iter_end // This needs to be placed after each loop end.

int_list_free(list);

// Output:
// First five squares:
// 1
// 4
// 9
// 16
// 25
```

The first parameter is the list to iterate over and the second parameter should be a variable with the same type as the values held by the list. It should be safe to nest an iteration block inside of another.

It is safe to add items to the end of the list, but inserting or removing items is undefined behaviour.