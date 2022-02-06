cmake_minimum_required(VERSION 3.17)

project(sci_calculator VERSION 0.1.0)


set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

set(SOURCE_FILES
		main.cpp
		src/calculator.cpp
		src/component/checker.cpp
		src/component/parser.cpp
		src/component/simplifier.cpp
		src/component/str_hdl.cpp
		src/func/sin_f.cpp
		src/manager/constant_manager.cpp
		src/manager/function_manager.cpp
		src/node/constant_node.cpp
		src/node/embedded_node.cpp
		src/node/function_node.cpp
		src/node/int_node.cpp
		src/node/math_node.cpp
		src/manager/tree_manager.cpp lib/manager/tree_manager.h src/node/node.cpp lib/node/node.h src/component/parser2.cpp lib/component/parser2.h)

add_executable(sci_calculator ${SOURCE_FILES})

#target_link_libraries(sci_calculator CalculatorLib)

include(CPack)
