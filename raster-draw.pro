QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

include($$PWD/util/util.pri)
include($$PWD/lines/lines.pri)
include($$PWD/circles/circles.pri)
include($$PWD/ellipses/ellipses.pri)
include($$PWD/polygons/polygons.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
win32 { QMAKE_CXXFLAGS += /FS /utf-8 }

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h
