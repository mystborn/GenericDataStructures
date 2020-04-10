# Pool

A [pool](https://en.wikipedia.org/wiki/Object_pool_pattern) is a specialized allocation mechanism that creates objects with the intent of reusing them in the future.

## Syntax

```c
POOL_DEFINE_H(type_name, function_prefix, value_type)
POOL_DEFINE_C(type_name, function_prefix, value_type, init_fn, free_resource_fn)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the pool functions with. |
| value_type | The type of value to pool. |
| init_fn | A function to initialize the value with when it is retrieved. |
| free_resources_fn | A function to free any resources used by the value when it is stored back in the pool. |

The functions should have the following signatures:

```c
void init_fn(value_type* value);
void free_resources_fn(value_type* value);
```

They should not modify the pointer itself, just its contents.

## Remarks

By default, the pool will check that a [released]({{site.baseurl}}/pool/pool-release) value was actually created by the pool. If you wish to bypass this check, in the source file that creates the pool type, define `POOL_SKIP_RELEASE_ASSERT` before including `generic_pool.h`. This will improve performance, which is generally the reason for this type to begin with, at the cost of some safety.

## Fields

These fields shouldn't be accessed directly, but they're documented just in case.

This data type creates an additional type `struct <type_name>Node` where `type_name` is the generated pools name.

__struct PoolNode:__

| Name | Type | Description |
| --- | --- | --- |
| buffer | value_type* | A list of the values allocated by this node. |
| next | struct PoolNode* | A pointer to the next node. |

__Pool:__

| Name | Type | Description |
| --- | --- | --- |
| node | struct PoolNode* | The node currently being used to get values from. |
| open | value_type** | The currently available values. |
| open_count | unsigned int | The number of values currently available. |
| open_capacity | unsigned int | The number of open values that can be held before resizing the open buffer. |
| next | unsigned int | The number of values retrieved from the current node. |
| node_capacity | unsigned int | The number of values allocated by the current node. |
| total | unsigned int | The total number of allocated values. |

## Example

This example is a bit contrived, but it creates a pool of ints, gets and releases them, then free the pool.

```c
#include <generic_pool.h>

static void int_init(int* value) {
    *value = 0;
}

static void int_free_resources(int* value) {
    // No action needed...
}

POOL_DEFINE_H(IntPool, int_pool, int)
POOL_DEFINE_C(IntPool, int_pool, int, int_init, int_free_resources) 

IntPool* pool = int_pool_create();

int* value = int_pool_get(pool);
*value = 5;

printf("Value: %d\n", value);

int* address = value;

int_pool_release(pool, value);

value = int_pool_get(pool);

printf("Value was reused? %s\n", value == address ? "true" : "false");

int_pool_free(pool);

// Output:
// Value: 5
// Value was reused? true
```