#-------------------------------------------------
#
# Project created by QtCreator 2014-03-02T03:51:34
#
#-------------------------------------------------

include(/usr/local/share/iris/iris_plugin.pri)

TARGET = $$qtLibraryTarget(xclueless.iris.Core)

LIBS += -lIris

QT       -= gui

CONFIG +=  c++11 plugin
SOURCES += CorePlugin.cpp \
    Listen.cpp \
    ListenFactory.cpp \
    SimpleAuth.cpp \
    SimpleAuthFactory.cpp \
    PermGroup.cpp \
    PermFile.cpp \
    PermUser.cpp
HEADERS += CorePlugin.hpp \
    Listen.hpp \
    ListenFactory.hpp \
    SimpleAuthFactory.hpp \
    SimpleAuth.hpp \
    PermGroup.hpp \
    PermFile.hpp \
    PermUser.hpp
