cmake_minimum_required(VERSION 3.14)

project("snake")

add_subdirectory("deps/SDL")

file(GLOB PROJECT_SOURCES "src/*")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "deps/SDL/include")
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMAND_EXPAND_LISTS)
