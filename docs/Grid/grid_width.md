---
tags: c grid
---
# grid_width

Gets the width of the grid.

## Syntax

```c
unsigned int grid_width(Grid* grid);
```

| Name | Type | Description |
| --- | --- | --- |
| grid | Grid* | A pointer to the grid. |

**Returns:** The width of the grid.

## Example

```c
GRID_DEFINE_H(IntGrid, int_grid, int)
GRID_DEFINE_C(IntGrid, int_grid, int)

IntGrid* grid = int_grid_create(12, 12);

unsigned int width = int_grid_width(grid);
assert(width == 12);
```