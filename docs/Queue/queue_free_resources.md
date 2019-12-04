---
tags: c queue
---
# queue_free_resources

Frees the resources used by the queue without freeing the queue itself.

## Syntax

```c
void queue_free_resources(Queue* queue);
```

| Name | Type | Description |
| --- | --- | --- |
| queue | Queue* | A pointer to the queue. |

## Example

```c
QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

StringQueue queue;
str_queue_init(&queue);

// Use the queue...

str_queue_free_resources(&queue);
```