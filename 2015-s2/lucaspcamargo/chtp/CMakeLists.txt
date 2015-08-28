project(chtp)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

foreach(SRC_FILE ${SRC_LIST})
    get_filename_component(EX_NAME ${SRC_FILE} NAME_WE)
    add_executable(${EX_NAME} ${SRC_FILE})
    #set_target_properties(${EX_NAME} PROPERTIES )
endforeach()
