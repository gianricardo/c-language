cmake_minimum_required(VERSION 2.6)

project(agenda LANGUAGES C)
set(PROJECT_VERSION 0.1)

set(CMAKE_BUILD_TYPE Debug)

add_executable(agenda main.c common.c contact.c contactlist.c)
add_definitions(-std=c11 -Wall)

install(TARGETS agenda RUNTIME DESTINATION bin)

add_subdirectory(doc)