set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/lib)

add_library(unity STATIC unity/unity.c)
target_include_directories(unity PUBLIC unity/)

function(add_myproject_test test_name)
    add_executable(${test_name} ${test_name}.c ${ARGN})
    target_link_libraries(${test_name}
        PRIVATE
            ${PROJECT_NAME}_lib
            project_options
            unity
    )
    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

# add_myproject_test(test_name)
