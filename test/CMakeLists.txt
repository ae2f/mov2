link_libraries(mov2)
project(mov2Test)

add_executable(${PROJECT_NAME} "main.c" "main.cpp")
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})