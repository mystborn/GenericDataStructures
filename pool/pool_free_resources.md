# pool_free_resources

Frees the resources used by the pool without freeing the pool itself.

## Syntax

```c
void pool_free_resources(Pool* pool);
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

IntPool pool;
int_pool_init(&pool);

// Use the pool...

int_pool_free_resources(&pool);
```