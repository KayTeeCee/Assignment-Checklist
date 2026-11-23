cmake_minimum_required(VERSION 3.10.0)
project(AssignmentChecklist VERSION 0.1.0 LANGUAGES C CXX)

add_executable(AssignmentChecklist 
  src/main.cpp
  src/AssignmentQueue.hpp
  src/UI.cpp
  src/Assignment.cpp 
  src/Course.cpp)


include_directories(include
  data)

include(CTest)
enable_testing()

