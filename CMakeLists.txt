cmake_minimum_required(VERSION 3.17)

project(snake)

if (WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif ()

add_subdirectory(SDL)

add_subdirectory(core)
target_include_directories(core PUBLIC SDL/include/SDL)
target_link_libraries(core PUBLIC SDL3::SDL3)

add_subdirectory(game)
if (ANDROID)
    target_include_directories(main PRIVATE core/src)
    target_link_libraries(main PRIVATE core)
else ()
    target_include_directories(game PRIVATE core/src)
    target_link_libraries(game PRIVATE core)
endif ()
