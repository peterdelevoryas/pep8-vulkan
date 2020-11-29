cmake_minimum_required(VERSION 3.19)
project(pep8-vulkan)
find_package(Vulkan REQUIRED)
add_library(pep8-vulkan INTERFACE)
target_include_directories(pep8-vulkan INTERFACE .)
target_link_libraries(pep8-vulkan INTERFACE Vulkan::Vulkan)

add_executable(example example.c)
target_link_libraries(example PRIVATE pep8-vulkan)

enable_testing()
add_test(NAME example.c COMMAND ${CMAKE_CURRENT_BINARY_DIR}/example)
