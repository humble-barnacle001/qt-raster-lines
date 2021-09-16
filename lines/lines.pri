include($$PWD/../util/util.pri)

INCLUDEPATH += lines

SOURCES += \
    lines/bresenhamwidget.cpp \
    lines/ddawidget.cpp \
    lines/linegraphwidget.cpp \
    lines/linesmainwindow.cpp

HEADERS += \
    lines/bresenhamwidget.h \
    lines/ddawidget.h \
    lines/linegraphwidget.h \
    lines/linesmainwindow.h

FORMS += \
    lines/linesmainwindow.ui
