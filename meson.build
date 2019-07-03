project('GenericDataStructures', 'c', version: '0.0.2', license: 'MIT')

c_comp = meson.get_compiler('c')

check_location = get_option('check_location')

include_files = ['include']

inc = include_directories(include_files)

if check_location != ''
    test_inc = include_directories(include_files + [check_location + '/include'])
endif

if check_location != ''
    subdir('tests')
endif