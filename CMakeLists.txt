cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost REQUIRED COMPONENTS)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(calc assignment2/exercise1/boosted/calc.cpp)

add_executable(test assignment2/exercise1/Rational.cpp assignment2/exercise1/Rational.h assignment2/exercise1/RationalTest.cpp)