cmake_minimum_required(VERSION 3.23)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(sources)

add_executable(Calculator
        sources/header.hpp
        sources/main.cpp
        sources/Result_Func.cpp
        sources/Polish_Entry_Func.cpp
        sources/Error_Debugging_Func.cpp
        )
