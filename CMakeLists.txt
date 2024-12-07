cmake_minimum_required(VERSION 3.10)
project(mov2 VERSION 1.0.1)
enable_testing()
if(NOT TARGET ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD_REQUIRED 20)

option(ae2f_IS_SHARED "Is a shared library or static one." OFF)
option(ae2f_mov_IS_64 "Would you use the Prm-Vec as 64-bit integer?" OFF)

add_subdirectory(mod/ae2f/mov)

# Namespace Package
include(GNUInstallDirs)

add_library(
    ${PROJECT_NAME}
    INTERFACE
    "include/ae2f/mov2/Def.h"
    "include/ae2f/mov2/Def.hpp"
    "include/ae2f/mov2/Vec.h"
    "include/ae2f/mov2/Scalar.h"
    "include/ae2f/mov2/Col.h"
)

target_link_libraries(${PROJECT_NAME} INTERFACE mov)


unset(ae2f_float_id)

include_directories(include)
add_subdirectory(test)


# Header
target_include_directories(${PROJECT_NAME}
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ae2f::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

endif()