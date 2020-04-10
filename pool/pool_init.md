# pool_init

Initializes an existing pool.

## Syntax

```c
bool pool_init(Pool* pool);
```

| Name | Type | Description |
| --- | --- | --- |
| pool | Pool* | A pointer to the pool. |

**Returns:** `true` on success, `false` on allocation failure.

## Example

```c
POOL_DEFINE_H(IntPool, int_pool, int)

// See the main page for the function implementations.
POOL_DEFINE_C(IntPool, int_pool, int, int_init, int_free_resources) 

IntPool pool;
int_pool_init(&pool);

// Use the pool...

int_pool_free_resources(&pool);
```