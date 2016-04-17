#-------------------------------------------------
#
# Project created by QtCreator 2016-04-17T10:13:44
#
#-------------------------------------------------

QT += core
QT += widgets
QT += svg
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testDrawing2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderarea.cpp

HEADERS  += mainwindow.h \
    renderarea.h

FORMS    += \
    mainwindow.ui
