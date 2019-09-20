cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost REQUIRED COMPONENTS)
include_directories(${Boost_INCLUDE_DIRS})


add_executable(PolyDevision 2/assignment2/exercise1/Rational.cpp 2/assignment2/exercise1/Rational.h 2/assignment2/exercise1/PolyDivision.cpp)

add_executable(NewtonInterpolation 2/assignment2/exercise2/NewtonInterpolation.cpp 2/assignment2/exercise2/NewtonInterpolation.h 2/assignment2/exercise2/NITest.cpp)