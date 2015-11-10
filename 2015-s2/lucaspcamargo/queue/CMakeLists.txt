cmake_minimum_required(VERSION 2.8)

project(queue)

add_executable(test test.c queue.c)

install(TARGETS test RUNTIME DESTINATION bin)
