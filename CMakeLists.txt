cmake_minimum_required(VERSION 3.0)

project(operating_time CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(operating_time main.cpp operating_time.cpp)

target_include_directories(operating_time PRIVATE ${CMAKE_SOURCE_DIR})
