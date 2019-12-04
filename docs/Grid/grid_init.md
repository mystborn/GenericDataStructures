---
tags: c grid
---
# grid_init

Initializes a grid.

## Syntax

```c
bool grid_init(Grid* grid, unsigned int width, unsigned int height);
```

| Name | Type | Description |
| --- | --- | --- |
| grid | Grid* | A pointer to the grid. |
| width | unsigned int | The width of the grid. |
| height | unsigned int | The height of the grid. |

**Returns:** `true` on success, `false` when initialization fails due to being out of memory.

## Example

```c
GRID_DEFINE_H(IntGrid, int_grid, int)
GRID_DEFINE_C(IntGrid, int_grid, int)

IntGrid grid;
bool success = int_grid_init(&grid, 12, 12);
assert(success);

int_grid_free_resources(grid);
```