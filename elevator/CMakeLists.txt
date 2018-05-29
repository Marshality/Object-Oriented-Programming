cmake_minimum_required(VERSION 3.9)
project(elevator)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main/main.cpp main/mainwidget.cpp main/mainwidget.h main/mainwidget.ui)

set(CMAKE_CXX_FLAGS)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(Qt5Widgets_DIR /Users/marshal/Applications/QtCreator/5.10.1/clang_64/lib/cmake/Qt5Widgets)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

add_executable(elevator ${SOURCE_FILES})
target_link_libraries(elevator Qt5::Widgets Qt5::Core Qt5::Gui)