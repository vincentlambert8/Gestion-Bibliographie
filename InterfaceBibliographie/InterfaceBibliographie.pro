TEMPLATE = app
TARGET = InterfaceBibliographie
QT += core \
    gui
HEADERS += modifierreference.h \
    supprimerreference.h \
    journalqt.h \
    ouvrageqt.h \
    interfacebibliographie.h
SOURCES += modifierreference.cpp \
    supprimerreference.cpp \
    journalqt.cpp \
    ouvrageqt.cpp \
    main.cpp \
    interfacebibliographie.cpp
FORMS += modifierreference.ui \
    supprimerreference.ui \
    journalqt.ui \
    ouvrageqt.ui \
    interfacebibliographie.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
