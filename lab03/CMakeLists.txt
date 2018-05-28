cmake_minimum_required(VERSION 3.9)
project(lab03)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main/main.cpp main/mainwidget.cpp main/mainwidget.h main/mainwidget.ui parser/CarcaseParser.h model/point.h
        model/edge.h model/CarcaseModel.h exception/exceptions.h vector/vector.h vector/_vector.h viewer.h command/BaseCommand.h command/commands.h canvas/BaseCanvas.h canvas/drawer.h model/BaseModel.h parser/BaseParser.h command/ParserCommand.h command/ModelCommand.h canvas/QtCanvas.h)

set(CMAKE_CXX_FLAGS)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

add_executable(lab03 ${SOURCE_FILES})
target_link_libraries(lab03 Qt5::Widgets Qt5::Core Qt5::Gui)