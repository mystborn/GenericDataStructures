# queue_peek

Gets the item that was first added to the queue without removing it.

Count checking is done via `assert`, so if it's needed in a production environment, it will need to be handled by the caller. The behaviour is otherwise undefined if you try and dequeue from and empty queue.

## Syntax

```c
value_type queue_peek(Queue* queue);
```

| Name | Type | Description |
| --- | --- | --- |
| queue | Queue* | A pointer to the queue. |

**Returns:** The item that was first added to the queue.

## Example

```c
QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

StringQueue* queue = str_queue_create();

str_queue_enqueue(queue, "hello");

char* value = str_queue_peek(queue);

assert(strcmp(value, "hello") == 0);
assert(str_queue_count(queue) == 1);

```