cmake_minimum_required(VERSION 3.21)
project(vaja1101)

set(CMAKE_CXX_STANDARD 14)

add_executable(vaja1101 main.cpp Address.cpp Address.h Date.cpp Date.h Student.cpp Student.h UnparseableDateException.cpp UnparseableDateException.h WrongPhoneNumberException.cpp WrongPhoneNumberException.h)
