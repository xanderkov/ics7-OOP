QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commands.cpp \
    controller.cpp \
    drawer_qt.cpp \
    facade.cpp \
    mainwindow.cpp \
    mainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    model_source_loader_file.cpp

HEADERS += \
    command_base.h \
    commands.h \
    controller.h \
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
    mainwindow.h \
    mainwindow.h \
    model_source_loader_file.h

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
