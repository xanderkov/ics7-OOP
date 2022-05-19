QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builder_camera.cpp \
    builder_model.cpp \
    camera_source_loader_file.cpp \
    canvas_qt.cpp \
    carcass.cpp \
    commands.cpp \
    controller.cpp \
    director_camera.cpp \
    director_model.cpp \
    drawer_qt.cpp \
    facade.cpp \
    link.cpp \
    load_controller_camera.cpp \
    load_controller_model.cpp \
    mainwindow.cpp \
    mainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    manager_draw.cpp \
    manager_load.cpp \
    manager_scene.cpp \
    manager_transform.cpp \
    matrix_transform.cpp \
    model_source_loader_file.cpp \
    object_camera.cpp \
    object_composite.cpp \
    object_model.cpp \
    scene.cpp

HEADERS += \
    builder_camera.h \
    builder_camera_base.h \
    builder_model.h \
    builder_model_base.h \
    camera_source_loader_base.h \
    camera_source_loader_file.h \
    canvas_base.h \
    canvas_qt.h \
    carcass.h \
    command_base.h \
    commands.h \
    controller.h \
    director_camera.h \
    director_model.h \
    drawer_base.h \
    drawer_qt.h \
    error_base.h \
    error_container.h \
    error_drawer.h \
    error_loader.h \
    error_new.h \
    error_scene.h \
    facade.h \
    factory_abstract.h \
    factory_qt.h \
    iterator_base.h \
    iterator_const.h \
    iterator_usual.h \
    iterator_vector.h \
    link.h \
    load_controller_base.h \
    load_controller_camera.h \
    load_controller_model.h \
    mainwindow.h \
    mainwindow.h \
    manager_base.h \
    manager_draw.h \
    manager_load.h \
    manager_scene.h \
    manager_transform.h \
    matrix.h \
    matrix_base.h \
    matrix_transform.h \
    model_source_loader_base.h \
    model_source_loader_file.h \
    object_camera.h \
    object_composite.h \
    object_invisible.h \
    object_model.h \
    object_scene.h \
    object_visible.h \
    point.h \
    points_pair.h \
    scene.h \
    vector.h \
    vector_base.h \
    visitor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/config.cfg \
    data/cube.txt \
    data/octahedron.txt
