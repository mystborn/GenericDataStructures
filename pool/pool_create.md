# pool_create

Allocates and initializes a new pool.

## Syntax

```c
Pool* pool_create(void);
```

**Returns:** A new pool on success, `NULL` on allocation failure.

## Example

```c
POOL_DEFINE_H(IntPool, int_pool, int)

// See the main page for the function implementations.
POOL_DEFINE_C(IntPool, int_pool, int, int_init, int_free_resources) 

IntPool* pool = int_pool_create();

// Use the pool...

int_pool_free(pool);
```