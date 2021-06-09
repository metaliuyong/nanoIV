#-------------------------------------------------
#
# Project created by QtCreator 2015-07-02T09:15:03
#
#-------------------------------------------------

QT       += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nanoIV
TEMPLATE = app

RC_FILE = nanoIV.rc

#directory =
INCLUDEPATH += C:\Users\Steven\Desktop\nanosizer_1\qcustomplot\ where qcustomplot.h


SOURCES += main.cpp\
    qcustomplot.cpp \
    session.cpp \
    typeconversions.cpp \
    ivsweep.cpp \
    session_interface.cpp \
    session_commands.cpp \
    measurementprotocol.cpp \
    session_staticmembervariables.cpp \
    gpiberror.cpp \
    currentsampleprotocol.cpp \
    plot.cpp \
    ivprotocol.cpp \
    mainwindow_directcontrols.cpp \
    mainwindow_currentsampleprotocol.cpp \
    mainwindow_initialization.cpp \
    mainwindow_ivprotocol_parametercontrols.cpp \
    mainwindow_ui.cpp \
    mainwindow_general.cpp \
    ivsweepaverage.cpp \
    mainwindow_ivprotocol_savesweeps.cpp \
    mainwindow_ivprotocol_playcontrols.cpp \
    mainwindow_ivprotocol_sweeptable.cpp \
    ptime.cpp \
    overwritefiledialogue.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    session.h \
    typeconversions.h \
    ivsweep.h \
    measurementprotocol.h \
    gpiberror.h \
    currentsampleprotocol.h \
    plot.h \
    ivprotocol.h \
    ivsweepaverage.h \
    ptime.h \
    overwritefiledialogue.h

FORMS    += mainwindow.ui \
    overwritefiledialogue.ui

LIBS += -L"C:\Program Files\IVI Foundation\VISA\Win64\Lib_x64\msc" -lvisa64
LIBS += -lwinmm

CONFIG += c++11
