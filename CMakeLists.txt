# set where final binary goes
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 4.2.3)
project(CSQL C)

add_executable(csql
    src/main.c
    src/file_handler.c
    src/input.c
    src/parser.c
    src/heap_err.c
    src/parser_handler.c
    src/create.c
)

add_compile_options(-Wall -Wextra)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
target_include_directories(csql PRIVATE include)