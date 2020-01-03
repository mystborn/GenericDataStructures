# deque_create_capacity

Allocates and initializes a deque with the specified starting capacity.

## Syntax

```c
Deque* deque_create_capacity(unsigned int capacity);
```

| Name | Type | Description |
| --- | --- | --- |
| capacity | unsigned int | The desired starting capacity by # of elements. |

**Returns:** A newly created deque on success, `NULL` on failure.

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque* deque = int_deque_create_capacity(15);

printf("Capacity: %d\n", int_deque_capacity(deque));

// Output:
// Capacity: 15

int_deque_free(deque);
```