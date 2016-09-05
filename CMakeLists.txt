project( NetEaseIntern )
cmake_minimum_required( VERSION 2.8.3 )

include_directories( ${CMAKE_SOURCE_DIR} )
include_directories( ${CMAKE_BINARY_DIR} )
configure_file(
    "${PROJECT_SOURCE_DIR}/Configs.h.in"
    "${PROJECT_BINARY_DIR}/Configs.h" )

add_executable( main  main.cpp )

add_executable( main1 main1.cpp )
add_executable( main2 main2.cpp )
add_executable( main3 main3.cpp )

add_executable( main4 main4.cpp )
add_executable( main5 main5.cpp )
add_executable( main6 main6.cpp )
