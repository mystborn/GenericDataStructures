---
tags: c queue
---
# queue_dequeue

Removes the item that was first added to the queue.

Count checking is done via `assert`, so if it's needed in a production environment, it will need to be handled by the caller. The behaviour is otherwise undefined if you try and dequeue from and empty queue.

## Syntax

```c
value_type queue_dequeue(Queue* queue);
```

| Name | Type | Description |
| --- | --- | --- |
| queue | Queue* | A pointer to the queue. |

**Returns:** The value that was most recently added to the queue.

## Example

```c
QUEUE_DEFINE_H(StringQueue, str_queue, int)
QUEUE_DEFINE_C(StringQueue, str_queue, int)

StringQueue* queue = str_queue_create();

str_queue_enqueue(queue, "hello");
str_queue_enqueue(queue, " world");

while(str_queue_count(queue) > 0) {
    char* value = str_queue_dequeue(queue);
    printf("%s", value);
}

printf("\n");

str_queue_free(queue);

// Output:
// hello world
```