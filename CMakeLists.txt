cmake_minimum_required(VERSION 3.3)
project(hash_table)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES hash_table.c hash_table_test.c)
add_executable(hash_table ${SOURCE_FILES})