cmake_minimum_required(VERSION 2.8)

project(algorithm CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "debug")
endif()

set(CXX_FLAGS
 -g
 # -DVALGRIND
 -Wall
 -Wextra
 # -m32
 -Werror
 -Wconversion
 -Wno-unused-parameter
 -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
 -Wno-shadow
 -Wwrite-strings
 -march=native
 # -MMD
 -std=c++0x
 -rdynamic
 #-Wno-missing-field-initializers
 #-fpermissive
 -Wno-sign-compare
 -Wno-conversion
 -Wno-unused-but-set-variable
 -DGTEST_HAS_PTHREAD=1
 )
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ${PROJECT_BINARY_DIR}/lib)

find_library(gtest gtest)
find_library(gtest_main gtest_main)
#find_library(benchmark benchmark)
#find_library(benchmark_main benchmark_main)

message(STATUS "gtest: ${gtest}")
message(STATUS "gtest_main: ${gtest_main}")
#message(STATUS "benchmark: ${benchmark}")
#message(STATUS "benchmark_main: ${benchmark_main}")

include_directories("${PROJECT_SOURCE_DIR}/util")
add_subdirectory(bat)
add_subdirectory(advanced)


