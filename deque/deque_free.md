# deque_free

Frees the reources used by the deque, then frees the deque itself.

## Syntax

```c
void deque_free(Deque* deque);
```

| Name | Type | Description |
| --- | --- | --- |
| deque | Deque* | A pointer to the deque. |

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque* deque = int_deque_create();

// Use the deque...

int_deque_free(deque);
```