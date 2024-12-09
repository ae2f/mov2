cmake_minimum_required(VERSION 3.10)
project(mov2 VERSION 1.1.2 LANGUAGES C CXX)
enable_testing()
if(NOT TARGET ${PROJECT_NAME})

add_subdirectory(mod/ae2f/mov)

ae2f_CoreLibProjTent(
    ${PROJECT_NAME} INTERFACE include
    "include/ae2f/mov2/Def.h"
    "include/ae2f/mov2/Def.hpp"
    "include/ae2f/mov2/Vec.h"
    "include/ae2f/mov2/Scalar.h"
    "include/ae2f/mov2/Col.h"    
)

target_link_libraries(${PROJECT_NAME} INTERFACE mov)

ae2f_CoreTestTent(${PROJECT_NAME} test)

include_directories(include)
endif()