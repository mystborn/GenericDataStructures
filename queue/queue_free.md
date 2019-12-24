# queue_free

Frees the resources used by the queue, then frees the queue itself.

## Syntax

```c
void queue_free(Queue* queue);
```

| Name | Type | Description |
| --- | --- | --- |
| queue | Queue* | A pointer to the queue. |

## Example

```c
QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

StringQueue* queue = str_queue_create();

// Use the queue...

str_queue_free(queue);
```