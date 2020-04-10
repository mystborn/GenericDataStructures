# pool_get

Gets a resource from the pool.

## Syntax

```c
value_type* pool_get(Pool* pool);
```

| Name | Type | Description |
| --- | --- | --- |
| pool | Pool* | A pointer to the pool. |

**Returns:** `value_type*` on success, `NULL` on failure.

The value will be initialized using the initialization function used to define the pool type.

## Example

```c
POOL_DEFINE_H(IntPool, int_pool, int)

// See the main page for the function implementations.
POOL_DEFINE_C(IntPool, int_pool, int, int_init, int_free_resources) 

IntPool* pool = int_pool_create();

// Here we retrieve a new int allocated by the pool.
int* value = int_pool_get(pool);
*value = 5;

printf("Value: %d\n", value);

int_pool_release(pool, value);

int_pool_free(pool);

// Output:
// Value: 5
```