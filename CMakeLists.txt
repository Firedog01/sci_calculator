cmake_minimum_required(VERSION 3.0.0)
project(sci_calculator VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB CSI_SRC
     "*.h"
     "*.cpp"
)

add_executable(sci_calculator ${CSI_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
