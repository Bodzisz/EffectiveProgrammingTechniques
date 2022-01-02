cmake_minimum_required(VERSION 3.21)
project(List05)

set(CMAKE_CXX_STANDARD 11)

add_executable(List05 main.cpp MySmartPointer.h MySmartPointerImpl.h RefCounter.cpp RefCounter.h)
