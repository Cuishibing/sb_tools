cmake_minimum_required(VERSION 3.8)
project(sb_tools)

set(CMAKE_C_STANDARD 99)

include_directories(./hea)

aux_source_directory(./ SOURCE_FILES)
aux_source_directory(./src SOURCE_FILES)
aux_source_directory(./src/collection SOURCE_FILES)
aux_source_directory(./src/sort SOURCE_FILES)
aux_source_directory(./src/tree SOURCE_FILES)

add_executable(sb_tools ${SOURCE_FILES} src/tree/sb_avltree.c)