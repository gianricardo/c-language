cmake_minimum_required(VERSION 2.8)

project(stack)

add_executable(stacktest stacktest.c stack.c)
add_executable(dectobin dectobin.c stack.c)

install(TARGETS stacktest RUNTIME DESTINATION bin)
