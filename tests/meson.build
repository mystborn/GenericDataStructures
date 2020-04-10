if check_location != ''
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
else
    check = c_comp.find_library('check', required: true)
    test_inc = inc
    deps = [check]
endif

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

deque_test = executable(
    'deque_test',
    'deque_test.c',
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

pool_test = executable(
    'pool_test',
    'pool_test.c',
    link_args: link_args,
    include_directories: test_inc,
    dependencies: deps
)

event_test = executable(
    'event_test',
    'event_test.c',
    link_args: link_args,
    include_directories: test_inc,
    dependencies: deps
)

trie_test = executable(
    'trie_test',
    'trie_test.c',
    link_args: link_args,
    include_directories: test_inc,
    dependencies: deps
)

option_test = executable(
    'option_test',
    'option_test.c',
    link_args: link_args,
    include_directories: test_inc,
    dependencies: deps
)

test('RB Tree Test', rb_tree_test)
test('Map Test', map_test)
test('Set Test', set_test)
test('Queue Test', queue_test)
test('Deque Test', deque_test)
test('List Test', list_test)
test('Grid Test', grid_test)
test('Pool Test', pool_test)
test('Event Test', event_test)
test('Trie Test', trie_test)
test('Option Test', option_test)