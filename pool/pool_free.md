# pool_free

Frees the resources used by the pool, then frees the pool itself.

## Syntax

```c
void pool_free(Pool* pool);
```

| Name | Type | Description |
| --- | --- | --- |
| pool | Pool* | A pointer to the pool. |

## Remarks

Any resources used by the pool will be invalidated when this function is called, so make sure there are no more references to them beforehand.

## Example

```c
POOL_DEFINE_H(IntPool, int_pool, int)

// See the main page for the function implementations.
POOL_DEFINE_C(IntPool, int_pool, int, int_init, int_free_resources) 

IntPool* pool = int_pool_create();

// Use the pool...

int_pool_free(pool);
```