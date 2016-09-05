project( NetEaseIntern )
cmake_minimum_required( VERSION 2.8.3 )

include_directories( ${CMAKE_SOURCE_DIR} )
include_directories( ${CMAKE_BINARY_DIR} )
configure_file(
    "${PROJECT_SOURCE_DIR}/Configs.h.in"
    "${PROJECT_BINARY_DIR}/Configs.h" )

add_executable( main  src/main.cpp )
add_executable( main1 src/main1.cpp )
add_executable( main2 src/main2.cpp )
add_executable( main3 src/main3.cpp )
add_executable( main4 src/main4.cpp )
add_executable( main5 src/main5.cpp )
add_executable( main6 src/main6.cpp )
add_executable( main7 src/main7.cpp )
add_executable( main8 src/main8.cpp )
add_executable( main9 src/main9.cpp )
