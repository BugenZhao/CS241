cmake_minimum_required(VERSION 3.15)
project(PieChart)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /Users/bugenzhao/Qt5.13.0/5.13.0/clang_64/lib/cmake)

find_package(Qt5Widgets REQUIRED)

add_executable(PieChart main.cpp mainwindow.cpp BPieView.cpp BPieView.h utils/BColor.hpp)
target_link_libraries(PieChart Qt5::Widgets)