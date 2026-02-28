cmake_minimum_required(VERSION 4.2)
project(QtNixMon)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(QtNixMon
        monitor.cpp
        monitor.h
        monitor.ui
)
target_link_libraries(QtNixMon
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

