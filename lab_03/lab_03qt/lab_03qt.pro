QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    facade.cpp \
    mainwindow.cpp \
    mainwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    command_base.h \
    controller.h \
    error_base.h \
    error_container.h \
    error_drawer.h \
    error_loader.h \
    error_new.h \
    error_scene.h \
    facade.h \
    mainwindow.h \
    mainwindow.h

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
