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
    ./utils/array_utils.c
    ./utils/swap.c
)

create_library(algorithms 
    ./algorithms/insertion_sort.c
)
target_link_libraries(algorithms PRIVATE utils project_options)

create_library(data_structures
    ./data_structures/linkedlist_int.c
)
target_link_libraries(algorithms PRIVATE project_options)

# buildin the main executable
add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        utils
        algorithms
        project_options
)

