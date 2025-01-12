cmake_minimum_required(VERSION 3.14)
project(nuss VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add own libraries
include_directories(${CMAKE_SOURCE_DIR}/shared)
add_library(logger shared/logger.c)

# Add third-party libraries
# include_directories(${CMAKE_SOURCE_DIR}/third_party)
# add_library(raylib third_party/raylib/src)
# add_library(enet third_party/enet/include/enet)
add_subdirectory(third_party/raylib EXCLUDE_FROM_ALL)
add_subdirectory(third_party/enet EXCLUDE_FROM_ALL)
include_directories(${enet_SOURCE_DIR}/include)

add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(tests)


# # Add third-party libraries
# add_subdirectory(third_party/raylib)
# add_subdirectory(third_party/enet)
#
# # Shared library
# add_library(shared STATIC
#     shared/logger.c
# )
# target_include_directories(shared PUBLIC shared)
#
# # Client executable
# add_executable(client
#     client/main.c
# )
# target_link_libraries(client PRIVATE raylib enet shared)
# target_include_directories(client PRIVATE third_party/enet/include)
#
# # Server executable
# add_executable(server
#     server/main.c
# )
# target_link_libraries(server PRIVATE enet shared)
# target_include_directories(server PRIVATE third_party/enet/include)
#
# # Tests executable
# add_executable(tests
#     tests/main.c
# )
# target_link_libraries(tests PRIVATE shared)
# target_include_directories(tests PRIVATE shared)

# # Enable testing
# enable_testing()
# add_test(NAME protocol_test COMMAND tests)

