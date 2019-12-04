---
tags: c queue
---
# queue_create_capacity

Allocates and initializes a queue with the specified initial capacity.

## Syntax

```c
Queue* queue_create_capacity(unsigned int capacity);
```

| Name | Type | Description |
| --- | --- | --- |
| capacity | unsigned int | The initial capacity of the queue. |

**Returns:** A new queue on success, NULL on allocation failure.

## Example

```c
QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

// Creates a queue large enough to hold at least 100 strings without resizing.
StringQueue* queue = str_queue_create_capacity(100);

// Use the queue

str_queue_free(queue);
```