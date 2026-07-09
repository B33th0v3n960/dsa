set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(lib${PROJECT_NAME}
    main.c
)

target_include_directories(lib${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(lib${PROJECT_NAME} PRIVATE project_options)
set_target_properties(lib${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# buildin the main executable
add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        lib${PROJECT_NAME} 
        project_options
)

