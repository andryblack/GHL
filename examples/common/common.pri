SOURCES+=../common/application_base.cpp
HEADERS+=../common/application_base.h
LIBS+=-L../../lib -lGHL
CONFIG-=qt
INCLUDEPATH+=../../include
linux*{
    LIBS+=-L/usr/X11R6/lib
    LIBS+=-lGL -lX11
    #XF86
    LIBS+=-lXxf86vm
}
