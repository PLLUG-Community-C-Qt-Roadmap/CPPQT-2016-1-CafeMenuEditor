#-------------------------------------------------
#
# Project created by QtCreator 2016-05-17T18:10:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CafeMenuEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    menuitemeditor.cpp \
    menueditor.cpp \
    abstractmenuitem.cpp \
    menu.cpp \
    menuitem.cpp \
    visitor.cpp

HEADERS  += mainwindow.h \
    menuitemeditor.h \
    menueditor.h \
    abstractmenuitem.h \
    menu.h \
    menuitem.h \
    visitor.h

FORMS    += mainwindow.ui \
    menuitemeditor.ui \
    menueditor.ui
