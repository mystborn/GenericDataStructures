---
tags: c queue
---
# queue_init

Initializes a queue.

## Syntax

```c
bool queue_init(Queue* queue);
```

| Name | Type | Description |
| --- | --- | --- |
| queue | Queue* | A pointer to the queue. |

**Returns:** `true` on success, `false` on allocation failure.

## Example

```c
QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

StringQueue queue;
str_queue_init(&queue);

// Use the queue...

str_queue_free_resources(&queue);
```