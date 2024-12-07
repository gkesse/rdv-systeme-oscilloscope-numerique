cmake_minimum_required(VERSION 3.5.0)
project(ReadyScope VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS
Widgets
SerialPort
)

set(SRC_FILES
main.cpp
DTerminal.cpp
DSettings.cpp
IoDevice.cpp
parser/ParseConnection.cpp
parser/FrameParser.cpp
scope/Scope.cpp
scope/Scopes.cpp
scope/DScopeQT.cpp
scope/DScopesQT.cpp
scope/DScopesQTWidget.cpp
)

set(UI_FILES
MainWindow.cpp
)

set(RCC_FILES
resources.qrc
)

add_definitions(-DDEVELMODE)

qt_wrap_ui(${UI_FILES})

include_directories(.
parser
scope
)

add_executable(ReadyScope
${SRC_FILES}
${UI_FILES}
${RCC_FILES}
)

target_link_libraries (ReadyScope
Qt5::Widgets
Qt5::SerialPort
)
