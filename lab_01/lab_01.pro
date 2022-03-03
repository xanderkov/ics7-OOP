QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    constants.cpp \
    controller.cpp \
    figure.cpp \
    figure_conventions.cpp \
    io.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    myscene.cpp \
    point.cpp \
    points_convertions.cpp

HEADERS += \
    constants.h \
    controller.h \
    figure.h \
    figure_conventions.h \
    io.h \
    mainwindow.h \
    matrix.h \
    myscene.h \
    point.h \
    points_convertions.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
