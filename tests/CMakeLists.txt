set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/lib)

add_library(unity STATIC unity/unity.c)
target_include_directories(unity PUBLIC unity/ ${CMAKE_SOURCE_DIR}/include)

function(create_test test_name)
    add_executable(${test_name} ${test_name}.c ${ARGN})

    target_link_libraries(${test_name}
        PRIVATE
            utils
            algorithms
            data_structures
            project_options
            unity
    )
    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

create_test(test_insertion_sort)
create_test(test_linkedlist_int)
