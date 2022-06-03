cmake_minimum_required(VERSION 3.0)
project(lab_04)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/runner")
set_property(GLOBAL PROPERTY USE_FOLDERS OFF)
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/mainwindow.cpp
        inc/mainwindow.h
        gui/mainwindow.ui
        src/lift.cpp
        inc/lift.h
        inc/liftcabin.h src/liftcabin.cpp
        inc/liftcontroller.h src/liftcontroller.cpp
        inc/define.h
        inc/button.h src/button.cpp
        inc/door.h src/door.cpp
)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})