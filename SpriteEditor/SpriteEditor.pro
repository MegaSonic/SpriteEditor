#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T22:15:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpriteEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcolormatrix.cpp \
    themes.cpp \
    canvas.cpp \
    fileio.cpp \
    preview.cpp \
    spritepropertieswindow.cpp

HEADERS  += mainwindow.h \
    qcolormatrix.h \
    themes.h \
    canvas.h \
    fileio.h \
    preview.h \
    spritepropertieswindow.h

FORMS    += mainwindow.ui \
    spritepropertieswindow.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
