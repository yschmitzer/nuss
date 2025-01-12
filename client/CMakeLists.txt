cmake_minimum_required(VERSION 3.14)
project(client)

file(GLOB_RECURSE GAME_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
add_executable(${PROJECT_NAME} main.c ${GAME_SRC})
target_link_libraries(${PROJECT_NAME} raylib enet logger)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
