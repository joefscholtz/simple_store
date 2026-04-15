cmake_minimum_required(VERSION 3.10)
project(simple_store VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

set(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
add_definitions(-DPROJECT_ROOT_PATH="${PROJECT_ROOT}")

add_executable(simple_store src/main.c src/store.c src/io.c)
