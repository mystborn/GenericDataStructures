# deque_free_resources

Frees the resources used internally by the deque without freeing the deque itself.

## Syntax

```c
void deque_free_resources(Deque* deque);
```

| Name | Type | Description |
| --- | --- | --- |
| deque | Deque* | A pointer to the deque. |

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)


// Create a deque on the stack.
IntDeque deque;
int_deque_init(&deque);

// Use the deque...

// Clean up the deque before going out of scope to
// to prevent a memory leak.
int_deque_free_resources(&deque);
```