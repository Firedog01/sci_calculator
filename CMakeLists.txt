cmake_minimum_required(VERSION 3.17)
project(sci_calculator VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
        src/parser.cpp
        src/func/abstract_function.cpp
        src/func/sin.cpp
        src/manager/constant_manager.cpp
        src/manager/function_manager.cpp
        src/manager/tree_manager.cpp
        src/node/constant_node.cpp
        src/node/embedded_node.cpp
        src/node/function_node.cpp
        src/node/int_node.cpp
        src/node/math_node.cpp
        )

add_executable(sci_calculator ${SOURCE_FILES})

#target_link_libraries(sci_calculator CalculatorLib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
