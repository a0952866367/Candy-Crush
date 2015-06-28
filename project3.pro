#-------------------------------------------------
#
# Project created by QtCreator 2015-06-28T13:33:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blank.cpp \
    bomb.cpp \
    destroy.cpp \
    hor.cpp \
    horizon.cpp \
    ver.cpp \
    vertical.cpp \
    wrap.cpp

HEADERS  += mainwindow.h \
    blank.h \
    bomb.h \
    destroy.h \
    hor.h \
    horizon.h \
    ver.h \
    vertical.h \
    wrap.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
