# deque_capacity

Gets the number of elements the deque can hold without resizing.

## Syntax

```c
unsigned int deque_capacity(Deque* deque);
```

| Name | Type | Description |
| --- | --- | --- |
| deque | Deque* | A pointer to the deque. |

**Returns:** The size of the deques internal buffer.

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque* deque = int_deque_create();

printf("Capacity: %d\n", int_deque_capacity(deque));

// Outputs:
// Capacity: 4

int_deque_free(deque);
```