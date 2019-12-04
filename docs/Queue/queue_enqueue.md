---
tags: c queue
---
# queue_enqueue

Adds an item to the end of the queue.

## Syntax

```c
bool queue_enqueue(Queue* queue, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| queue | Queue* | A pointer to the queue. |
| value | value_type | The value to add. |

**Returns:** `true` on success, `false` if the queue tried to resize and there was an allocation failure. Nothing in the queue will change if this happens.

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