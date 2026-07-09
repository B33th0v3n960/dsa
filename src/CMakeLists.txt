set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

function(create_library lib_name)
    add_library(${lib_name} STATIC ${ARGN})
    target_include_directories(${lib_name}
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
    )
    target_link_libraries(${lib_name} PRIVATE project_options)
endfunction()

create_library(utils
    ./utils/print_array.c
)
create_library(insertion_sort ./algorithms/insertion_sort.c)

# buildin the main executable
add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        utils
        insertion_sort
        project_options
)

