# grid_free

Frees the resources used by the grid, then frees the grid.

## Syntax

```c
void grid_free(Grid* grid);
```

| Name | Type | Description |
| --- | --- | --- |
| grid | Grid* | A pointer to the grid. |

## Example

```c
GRID_DEFINE_H(IntGrid, int_grid, int)
GRID_DEFINE_C(IntGrid, int_grid, int)

IntGrid* grid = int_grid_create(12, 12);

// Use the grid...

int_grid_free(grid);
```