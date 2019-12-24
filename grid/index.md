# Grid

The grid is a simple collection that helps with 2D array operations (note: not jagged arrays, but proper fixed width and height arrays).

When iterating through the grid, the outer loop should be the height and the inner loop should be the width for better cache locality.

## Syntax

```c
GRID_DEFINE_H(type_name, function_prefix, value_type)
GRID_DEFINE_C(type_name, function_prefix, value_type)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the grid functions with. |
| value_type | The value to be held by the grid. |

## Fields

These shouldn't be accessed directly (instead use the corresponding functions. They should be inlined), but they're documented in case they're needed (e.g. accessing the grid dimensions in a tight loop. Again, this should be inlined, so profile before accessing the field).

| Name | Type | Description |
| --- | --- | --- |
| grid | value_type* | The backing array of the grid. |
| width | unsigned int | The width of the grid. |
| height | unsigned int | The height of the grid. |

## Example

The following creates a grid of ints that can be used as a times table.

```c
GRID_DEFINE_H(IntGrid, int_grid, int)
GRID_DEFINE_C(IntGrid, int_grid, int)

IntGrid* grid = int_grid_create(12, 12);

for(int h = 0; h < int_grid_height(grid); h++) {
    for(int w = 0; w < int_grid_width(grid); w++) {
        int_grid_set(grid, w, h, w * h);
    }
}

int left = 6;
int right = 4;
int times = int_grid_get(grid, left, right);

assert(times == left * right);

int_grid_free(grid);
```