cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
message(STATUS "Using CMake version ${CMAKE_VERSION}")

project(dsa
    VERSION 0.1.0
    DESCRIPTION "A template C project"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")
endif()

option(TEST_FLAG "Build tests" ON)
option(WERROR_FLAG "Treat warnings as errors" ON)
option(SANITIZERS_FLAG "Enable ASan/UBSan in Debug builds" ON)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE c_std_11)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(project_options INTERFACE
        -Wall -Wextra -Wpedantic -Wshadow -Wconversion
    )
    if(WERROR_FLAG)
        target_compile_options(project_options INTERFACE -Werror)
    endif()
    if(SANITIZERS_FLAG AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(project_options INTERFACE -fsanitize=address,undefined)
        target_link_options(project_options INTERFACE -fsanitize=address,undefined)
    endif()
elseif(MSVC)
    target_compile_options(project_options INTERFACE /W4)
    if(WERROR_FLAG)
        target_compile_options(project_options INTERFACE /WX)
    endif()
endif()

add_subdirectory(src)

if(TEST_FLAG)
    enable_testing()
    list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
    add_subdirectory(tests)
endif()
