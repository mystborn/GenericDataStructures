---
tags: c queue
---
# queue_create

Allocates and initializes a new queue.

## Syntax

```c
Queue* queue_create(void);
```

**Returns:** A new queue on success, NULL on out of memory.

## Example

```c
QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

StringQueue* queue = str_queue_create();

// Use the queue...

str_queue_free(queue);
```