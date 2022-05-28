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
        main.cpp
        implementation/commands/camera/add/add_camera.cpp
        implementation/commands/camera/add/add_camera.hpp
        implementation/commands/camera/count/count_cameras.cpp
        implementation/commands/camera/count/count_cameras.hpp
        implementation/commands/camera/load/load_camera.cpp
        implementation/commands/camera/move/move_camera.cpp
        implementation/commands/camera/move/move_camera.hpp
        implementation/commands/camera/load/load_camera.hpp
        implementation/commands/camera/remove/remove_camera.cpp
        implementation/commands/camera/remove/remove_camera.hpp
        implementation/commands/camera/set/set_camera.cpp
        implementation/commands/camera/set/set_camera.hpp
        implementation/commands/camera/camera_command.hpp

        implementation/commands/model/add/add_model.cpp
        implementation/commands/model/add/add_model.hpp
        implementation/commands/model/count/count_models.cpp
        implementation/commands/model/count/count_models.hpp
        implementation/commands/model/load/load_model.cpp
        implementation/commands/model/move/move_model.cpp
        implementation/commands/model/move/move_model.hpp
        implementation/commands/model/scale/scale_model.cpp
        implementation/commands/model/scale/scale_model.hpp
        implementation/commands/model/load/load_model.hpp
        implementation/commands/model/remove/remove_model.cpp
        implementation/commands/model/remove/remove_model.hpp
        implementation/commands/model/rotate/rotate_model.cpp
        implementation/commands/model/rotate/rotate_model.hpp
        implementation/commands/model/transform/transform_model.cpp
        implementation/commands/model/transform/transform_model.hpp
        implementation/commands/model/model_command.hpp

        implementation/commands/scene/get_main_camera/get_main_camera.cpp
        implementation/commands/scene/get_main_camera/get_main_camera.hpp
        implementation/commands/scene/get_object/get_object.cpp
        implementation/commands/scene/get_object/get_object.hpp
        implementation/commands/scene/get_scene/get_scene.cpp
        implementation/commands/scene/get_scene/get_scene.hpp
        implementation/commands/scene/render/render_scene.cpp
        implementation/commands/scene/render/render_scene.hpp
        implementation/commands/scene/scene_command.hpp

        implementation/commands/command.hpp

        implementation/drawer/solution/solution_drawer_factory.cpp
        implementation/drawer/solution/solution_drawer_factory.hpp
        implementation/drawer/drawer.hpp

        implementation/exceptions/base_exception.hpp
        implementation/exceptions/camera_exceptions.hpp
        implementation/exceptions/load_exceptions.hpp
        implementation/exceptions/model_exceptions.hpp
        implementation/exceptions/ui_exceptions.hpp

        implementation/facade/facade.cpp
        implementation/facade/facade.hpp

        implementation/load/builders/camera/file_camera_builder/file_camera_builder.cpp
        implementation/load/builders/camera/file_camera_builder/file_camera_builder.hpp
        implementation/load/builders/camera/camera_builder.hpp

        implementation/load/builders/model/file_model_builder/file_wireframe_model_builder/file_wireframe_model_builder.hpp
        implementation/load/builders/model/file_model_builder/file_wireframe_model_builder/file_wireframe_model_builder.cpp
        implementation/load/builders/model/file_model_builder/file_model_builder.hpp
        implementation/load/builders/model/model_builder.hpp

        implementation/load/builders/object_builder.hpp

        implementation/load/directors/camera/camera_director.cpp
        implementation/load/directors/camera/camera_director.hpp
        implementation/load/directors/model/wireframe_model/wireframe_model_director.cpp
        implementation/load/directors/model/wireframe_model/wireframe_model_director.hpp
        implementation/load/directors/model/model_director.hpp

        implementation/load/directors/solution/director_solution.cpp
        implementation/load/directors/solution/director_solution.hpp
        implementation/load/directors/load_director.hpp

        implementation/load/loaders/camera/file_camera_loader.cpp
        implementation/load/loaders/camera/file_camera_loader.hpp

        implementation/load/loaders/model/file_wireframe_model_loader.cpp
        implementation/load/loaders/model/file_wireframe_model_loader.hpp
        implementation/load/loaders/file_base_loader.hpp

        implementation/managers/draw/draw_manager.cpp
        implementation/managers/draw/draw_manager.hpp
        implementation/managers/load/load_manager.hpp
        implementation/managers/load/load_manager.cpp
        implementation/managers/scene/scene_manager.hpp
        implementation/managers/scene/scene_manager.cpp
        implementation/managers/transform/transform_manager.cpp
        implementation/managers/transform/transform_manager.hpp
        implementation/managers/manager_creator.hpp
        implementation/managers/manager.hpp

        implementation/objects/camera/camera.cpp
        implementation/objects/camera/camera.hpp
        implementation/objects/composite/composite.cpp
        implementation/objects/composite/composite.hpp
        implementation/objects/model/wireframe_model/wireframe_model.cpp
        implementation/objects/model/wireframe_model/wireframe_model.hpp
        implementation/objects/model/wireframe_model/model_details/edge/edge.cpp
        implementation/objects/model/wireframe_model/model_details/edge/edge.hpp
        implementation/objects/model/wireframe_model/model_details/point/point.cpp
        implementation/objects/model/wireframe_model/model_details/point/point.hpp
        implementation/objects/model/wireframe_model/model_details/wireframe_model_details.cpp
        implementation/objects/model/wireframe_model/model_details/wireframe_model_details.hpp
        implementation/objects/model/model.hpp
        implementation/objects/object.hpp
        implementation/scene/scene.cpp
        implementation/scene/scene.hpp

        implementation/visitor/draw_visitor/draw_visitor.cpp
        implementation/visitor/draw_visitor/draw_visitor.hpp
        implementation/visitor/visitor.hpp

        gui/qt/drawer/factory/qt_drawer_factory.cpp
        gui/qt/drawer/factory/qt_drawer_factory.hpp
        gui/qt/drawer/qt_drawer.cpp
        gui/qt/drawer/qt_drawer.hpp

        gui/qt/design.h
        gui/qt/display.h
        gui/qt/mainwindow.cpp
        gui/qt/mainwindow.h
        )
        
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} config++)

