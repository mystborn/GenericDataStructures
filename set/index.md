# Set

A [set](https://en.wikipedia.org/wiki/Set_%28mathematics%29) is collection of unique values. It also has some [unique operations](https://en.wikipedia.org/wiki/Set_%28mathematics%29#Basic_operations) for creating new sets from given sets. These values are not sorted in any way, which allows for most operations to be performed quicker.

## Syntax

```c
SET_DEFINE_H(type_name, function_prefix, value_type)
SET_DEFINE_C(type_name, function_prefix, value_type, hash_fn, compare_fn)
```

| Name | Description |
| --- | --- |
| type_name | The name of the generated type. |
| function_prefix | The name to prefix the set functions with. |
| value_type | The values held in the set. |
| hash_fn | A function that takes a value and hashes it. |
| compare_fn | A function that compares two values. |

## Remarks

Unlike most of the other collections, if you wish to just use the set header, you must also copy the `generic_hash_utils.h` header as well. It contains some utility functions shared by a couple of the data structures, as well as a string hash function (`gds_fnv32`) so you don't have to write one when using `char*` as the set value.


## Fields

These shouldn't be accessed directly (instead use the corresponding functions. They should be inlined), but they're documented in case they're needed. This data type actually creates two structs. The first one is `<type_name>Cell` where `<type_name>` will be replaced by the name of the set type.

__Cell:__

| Name | Type | Description |
| --- | --- | --- |
| value | value_type | The value held by the cell. |
| hash | uint32_t | The hash value of the cells value. |
| active | bool | Determines if the cell is in use. |

__Map:__

| Name | Type | Description |
| --- | --- | --- |
| cells | SetCell* | An array of cells. |
| count | uint32_t | The number of items in the set. |
| capacity | uint32_t | The number of allocated cells. |
| load_factor | uint32_t | The number of active cells that can be held by the set before resizing. |
| shift | uint32_t | *reserved* |

## Example

The following creates a two sets of numbers, then performs some special operations using them.

```c
#include <generic_set.h>

// The comparison function used by the tree.
static int int_cmp(int left, int right) {
    return left < right ? -1 : (left > right ? 1 : 0); 
}

static uint32_t int_hash(int value) { return (uint32_t)value; }

SET_DEFINE_H(IntSet, int_set, int)
SET_DEFINE_C(IntSet, int_set, int, int_hash, int_cmp)

IntSet* left = int_set_create();
IntSet* right = int_set_create();

// Populate left
for(int i = 0; i < 7; i++)
    int_set_add(left, i);

// Populate right.
for(int i = 3; i < 10; i++)
    int_set_add(right, i);


// Get the union of the two sets (all of the numbers that are in either set)
IntSet* union_result = int_set_create();
int_set_union(left, right, union_result);

for(int i = 0; i < 10; i++) {
    // The union result contains all of these numbers.
    assert(int_set_contains(union_result, i));
}

int_set_free(union_result);

// Get the intersection of the two sets (all of the numbers that are in both sets)

IntSet* intersect = int_set_create();
int_set_intersect(left, right, intersect);

printf("%d\n", int_set_contains(intersect, 0));
printf("%d\n", int_set_contains(intersect, 5));
printf("%d\n", int_set_contains(intersect, 9));

int_set_free(intersect);

// Output:
// 0
// 1
// 0

// Get the complement of the two sets (all of the numbers only in left)
IntSet* complement = int_set_create();
int_set_complement(left, right, complement);

printf("%d\n", 0);
printf("%d\n", 5);
printf("%d\n", 9);

int_set_free(complement);

// Output:
// 1
// 0
// 0
```

### Iterating

There is an extension that allows for iterating over the items in a set in a random order. It's meant to be used like a for loop.

Mod

```c
#include <generic_set.h>
#include <generic_iterators/set_iterator.h>

SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

StringSet* set = str_set_create();

str_set_add(set, "moo");
str_set_add(set, "caw");
str_set_add(set, "nyan");
str_set_add(set, "woof");

// This will get set by the iterator
char* sound;

set_iter_start(set, sound) {
    printf("%s\n", sound);
}
set_iter_end

string_set_free(set);

// Possible Output:
// caw
// woof
// nyan
// moo
```

The first parameter is the set to iterate over and the second parameter should be a variable with the same type as the values held by the set. It should be safe to nest an iteration block inside of another.

It is not allowed to modify the set at all during iteration.