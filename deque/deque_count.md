# deque_count

Gets the number of items currently in the deque.

## Syntax

```c
unsigned int deque_count(const Deque* deque);
```

| Name | Type | Description |
| --- | --- | --- |
| deque | const Deque* | A pointer to the deque. |

**Returns:** The number of items in the deque.

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque* deque = int_deque_create();

for(int i = 0; i < 10; i++)
    int_deque_push_back(deque, i);

int count = int_deque_count(deque);

printf("Count: %d\n", count);

// Output:
// Count: 10

int_deque_free(deque);
```