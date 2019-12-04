---
tags: c queue
---
# Queue

A queue is a data structure that adds and removes items in a First In First First Out order (e.g. the first item in the queue is the first item to be removed from it).

## Syntax

```c
QUEUE_DEFINE_H(type_name, function_prefix, value_type)
QUEUE_DEFINE_H(type_name, function_prefix, value_type)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the queue functions with. |
| value_type | The value to be held by the queue. |

## Fields

The fields on this type should definitely not be modified except in very specific circumstances. If you need to iterate over the queue, please use the `generic_iterators/queue_iterator.h` header instead of doing it manually.

| Name | Type | Description |
| --- | --- | --- |
| buffer | value_type\* | The backing array of the queue. These are not necessarily in the order that items were added, so don't get items from it directly. |
| count | unsigned int | The number of items in the queue. |
| capacity | unsigned int | The number of items the queue can potentially hold. |
| start | unsigned int | *reserved* |
| end | unsigned int | *reserved* |

## Example

```c
#include <stdio.h>

#include <generic_queue.h>

QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

StringQueue* queue = str_queue_create();

str_queue_enqueue(queue, "one");
str_queue_enqueue(queue, "two");
str_queue_enqueue(queue, "three");
str_queue_enqueue(queue, "four");

printf("Queue count: %d\n", str_queue_count(queue));
printf("First item: %s\n", str_queue_peek(queue));

while(queue_count(queue) > 0) {
    printf("%s\n", str_queue_dequeue(queue));
}

printf("Queue count: %d\n", str_queue_count(queue));

str_queue_free(queue);

// Output:
// Queue count: 4
// First item: one
// one
// two
// three
// four
// Queue count: 0
```

### Iterating

There is an extension that allows iterating over all of the values in the queue in the order in which they were added. This will not remove any of the values.

```c
#include <stdio.h>

#include <generic_queue.h>

// The extension is located here.
#include <generic_iterators/queue_iterator.h>

QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

StringQueue* queue = str_queue_create();

str_queue_enqueue(queue, "one");
str_queue_enqueue(queue, "two");
str_queue_enqueue(queue, "three");
str_queue_enqueue(queue, "four");


// This will be set by the loop.
char* value;

// Start the iteration
queue_iter_start(queue, value) {
    // Use the current value.
    printf("%s\n", queue);
} 
queue_iter_end // End the iteration

// Output:
// one
// two
// three
// four
```

Just like with the other iterators, you can use `break` and `continue` like you would with any c loop.