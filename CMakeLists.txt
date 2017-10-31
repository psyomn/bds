cmake_minimum_required(VERSION 2.8)
project(bds)

# Took some many of these parts for cmake off
#   https://github.com/RAttab/optics

enable_testing()

add_definitions("-Wall")
add_definitions("-Wextra")
add_definitions("-Wundef")
add_definitions("-Wformat=2")
add_definitions("-Winit-self")
add_definitions("-Wcast-align")
add_definitions("-Wswitch-enum")
add_definitions("-Wwrite-strings")
add_definitions("-Wswitch-default")
add_definitions("-Wunreachable-code")
add_definitions("-Wno-strict-aliasing")
add_definitions("-Wno-format-nonliteral")
add_definitions("-Wno-missing-field-initializers")
add_definitions("-pipe -g -O3 -Werror -march=native")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -std=gnu11")

set(BDS_SOURCES
    src/linked_list.c)

add_library(bds STATIC ${BDS_SOURCES})

include_directories(include)

add_executable(llist_example test/llist_example.c)
target_link_libraries(llist_example bds)
