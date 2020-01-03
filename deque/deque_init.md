# deque_init

Initializes an existing deque.

## Syntax

```c
bool deque_init(Deque* deque);
```

| Name | Type | Description |
| --- | --- | --- |
| deque | Deque* | A pointer to the deque. |

**Returns:** `true` if the deque was initialized, `false` if there wasn't enough memory.

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque deque;
int_deque_init(&deque);

// Use the deque...

int_deque_free_resources(deque);
```