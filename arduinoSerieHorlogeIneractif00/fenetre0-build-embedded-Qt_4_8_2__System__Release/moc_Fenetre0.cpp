/****************************************************************************
** Meta object code from reading C++ file 'Fenetre0.h'
**
** Created: Wed Sep 7 23:24:00 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fenetre0/Fenetre0.h"
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
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,   23,   23,   23, 0x08,
      24,   23,   23,   23, 0x08,
      33,   23,   23,   23, 0x08,
      40,   23,   23,   23, 0x08,
      64,   23,   23,   23, 0x08,
      88,   23,   23,   23, 0x08,
     106,   23,   23,   23, 0x08,
     136,   23,   23,   23, 0x08,
     166,   23,   23,   23, 0x08,
     191,   23,   23,   23, 0x08,
     215,  236,   23,   23, 0x08,
     244,   23,   23,   23, 0x08,
     273,   23,   23,   23, 0x08,
     285,   23,   23,   23, 0x08,
     302,   23,   23,   23, 0x08,
     325,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaFenetre[] = {
    "MaFenetre\0connection()\0\0enoyer()\0"
    "temp()\0ecrireActiverReveille()\0"
    "slotEnvoyerEtatAlerte()\0gererCalendrier()\0"
    "lireEvenementDuJourEtProch1()\0"
    "actiVOuDesactiVClignotement()\0"
    "actiVOuDesactiVVitesse()\0"
    "actiVOuDesactiVEspace()\0setRecepton(QString)\0"
    "txtRecu\0desativerActiverAllumeAuto()\0"
    "lireDedit()\0lireEspceLibre()\0"
    "actiVOueteindrePrise()\0allumerOuEteindreLumiR()\0"
};

void MaFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaFenetre *_t = static_cast<MaFenetre *>(_o);
        switch (_id) {
        case 0: _t->connection(); break;
        case 1: _t->enoyer(); break;
        case 2: _t->temp(); break;
        case 3: _t->ecrireActiverReveille(); break;
        case 4: _t->slotEnvoyerEtatAlerte(); break;
        case 5: _t->gererCalendrier(); break;
        case 6: _t->lireEvenementDuJourEtProch1(); break;
        case 7: _t->actiVOuDesactiVClignotement(); break;
        case 8: _t->actiVOuDesactiVVitesse(); break;
        case 9: _t->actiVOuDesactiVEspace(); break;
        case 10: _t->setRecepton((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->desativerActiverAllumeAuto(); break;
        case 12: _t->lireDedit(); break;
        case 13: _t->lireEspceLibre(); break;
        case 14: _t->actiVOueteindrePrise(); break;
        case 15: _t->allumerOuEteindreLumiR(); break;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
