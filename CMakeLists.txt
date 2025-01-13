cmake_minimum_required(VERSION 3.14)
project(nuss VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(shared)
add_library(logger shared/logger.c)

add_subdirectory(external/raylib EXCLUDE_FROM_ALL)
add_subdirectory(external/enet EXCLUDE_FROM_ALL)
include_directories(${enet_SOURCE_DIR}/include)

file(GLOB_RECURSE SERVER_SRC CONFIGURE_DEPENDS "server/src/*.c")
add_executable(server server/main.c ${SERVER_SRC})
target_link_libraries(server enet logger)

file(GLOB_RECURSE CLIENT_SRC CONFIGURE_DEPENDS "client/src/*.c")
add_executable(client client/main.c ${CLIENT_SRC})
target_link_libraries(client raylib enet logger)
