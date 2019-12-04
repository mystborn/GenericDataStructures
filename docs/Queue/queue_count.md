---
tags: c queue
---
# queue_count

Gets the number of items in the queue.

## Syntax

```c
unsigned int queue_count(Queue* queue);
```

| Name | Type | Description |
| --- | --- | --- |
| queue | Queue* | A pointer to the queue. |

**Returns:** The number of items in the queue.

## Example

```c
QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

StringQueue* queue = str_queue_create();

str_queue_enqueue(queue, "hello");
str_queue_enqueue(queue, "world");

unsigned int count = str_queue_count(queue);
assert(count == 2);

str_queue_free(queue);
```