QT += core
QT -= gui

CONFIG += c++11

TARGET = EvacuationRoutes
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Graph.cpp \
    Node.cpp \
    PriorityQueue.cpp \
    Dijkstra.cpp \
    Yen.cpp

HEADERS += \
    Graph.h \
    Node.h \
    PriorityQueue.h \
    Dijkstra.h \
    Yen.h
