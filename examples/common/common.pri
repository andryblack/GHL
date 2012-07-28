SOURCES+=../common/application_base.cpp
HEADERS+=../common/application_base.h
debug {
    LIBS+=../../lib/libGHL-qt_d.a
}
!debug{
    LIBS+=../../lib/libGHL-qt.a
}
CONFIG-=qt
INCLUDEPATH+=../../include
linux*{
    LIBS+=-L/usr/X11R6/lib
    LIBS+=-lGL -lX11
    #XF86
    LIBS+=-lXxf86vm
}
macx{
    LIBS += -framework Cocoa
}
