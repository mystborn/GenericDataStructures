---
tags: c grid
---
# grid_create

Allocates and initializes a new grid.

## Syntax

```c
Grid* grid_init(unsigned int width, unsigned int height);
```

| Name | Type | Description |
| --- | --- | --- |
| width | unsigned int | The width of the grid. |
| height | unsigned int | The height of the grid. |

**Returns:** New grid on success, NULL on out of memory.

## Example

```c
GRID_DEFINE_H(IntGrid, int_grid, int)
GRID_DEFINE_C(IntGrid, int_grid, int)

IntGrid* grid = grid_create(12, 12);
assert(grid);


// Use grid...

int_grid_free(grid);
```