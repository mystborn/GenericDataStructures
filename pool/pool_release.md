# pool_release

Returns a resource to the pool.

## Syntax

```c
bool pool_release(Pool* pool, value_type* value);
```

| Name | Type | Description |
| --- | --- | --- |
| pool | Pool* | A pointer to the pool. |
| value | value_type* | A resource originally created by the pool. |

**Returns:** `true` on success, `false` if there was an allocation error.

## Example

```c
POOL_DEFINE_H(IntPool, int_pool, int)

// See the main page for the function implementations.
POOL_DEFINE_C(IntPool, int_pool, int, int_init, int_free_resources) 

IntPool* pool = int_pool_create();

int* value = int_pool_get(pool);
*value = 5;

printf("Value: %d\n", value);

// Here we release the resource back to the pool.
int_pool_release(pool, value);

int_pool_free(pool);

// Output:
// Value: 5
```