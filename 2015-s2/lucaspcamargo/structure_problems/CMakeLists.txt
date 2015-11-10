cmake_minimum_required(VERSION 3.2)

project(structure_problems)

set(EXT_SOURCES ../queue/queue.c ../stack/stack.c)

add_executable(problem1 problem1.c ${EXT_SOURCES})
add_executable(problem2 problem2.c ${EXT_SOURCES})

install(TARGETS problem1 RUNTIME DESTINATION bin)
