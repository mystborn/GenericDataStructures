---
tags: c grid
---
# grid_get

Gets the value at the specified position in the grid.

Bounds checking is done via `assert`, so if it's needed in a production environment, it will need to be handled by the caller.

## Syntax

```c
value_type grid_get(Grid* grid, unsigned int x, unsigned int y);
```

| Name | Type | Description |
| --- | --- | --- |
| grid | Grid* | A pointer to the grid. |
| x | unsigned int | The x location of the grid. |
| y | unsigned int | the y location of the grid. |

**Returns:** value_type

## Example

```c
GRID_DEFINE_H(IntGrid, int_grid, int)
GRID_DEFINE_C(IntGrid, int_grid, int)

IntGrid* grid = int_grid_create(12, 12);

int_grid_clear(grid, 13);

int value = int_grid_get(grid, 1, 1);
assert(value == 13);
```