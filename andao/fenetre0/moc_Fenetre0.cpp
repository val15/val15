/****************************************************************************
** Meta object code from reading C++ file 'Fenetre0.h'
**
** Created: Tue Jun 21 13:20:54 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Fenetre0.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Fenetre0.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MaFenetre[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,   23,   23,   23, 0x08,
      24,   23,   23,   23, 0x08,
      35,   23,   23,   23, 0x08,
      46,   23,   23,   23, 0x08,
      55,   23,   23,   23, 0x08,
      78,   23,   23,   23, 0x08,
      98,   23,   23,   23, 0x08,
     120,   23,   23,   23, 0x08,
     142,   23,   23,   23, 0x08,
     152,   23,   23,   23, 0x08,
     165,   23,   23,   23, 0x08,
     185,   23,   23,   23, 0x08,
     208,   23,   23,   23, 0x08,
     230,   23,   23,   23, 0x08,
     246,   23,   23,   23, 0x08,
     257,   23,   23,   23, 0x08,
     273,  295,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaFenetre[] = {
    "MaFenetre\0connection()\0\0sendData()\0"
    "readData()\0enoyer()\0lancerEnregistrement()\0"
    "incrementerTmptrj()\0incrementerCompteur()\0"
    "tretementTrjLecture()\0playTrj()\0"
    "playTrjInv()\0playTrjEnregistrE()\0"
    "playInvTrjEnregistrE()\0modifNomEreregister()\0"
    "enregisterTrj()\0mazTemps()\0lancerServeur()\0"
    "afficherInfo(QString)\0info\0"
};

void MaFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaFenetre *_t = static_cast<MaFenetre *>(_o);
        switch (_id) {
        case 0: _t->connection(); break;
        case 1: _t->sendData(); break;
        case 2: _t->readData(); break;
        case 3: _t->enoyer(); break;
        case 4: _t->lancerEnregistrement(); break;
        case 5: _t->incrementerTmptrj(); break;
        case 6: _t->incrementerCompteur(); break;
        case 7: _t->tretementTrjLecture(); break;
        case 8: _t->playTrj(); break;
        case 9: _t->playTrjInv(); break;
        case 10: _t->playTrjEnregistrE(); break;
        case 11: _t->playInvTrjEnregistrE(); break;
        case 12: _t->modifNomEreregister(); break;
        case 13: _t->enregisterTrj(); break;
        case 14: _t->mazTemps(); break;
        case 15: _t->lancerServeur(); break;
        case 16: _t->afficherInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaFenetre::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaFenetre::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MaFenetre,
      qt_meta_data_MaFenetre, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaFenetre::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaFenetre))
        return static_cast<void*>(const_cast< MaFenetre*>(this));
    return QWidget::qt_metacast(_clname);
}

int MaFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
