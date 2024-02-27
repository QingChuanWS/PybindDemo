cmake_minimum_required(VERSION 3.18)
project(pybind_demo)

add_subdirectory(extern/pybind11)
pybind11_add_module(pybind_demo src/main.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(pybind_demo
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})