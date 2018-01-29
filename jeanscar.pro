#-------------------------------------------------
#
# Project created by QtCreator 2017-04-07T17:26:03
#
#-------------------------------------------------

QT       += core gui printsupport
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jeanscar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    password.cpp \
    thread.cpp \
    report.cpp \
    dialog.cpp \
    product.cpp \
    todoornottodo.cpp \
    mohafzat_table.cpp \
    dialog1.cpp \
    table.cpp \
    choose_employee.cpp \
    taqrer_salar.cpp \
    priority.cpp \
    accounting.cpp \
    settings.cpp \
    print.cpp

HEADERS  += mainwindow.h \
    password.h \
    thread.h \
    report.h \
    dialog.h \
    product.h \
    todoornottodo.h \
    mohafzat_table.h \
    dialog1.h \
    table.h \
    choose_employee.h \
    taqrer_salar.h \
    priority.h \
    accounting.h \
    settings.h \
    print.h
FORMS    += mainwindow.ui \
    password.ui \
    report.ui \
    dialog.ui \
    product.ui \
    todoornottodo.ui \
    mohafzat_table.ui \
    dialog1.ui \
    table.ui \
    choose_employee.ui \
    taqrer_salar.ui \
    priority.ui \
    accounting.ui \
    settings.ui \
    print.ui
CONFIG += static
CONFIG += staticlib

RESOURCES += \
    logo.qrc

