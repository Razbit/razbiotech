TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/cnucleotide.cpp \
    src/cnastrand.cpp \
    src/cdnapolymerase.cpp \
    src/curses_utils.cpp

win32: LIBS += -L$$PWD/lib/ -lpdcurses
linux: LIBS += -lncurses

DISTFILES += \
    README.md

INCLUDEPATH += src/include

HEADERS += \
    lib/pdc_panel.h \
    lib/pdcurses.h \
    src/include/platform.h \
    src/include/pdc_panel.h \
    src/include/pdcurses.h \
    src/cobject.h \
    src/cnucleotide.h \
    src/cnastrand.h \
    src/cnapolymerase.h \
    src/cdnapolymerase.h \
    src/curses_utils.h

