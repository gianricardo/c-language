cmake_minimum_required(VERSION 2.6)
project(somador)

add_executable(somador main.c bit.c port.c bitadder.c)

install(TARGETS somador RUNTIME DESTINATION bin)
