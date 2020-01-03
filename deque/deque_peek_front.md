# deque_peek_front

Gets the value at the front of the deque without removing it.

## Syntax

```c
value_type deque_peek_front(const Deque* deque);
```

| Name | Type | Description |
| --- | --- | --- |
| deque | const Deque* | A pointer to the deque. |

**Returns:** The value from the front of the deque.

## Remarks

Count checking is done via `assert`, so if it's needed in a production environment, it will need to be handled by the caller. The behaviour is otherwise undefined if you try and get an item from an empty deque.

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque* deque = int_deque_create();

int_deque_push_front(deque, 1);

int value = int_deque_peek_front(deque);

printf("Front: %d\n", value);

// Output:
// Front: 1

int_deque_free(deque);
```