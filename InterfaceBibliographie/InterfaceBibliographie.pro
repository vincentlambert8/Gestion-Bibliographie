TEMPLATE = app
TARGET = InterfaceBibliographie
QT += core \
    gui
HEADERS += supprimerreference.h \
    journalqt.h \
    ouvrageqt.h \
    interfacebibliographie.h
SOURCES += supprimerreference.cpp \
    journalqt.cpp \
    ouvrageqt.cpp \
    main.cpp \
    interfacebibliographie.cpp
FORMS += supprimerreference.ui \
    journalqt.ui \
    ouvrageqt.ui \
    interfacebibliographie.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
