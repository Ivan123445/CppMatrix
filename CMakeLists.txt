cmake_minimum_required(VERSION 3.25)
project(Cpp_matrix)
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c11 -fanalyzer -pedantic")

file(GLOB_RECURSE SRC_CC src/*.cc)
#file(GLOB_RECURSE TESTS_CC test/*.cc)

add_executable(Cpp_matrix ${SRC_CC})
#add_executable(tests ${SRC_CC} ${TESTS_CC})

#target_link_libraries(tests check)