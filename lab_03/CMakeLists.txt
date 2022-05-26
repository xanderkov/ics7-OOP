cmake_minimum_required(VERSION 3.0)
project(lab_03)

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
        src/configuration/loadsolution.cpp
    src/configuration/registrator.cpp
    src/configuration/solution.cpp
    src/facade/basecommand.cpp
    src/load/baseSourceLoader.cpp
    src/load/camerabuilder.cpp
    src/load/camerafileloader.cpp
    src/load/figurebuilder.cpp
    src/load/figurefileloader.cpp
    src/load/scenebuilder.cpp
    src/load/scenefileloader.cpp
    src/managers/configmanager.cpp
    src/managers/drawmanager.cpp
    src/managers/loadmanager.cpp
    src/managers/scenemanager.cpp
    src/objects/camera.cpp
    src/objects/composite.cpp
    src/objects/data.cpp
    src/objects/figure.cpp
    src/gui/main.cpp
    src/gui/mainwindow.cpp
    src/objects/point.cpp
    src/scene/scene.cpp
    src/visitor/visitor.cpp
    src/load/loadDirector.cpp
    src/abstractfactory/abstractfactory.h
    src/configuration/loadsolution.h
    src/configuration/registrator.h
    src/configuration/solution.h
    src/facade/basecommand.h
    src/load/basesourceloader.h
    src/load/builder.h
    src/load/camerabuilder.h
    src/load/camerafileloader.h
    src/load/figurebuilder.h
    src/load/figurefileloader.h
    src/load/loadcreator.h
    src/load/scenebuilder.h
    src/load/scenefileloader.h
    src/managers/basemanager.h
    src/managers/configmanager.h
    src/managers/drawmanager.h
    src/managers/loadmanager.h
    src/managers/scenemanager.h
    src/objects/camera.h
    src/objects/composite.h
    src/abstractfactory/drawer.h
    src/objects/data.h
    src/objects/edge.h
    src/exceptions/exceptions.h
    src/objects/figure.h
    src/gui/mainwindow.h
    src/Mathobj/mathobjs.h
    src/objects/object.h
    src/Mathobj/pixel.h
    src/objects/point.h
    src/scene/scene.h
    src/facade/facade.h
    src/visitor/baseVisitor.h
    src/visitor/visitor.h
    src/load/loadDirector.h
    src/configuration/loadsolution.h
    src/managers/managersolution.h
    src/managers/managersolution.cpp
        )
        
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} config++)
