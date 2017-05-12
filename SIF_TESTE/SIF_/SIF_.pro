#-------------------------------------------------
#
# Project created by QtCreator 2017-05-11T16:59:03
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_sif_veiculotest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_sif_veiculotest.cpp \
    ../../SIF_GUI/Model/Veiculo.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../SIF_GUI/Model/Veiculo.h
