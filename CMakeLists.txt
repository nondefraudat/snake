cmake_minimum_required(VERSION 3.17)

if (WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif ()

add_subdirectory(SDL)

add_subdirectory(core)
target_include_directories(core PUBLIC SDL/include/SDL)
target_link_libraries(core PUBLIC SDL3::SDL3)

add_subdirectory(game)
target_include_directories(game PRIVATE core/src)
target_link_libraries(game PRIVATE core)
