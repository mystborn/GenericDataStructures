# Deque

A [deque (double ended queue)](https://en.wikipedia.org/wiki/Double-ended_queue) is a collection that can efficiently add or remove items from both the start and the end of it.

## Syntax

```c
DEQUE_DEFINE_H(type_name, function_prefix, value_type)
DEQUE_DEFINE_C(type_name, function_prefix, value_type)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the deque functions with. |
| value_type | The value to be held by the deque. |

## Fields

The fields of this type generally should not be modified directly. If you need to iterate over the deque, please use the `generic_iterators/deque_iterator.h` header instead of doing it manually.

| Name | Type | Description |
| --- | --- | --- |
| buffer | value_type* | The backing array of the deque. These are not necessarily in the order that the items were added. |
| count | unsigned int | The number of items in the deque. |
| capacity | unsigned int | The number of items the deque can potentially hold without resizing. |
| start | unsigned int | *reserved* |
| end | unsigned int | *reserved* |

## Example

```c
#include <stdio.h>

#include <generic_deque.h>

DEQUE_DEFINE_H(StringDeque, str_deque, char*)
DEQUE_DEFINE_C(StringDeque, str_deque, char*)

StringDeque* deque = str_deque_create();

str_deque_push_back("world!");

str_deque_push_front(" ");
str_deque_push_front("Hello");

printf("Count: %d\n", str_deque_count(deque));
printf("Front: %s\n", str_deque_peek_front(deque));
printf("Back: %s\n", str_deque_peek_back(deque));

while(str_deque_count(deque) > 0) {
    printf("%s", str_deque_pop_front(deque));
}

printf("Count: %d\n", str_deque_count(deque));

str_deque_free(deque);

// Output:
// Count: 3
// Front: Hello
// Back: world!
// Hello world!
// Count: 0
```

### Iterating

There is an extension that allows iterating over all of the values in the deque from front to back. This will not remove any of the values.

```c
#include <stdio.h>

#include <generic_deque.h>

// The extension is located here.
#include <generic_iterators/deque_iterator.h>

DEQUE_DEFINE_H(StringDeque, str_deque, char*)
DEQUE_DEFINE_C(StringDeque, str_deque, char*)

StringDeque* deque = str_deque_create();

str_deque_push_back(deque, "three");
str_deque_push_back(deque, "four");

str_deque_push_front(deque, "two");
str_deque_push_front(deque, "one");

// This will be set by the loop.
char* value;


// Start the iteration
deque_iter_start(deque, value) {
    printf("%s\n", value);
}
deque_iter_end // End the iteration

str_deque_free(deque);

// Output:
// one
// two
// three
// four
```

Just like with the other iterators, you can use `break` and `continue` like you would with any c loop.