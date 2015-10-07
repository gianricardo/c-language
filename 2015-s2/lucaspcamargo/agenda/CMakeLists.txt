cmake_minimum_required(VERSION 2.6)
project(agenda)

add_executable(agenda main.c)
add_definitions(-std=c11)

install(TARGETS agenda RUNTIME DESTINATION bin)

add_subdirectory(doc)
