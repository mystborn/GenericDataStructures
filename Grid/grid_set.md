# grid_set

Sets the value at the specified loaction in the grid.

Bounds checking is done via `assert`, so if it's needed in a production environment, it will need to be handled by the caller.

## Syntax

```c
void grid_set(Grid* grid, unsigned int x, unsigned int y, value_type value);
```

| Name | Type | Description |
| --- | --- | --- |
| grid | Grid* | A pointer to the grid. |
| x | unsigned int | The x location of the grid. |
| y | unsigned int | the y location of the grid. |
| value | value_type | The value to set the location to. |

## Example

```c
GRID_DEFINE_H(IntGrid, int_grid, int)
GRID_DEFINE_C(IntGrid, int_grid, int)

IntGrid* grid = int_grid_create(12, 12);

for(int h = 0; h < int_grid_height(grid); h++) {
    for(int w = 0; w < int_grid_width(grid); w++) {
        int_grid_set(grid, w, h, w * h);
    }
}
```