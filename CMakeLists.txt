cmake_minimum_required(VERSION 3.2...3.5 FATAL_ERROR)

set(PROJECT_NAME HW-dpcpp-4.2)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.cpp src/Data_DrySolid.hpp)