TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp

win32: LIBS += -L$$PWD/lib/ -lpdcurses
linux: LIBS += -lncurses

DISTFILES += \
    README.md
