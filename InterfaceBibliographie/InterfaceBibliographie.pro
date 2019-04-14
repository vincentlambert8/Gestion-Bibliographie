TEMPLATE = app
TARGET = InterfaceBibliographie
QT += core \
    gui
HEADERS += journalqt.h \
    ouvrageqt.h \
    interfacebibliographie.h
SOURCES += journalqt.cpp \
    ouvrageqt.cpp \
    main.cpp \
    interfacebibliographie.cpp
FORMS += journalqt.ui \
    ouvrageqt.ui \
    interfacebibliographie.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
