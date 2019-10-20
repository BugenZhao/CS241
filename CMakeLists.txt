cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost REQUIRED COMPONENTS)
include_directories(${Boost_INCLUDE_DIRS})


add_executable(PolyDevision 2/assignment2/exercise1/Rational.cpp 2/assignment2/exercise1/Rational.h 2/assignment2/exercise1/PolyDivision.cpp)

add_executable(NewtonInterpolation 2/assignment2/exercise2/NewtonInterpolation.cpp 2/assignment2/exercise2/NewtonInterpolation.h 2/assignment2/exercise2/NITest.cpp)
add_executable(BisectionMethod 3/assignment3/exercise1/HW3-BisectionMethod/BisectionMethod.cpp)
add_executable(NewtonsMethod 3/assignment3/exercise1/HW3-NewtonsMethod/NewtonsMethod.cpp)
add_executable(Calculator 3/Calculator/main.cpp 3/Calculator/Token.cpp 3/Calculator/TokenStream.cpp 3/Calculator/StreamCalculator.cpp 3/Calculator/BZCalculator.cpp 3/Calculator/BZCalculator.h 3/Calculator/BaseAlgorithms.cpp 3/Calculator/BaseAlgorithms.h)
add_executable(LinearSolver 4/assignment4/LinearSolver.cpp)
add_executable(GPTest 5/assignment5/main.cpp 5/assignment5/myArray.h 5/assignment5/myData.h 5/assignment5/mySort.h)
add_executable(HMTest 6/assignment6/main.cpp 6/assignment6/hm.hpp)