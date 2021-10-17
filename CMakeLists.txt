cmake_minimum_required(VERSION 3.17)
project(sci_calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(managers/lib)
include_directories(node/lib)

add_executable(sci_calculator
        managers/lib/constant_manager.h
        managers/src/constant_manager.cpp
        node/lib/constant_node.h
        node/lib/embeded_node.h
        node/lib/function_node.h
        node/lib/int_node.h
        node/lib/math_node.h
        node/src/constant_node.cpp
        node/src/embeded_node.cpp
        node/src/function_node.cpp
        node/src/int_node.cpp
        node/src/math_node.cpp
        includes.h
        main.cpp
        parser.cpp
        parser.h)
