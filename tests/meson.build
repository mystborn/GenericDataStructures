check_lib = check_location + '/lib'

compat = c_comp.find_library(
    'compat',
    required: true,
    dirs: check_lib)

check = c_comp.find_library(
    'check',
    required: true,
    dirs: check_lib)

deps = [compat, check]
link_args = []

if c_comp.get_id() == 'msvc' and get_option('buildtype') == 'release'
    link_args += '/NODEFAULTLIB:MSVCRTD'
endif

rb_tree_test = executable(
    'rb_tree_test',
    'rb_tree_test.c',
    link_args: link_args,
    include_directories: test_inc,
    dependencies: deps
)

map_test = executable(
    'map_test',
    'map_test.c',
    link_args: link_args,
    include_directories: test_inc,
    dependencies: deps
)

set_test = executable(
    'set_test',
    'set_test.c',
    link_args: link_args,
    include_directories: test_inc,
    dependencies: deps
)

queue_test = executable(
    'queue_test',
    'queue_test.c',
    link_args: link_args,
    include_directories: test_inc,
    dependencies: deps
)

list_test = executable(
    'list_test',
    'list_test.c',
    link_args: link_args,
    include_directories: test_inc,
    dependencies: deps
)

grid_test = executable(
    'grid_test',
    'grid_test.c',
    link_args: link_args,
    include_directories: test_inc,
    dependencies: deps
)

test('RB Tree Test', rb_tree_test)
test('Map Test', map_test)
test('Set Test', set_test)
test('Queue Test', queue_test)
test('List Test', list_test)
test('Grid Test', grid_test)