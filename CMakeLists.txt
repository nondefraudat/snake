cmake_minimum_required(VERSION 3.17)

if (WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif ()

add_subdirectory(SDL)

add_subdirectory(game)
target_include_directories(game PRIVATE SDL/include/SDL3)
target_link_libraries(game PRIVATE SDL3::SDL3)
