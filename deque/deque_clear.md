# deque_clear

Clears all elements from the deque.

## Syntax

```c
void deque_clear(Deque* deque, bool reset_capacity);
```

| Name | Type | Description |
| --- | --- | --- |
| deque | Deque* | A pointer to the deque. |
| reset_capacity | bool | Determines whether to reset the internal size of the deque or leave it as is. |

## Example

```c
DEQUE_DEFINE_H(IntDeque, int_deque, int)
DEQUE_DEFINE_C(IntDeque, int_deque, int)

IntDeque* deque = int_deque_create();

for(int i = 0; i < 30; i++)
    int_deque_push_front(deque, i);

printf("Count before clearing: %d\n", int_deque_count(deque));
printf("Capacity before clearing: %d\n", int_deque_capacity(deque));

// Clear the deque without clearing internal capacity.
int_deque_clear(deque, false);

printf("Count after clearing: %d\n", int_deque_count(deque));
printf("Capacity after clearing: %d\n", int_deque_capacity(deque));

// Output:
// Count before clearing: 30
// Capacity before clearing: 32
//
// Count after clearing: 0
// Capacity after clearing: 32

int_deque_free(deque);
```