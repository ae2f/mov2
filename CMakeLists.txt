cmake_minimum_required(VERSION 3.10)
project(mov2 VERSION 1.4.9 LANGUAGES C CXX)
enable_testing()

include(cmake/Core.cmake)

if(NOT TARGET ${PROJECT_NAME})

ae2f_CoreLibFetch(ae2f mov Rel-v0.8.4)

ae2f_CoreLibTent(
    ${PROJECT_NAME} INTERFACE include ae2f
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