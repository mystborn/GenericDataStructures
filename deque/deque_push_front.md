# deque_push_front

Adds an item to the front of the deque.

## Syntax

```c
bool deque_push_front(Deque* deque, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| deque | Deque* | A pointer to the deque. |
| value | value_type | The item to add. |

**Returns:** `true` on success, `false` if the deque tried to resize and there was an allocation failure. Nothing in the deque will change if this happens.

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque* deque = int_deque_create();

int_deque_push_front(deque, 5);
int_deque_push_front(deque, 6);
printf("Front: %d\n", int_deque_peek_front(deque));

// Output:
// Front: 6

int_deque_free(deque);
```