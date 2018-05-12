cmake_minimum_required(VERSION 3.9)
project(lab03)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp mainwidget.cpp mainwidget.h mainwidget.ui parser.h model/point.h
                                        model/edge.h ./vtemplate model/model.h exceptions.h)

set(CMAKE_CXX_FLAGS '-Wall')

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

add_executable(lab03 ${SOURCE_FILES})
target_link_libraries(lab03 Qt5::Widgets Qt5::Core Qt5::Gui)