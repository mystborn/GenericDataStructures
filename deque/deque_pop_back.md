# deque_pop_back

Removes the item at the back of the deque.

## Syntax

```c
value_type deque_pop_back(Deque* deque);
```

| Name | Type | Description |
| --- | --- | --- |
| deque | Deque* | A pointer to the deque. |

**Returns:** The removed value.

## Remarks

Count checking is done via `assert`, so if it's needed in a production environment, it will need to be handled by the caller. The behaviour is otherwise undefined if you try and remove an item from an empty deque.

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque* deque = int_deque_create();

int_deque_push_front(deque, 10);
int_deque_push_back(deque, -10);

int first = int_deque_pop_back(deque);
int second = int_deque_pop_back(deque);

printf("First: %d\n", first);
printf("Second: %d\n", second);

// Output:
// First: -10
// Second: 10

int_deque_free(deque);
```