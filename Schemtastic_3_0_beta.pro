#-------------------------------------------------
#
# Project created by QtCreator 2014-03-22T00:20:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Schemtastic_3_0_beta
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    component.cpp \
    and_component.cpp \
    or_component.cpp \
    nand_component.cpp \
    nor_component.cpp \
    not_component.cpp \
    xor_component.cpp \
    xnor_component.cpp \
    linija.cpp \
    naprednelinije.cpp \
    prekidac.cpp \
    userdefined.cpp

HEADERS  += mainwindow.h \
    component.h \
    and_component.h \
    or_component.h \
    nand_component.h \
    nor_component.h \
    not_component.h \
    xor_component.h \
    xnor_component.h \
    linija.h \
    naprednelinije.h \
    prekidac.h \
    userdefined.h

FORMS    += mainwindow.ui

RESOURCES += \
    ikone.qrc
