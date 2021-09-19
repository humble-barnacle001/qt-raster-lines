include($$PWD/../util/util.pri)

INCLUDEPATH += lines

SOURCES += \
    lines/linesmainwidget.cpp \
    lines/bresenhamwidget.cpp \
    lines/ddawidget.cpp \
    lines/linegraphwidget.cpp

HEADERS += \
    lines/linesmainwidget.h \
    lines/bresenhamwidget.h \
    lines/ddawidget.h \
    lines/linegraphwidget.h

FORMS += \
    lines/linesmainwidget.ui

