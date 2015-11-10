project(set)

add_executable(set main.c set.c)

install(TARGETS set RUNTIME DESTINATION bin)
