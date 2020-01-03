# deque_init_capacity

Initializes an existing deque with the specified starting capacity.

## Syntax

```c
bool deque_init_capacity(Deque* deque, unsigned int capacity);
```

| Name | Type | Description |
| --- | --- | --- |
| deque | Deque* | A pointer to the deque. |
| capacity | unsigned int | The desired starting capacity by # of elements. |

**Returns:** `true` if the deque was initialized, `false` if there wasn't enough memory.

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque deque;
int_deque_init_capacity(&deque, 32);

printf("Capacity: %d\n", int_deque_capacity(&deque));

// Output:
// Capacity: 32

int_deque_free_resources(deque);
```