---
tags: c grid
---
# grid_height

Gets the height of a grid.

## Syntax

```c
unsigned int grid_height(Grid* grid);
```

| Name | Type | Description |
| --- | --- | --- |
| grid | Grid* | A pointer to the grid. |

**Returns:** The height of the grid.

## Example

```c
GRID_DEFINE_H(IntGrid, int_grid, int)
GRID_DEFINE_C(IntGrid, int_grid, int)

IntGrid* grid = int_grid_create(12, 12);

unsigned int height = int_grid_height(grid);
assert(height == 12);
```