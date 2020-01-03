# deque_create

Allocates and initializes a new deque.

## Syntax

```c
Deque* deque_create();
```

**Returns:** The newly created deque on success, `NULL` on failure.

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque* deque = int_deque_create();

// Use the deque...

int_deque_free(deque);
```