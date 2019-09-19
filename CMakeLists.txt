cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost REQUIRED COMPONENTS)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(calc assignment2/exercise1/boosted/calc.cpp)

add_executable(PolyDevision assignment2/exercise1/Rational.cpp assignment2/exercise1/Rational.h assignment2/exercise1/PolyDevision.cpp)

add_executable(NewtonInterpolation assignment2/exercise2/NewtonInterpolation.cpp assignment2/exercise2/NewtonInterpolation.h assignment2/exercise2/NITest.cpp)