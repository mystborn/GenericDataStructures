---
tags: c queue
---
# queue_init_capacity

Initializes a queue and makes sure it has a large enough capacity to hold the specified number of items.

## Syntax

```c
bool queue_init_capacity(Queue* queue, unsigned int capacity);
```

| Name | Type | Description |
| --- | --- | --- |
| queue | Queue* | A pointer to the queue. |
| capacity | unsigned int | The initial capacity to allocate. |

**Returns:** `true` on success, `false` on allocation failure.

## Example

```c
QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

// Initializes a queue that can hold at least 100 strings.

StringQueue queue;
str_queue_init_capacity(&queue, 100);

// Use the queue...

str_queue_free_resoures(&queue);
```