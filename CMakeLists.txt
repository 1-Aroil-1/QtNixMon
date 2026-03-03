cmake_minimum_required(VERSION 4.2)
project(QtNixMon)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(QtNixMon)

# 1. Обычные файлы (UI, ресурсы, QObject классы)
target_sources(QtNixMon PRIVATE
        src/main.cpp
        resources/resources.qrc
        src/ui/mainwindow.ui
        src/ui/mainwindow.h
        src/ui/mainwindow.cpp
        src/ui/settingdialog.ui
        src/ui/settingdialog.h
        src/ui/settingdialog.cpp
)

# 2. Модули C++ (через FILE_SET)
target_sources(QtNixMon PUBLIC
        FILE_SET CXX_MODULES FILES
        src/core/meminfo.cppm
        src/core/cpuinfo.cppm
        src/core/systemmonitor.cppm
        src/config/configmanager.cppm
)

target_link_libraries(QtNixMon
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)