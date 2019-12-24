# queue_clear

Clears all values from the queue. Note that this does not free any of the values, nor does it affect the queues capacity.

## Syntax

```c
void queue_clear(Queue* queue);
```

| Name | Type | Description |
| --- | --- | --- |
| queue | Queue* | A pointer to the queue. |

## Example

```c
QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

StringQueue* queue = str_queue_create();

str_queue_enqueue(queue, "hello");
str_queue_enqueue(queue, "world");

assert(str_queue_count(queue) == 2);

str_queue_clear(queue);

assert(str_queue_count(queue) == 0);

str_queue_free(queue);

```