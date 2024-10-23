cmake_minimum_required(VERSION 3.28)
project(oop_a8_9_916_schiau_teodora)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/teoschiau/Qt1/6.7.0/macos/lib/cmake")
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Charts Qt5::Gui Qt5::Widgets)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network
        Charts
        REQUIRED)

add_executable(oop_a8_9_916_schiau_teodora main.cpp
        GUI.cpp
        GUI.h
        AdminGUI.cpp
        AdminGUI.h
        validator.cpp
        UserGUI.cpp
        UserGUI.h
        domain.cpp
        exceptions.cpp
        FileRepository.cpp
        Repository.cpp
        service.cpp
        ui.cpp
        WriteFile.cpp
        qtgui.cpp
        qtgui.h
        qtgui.ui
        Action.cpp
        Action.h
        TableMode.cpp
        TableMode.h)
target_link_libraries(oop_a8_9_916_schiau_teodora
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Charts
)

