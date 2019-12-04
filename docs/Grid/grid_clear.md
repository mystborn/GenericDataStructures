---
tags: c grid
---
# grid_clear

Sets all of the locations in a grid to a default value.

## Syntax

```c
void grid_clear(Grid* grid, value_type default_value);
```

| Name | Type | Description |
| --- | --- | --- |
| grid | Grid* | A pointer to the grid. |
| default_value | value_type | The value to set each location to. |

## Example

```c
GRID_DEFINE_H(IntGrid, int_grid, int)
GRID_DEFINE_C(IntGrid, int_grid, int)

IntGrid* grid = int_grid_create(12, 12);

int_grid_clear(grid, 0);
```