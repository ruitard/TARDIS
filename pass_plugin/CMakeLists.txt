cmake_minimum_required(VERSION 3.20.0)
project(pass_plugin VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_library(host SHARED pass.cpp)
add_library(pass SHARED pass_plugin.cpp)
target_link_libraries(host PRIVATE pass)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE host)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
