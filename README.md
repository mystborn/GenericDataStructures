# Generic Data Structures

Generic Data Structures is a header-only project in C that can be used to generate strongly typed Data Structures, mostly various collection types. It works similar to c++ templates.

The following collections are currently implemented:
* [List](https://mystborn.github.io/GenericDataStructures/list/)
* [Map](https://mystborn.github.io/GenericDataStructures/map/)
* [Queue](https://mystborn.github.io/GenericDataStructures/queue/)
* [Red Black Tree](https://mystborn.github.io/GenericDataStructures/redblacktree/)
* [Set](https://mystborn.github.io/GenericDataStructures/set/)
* [Grid](https://mystborn.github.io/GenericDataStructures/grid/)

There a number of collections I'd like to add. If you want to contribute, please check the [todo list](https://github.com/mystborn/GenericDataStructures/blob/master/todolist.txt) to see what is currently pending implementation.

## Usage

*For more information, please view the [documentation website](https://mystborn.github.io/GenericDataStructures/)*

All of the data structures are split into two macros. One generally goes into a header file, and the other into a source file. The header macro can be placed in the same source file as the source macro if the data structure will only be used in that file. For example, the list macros are `LIST_DEFINE_H` for the header and `LIST_DEFINE_C` for the source.

Here's an example that creates and uses a list of ints:

```c
// main.h
#include <generic_list.h>

// The first argument is the name of the generated data structure,
// the second argument is a name to prefix each function with,
// and the final argument is the value stored by the list, in this
// case int.

LIST_DEFINE_H(IntList, int_list, int)


// main.c

#include "main.h"

LIST_DEFINE_C(IntList, int_list, int)

int main(void) {
    IntList* list = int_list_create();

    // Add the square of the number 0..9
    for(int i = 0; i < 10; i++)
        int_list_add(list, i * i);

    // Print the squares
    for(int i = 0; i < int_list_count(list); i++)
        printf("%d^2 = %d\n", i, int_list_get(list, i));

    int_list_free(list);

    return 0;
}
```

## Including

This is a header-only project, so for the most part all you need to do is clone the repo to a subdirectory and at it to your include lists. If you're using meson, you can subproject easily like so:

##### Wrap File:

```ini
[wrap-git]
directory = GenericDataStructures
url = https://github.com/mystborn/GenericDataStructures
revision = master
```

##### Meson:

```meson
GenericDataStructures = subproject('GenericDataStructures')

# Pass this with the rest of your dependencies when creating the library/executable.
GenericDataStructures_dep = GenericDataStructures.get_variable('GenericDataStructures_dep')
```

## Building

As this is a header-only project, it doesn't need to be built. There are some tests included that will need to be built however. This project uses meson to build by default. The tests use the [check](https://libcheck.github.io/check/) unit testing framework. On windows, you'll need to specify where the library is. On linux, as long as it's installed normally, they'll be built automatically. To specify the location, use the `check_location` configuration option. Most likely installed at `C:\Program Files (x86)\check`.

```sh
mkdir build
cd build
meson ..
meson configure "-Dcheck_location=C:\Program Files (x86)\check"
ninja test
```