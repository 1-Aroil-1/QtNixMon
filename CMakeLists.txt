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
        src/main.cpp
        src/ui/mainwindow.cpp
        src/ui/mainwindow.ui
        src/ui/settingsdialog.cpp
        src/ui/settingsdialog.ui
        src/core/systemmonitor.cpp
        src/core/cpuinfo.cpp
        src/core/meminfo.cpp
        src/config/configmanager.cpp
        resources/resources.qrc
)
target_link_libraries(QtNixMon
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

