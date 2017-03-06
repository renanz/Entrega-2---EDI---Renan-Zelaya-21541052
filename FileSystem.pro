#-------------------------------------------------
#
# Project created by QtCreator 2017-02-27T17:04:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fileExplorer.cpp \
    Lista_Apuntador.cpp \
    folder.cpp \
    archivo.cpp \
    archivoTexto.cpp

HEADERS  += mainwindow.h \
    fileExplorer.h \
    Lista_Apuntador.h \
    folder.h \
    archivo.h \
    archivoTexto.h

FORMS    += mainwindow.ui
