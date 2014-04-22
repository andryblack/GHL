TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp

SOURCES += ../../src/render/stage3d/agal_assembler.cpp \
    ../../src/render/stage3d/Parser.cpp \
    ../../src/render/stage3d/Scanner.cpp \
    ../../src/ghl_log_impl.cpp \
    ../../src/ghl_data_impl.cpp \

HEADERS += ../../src/render/stage3d/agal_assembler.h \
    ../../src/render/stage3d/Parser.h \
    ../../src/render/stage3d/Scanner.h \
    ../../src/ghl_log_impl.h \
    ../../src/ghl_data_impl.h \

INCLUDEPATH+=../../include

INCLUDEPATH+=../../src
INCLUDEPATH+=../../src/render/stage3d

