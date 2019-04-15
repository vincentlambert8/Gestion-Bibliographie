/****************************************************************************
** Meta object code from reading C++ file 'interfacebibliographie.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interfacebibliographie.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interfacebibliographie.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InterfaceBibliographie[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x08,
      99,   41,   23,   23, 0x08,
     202,  188,  183,   23, 0x08,
     245,   23,   23,   23, 0x08,
     333,  262,   23,   23, 0x08,
     417,   23,   23,   23, 0x08,
     441,   23,   23,   23, 0x08,
     465,  188,   23,   23, 0x08,
     510,  188,  183,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_InterfaceBibliographie[] = {
    "InterfaceBibliographie\0\0ajouterOuvrage()\0"
    "p_auteurs,p_titre,p_ville,p_editeur,p_annee,p_identifiant\0"
    "enregistrerOuvrage(std::string,std::string,std::string,std::string,int"
    ",std::string)\0"
    "bool\0p_identifiant\0"
    "verifierReferenceDejaPresente(std::string)\0"
    "ajouterJournal()\0"
    "p_auteurs,p_titre,p_nom,p_volume,p_numero,p_page,p_annee,p_identifiant\0"
    "enregistrerJournal(std::string,std::string,std::string,int,int,int,int"
    ",std::string)\0"
    "afficherBibliographie()\0supprimerUneReference()\0"
    "enregistrerSuppressionReference(std::string)\0"
    "verifierReferenceAbsente(std::string)\0"
};

void InterfaceBibliographie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InterfaceBibliographie *_t = static_cast<InterfaceBibliographie *>(_o);
        switch (_id) {
        case 0: _t->ajouterOuvrage(); break;
        case 1: _t->enregistrerOuvrage((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3])),(*reinterpret_cast< const std::string(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< const std::string(*)>(_a[6]))); break;
        case 2: { bool _r = _t->verifierReferenceDejaPresente((*reinterpret_cast< const std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->ajouterJournal(); break;
        case 4: _t->enregistrerJournal((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< const std::string(*)>(_a[8]))); break;
        case 5: _t->afficherBibliographie(); break;
        case 6: _t->supprimerUneReference(); break;
        case 7: _t->enregistrerSuppressionReference((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 8: { bool _r = _t->verifierReferenceAbsente((*reinterpret_cast< const std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InterfaceBibliographie::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InterfaceBibliographie::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_InterfaceBibliographie,
      qt_meta_data_InterfaceBibliographie, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InterfaceBibliographie::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InterfaceBibliographie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InterfaceBibliographie::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InterfaceBibliographie))
        return static_cast<void*>(const_cast< InterfaceBibliographie*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int InterfaceBibliographie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
