project(doublesort)

add_executable(doublesort main.c)

install(TARGETS doublesort RUNTIME DESTINATION bin)

add_subdirectory(doc)