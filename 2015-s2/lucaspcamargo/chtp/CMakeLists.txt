project(chtp)
cmake_minimum_required(VERSION 2.8)

# use c11 :)
add_definitions(-std=c11)

# find all source files in current directory
aux_source_directory(. SRC_LIST)

# create an executable build target for each source 
foreach(SRC_FILE ${SRC_LIST})
    get_filename_component(EX_NAME ${SRC_FILE} NAME_WE)
    add_executable(${EX_NAME} ${SRC_FILE})
    #set_target_properties(${EX_NAME} PROPERTIES )
endforeach()
