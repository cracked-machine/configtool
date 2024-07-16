cmake_minimum_required(VERSION 3.1...3.29)

project(
  mapexample
  VERSION 1.0
  LANGUAGES CXX)

include_directories(include)
add_compile_options(-g -O0)
add_executable(mapexample 
  mapexample.cpp  
)