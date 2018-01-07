/****************************************************************************
** Meta object code from reading C++ file 'Fenetre0.h'
**
** Created: Mon Dec 19 16:37:12 2016
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
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,   23,   23,   23, 0x08,
      24,   23,   23,   23, 0x08,
      31,   23,   23,   23, 0x08,
      55,   23,   23,   23, 0x08,
      79,   23,   23,   23, 0x08,
      97,   23,   23,   23, 0x08,
     127,   23,   23,   23, 0x08,
     157,   23,   23,   23, 0x08,
     181,  202,   23,   23, 0x08,
     210,   23,   23,   23, 0x08,
     239,   23,   23,   23, 0x08,
     251,   23,   23,   23, 0x08,
     268,   23,   23,   23, 0x08,
     293,   23,   23,   23, 0x08,
     322,   23,   23,   23, 0x08,
     345,   23,   23,   23, 0x08,
     370,  390,   23,   23, 0x08,
     392,  412,   23,   23, 0x08,
     414,   23,   23,   23, 0x08,
     427,   23,   23,   23, 0x08,
     437,   23,   23,   23, 0x08,
     449,   23,   23,   23, 0x08,
     457,   23,   23,   23, 0x08,
     473,   23,   23,   23, 0x08,
     489,   23,   23,   23, 0x08,
     500,  530,   23,   23, 0x08,
     534,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaFenetre[] = {
    "MaFenetre\0connection()\0\0temp()\0"
    "ecrireActiverReveille()\0slotEnvoyerEtatAlerte()\0"
    "gererCalendrier()\0lireEvenementDuJourEtProch1()\0"
    "actiVOuDesactiVClignotement()\0"
    "actiVOuDesactiVEspace()\0setRecepton(QString)\0"
    "txtRecu\0desativerActiverAllumeAuto()\0"
    "lireDebit()\0lireEspceLibre()\0"
    "actiVOuDesactiVVitesse()\0"
    "actiVOuDesactiVVitesseAuto()\0"
    "actiVOueteindrePrise()\0allumerOuEteindreLumiR()\0"
    "changerValeurH(int)\0h\0changerValeurV(int)\0"
    "v\0enregister()\0charger()\0supprimer()\0"
    "vider()\0envoyerCoordH()\0envoyerCoordV()\0"
    "readData()\0traiterMessagServeur(QString)\0"
    "msg\0deconnectionClient()\0"
};

void MaFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaFenetre *_t = static_cast<MaFenetre *>(_o);
        switch (_id) {
        case 0: _t->connection(); break;
        case 1: _t->temp(); break;
        case 2: _t->ecrireActiverReveille(); break;
        case 3: _t->slotEnvoyerEtatAlerte(); break;
        case 4: _t->gererCalendrier(); break;
        case 5: _t->lireEvenementDuJourEtProch1(); break;
        case 6: _t->actiVOuDesactiVClignotement(); break;
        case 7: _t->actiVOuDesactiVEspace(); break;
        case 8: _t->setRecepton((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->desativerActiverAllumeAuto(); break;
        case 10: _t->lireDebit(); break;
        case 11: _t->lireEspceLibre(); break;
        case 12: _t->actiVOuDesactiVVitesse(); break;
        case 13: _t->actiVOuDesactiVVitesseAuto(); break;
        case 14: _t->actiVOueteindrePrise(); break;
        case 15: _t->allumerOuEteindreLumiR(); break;
        case 16: _t->changerValeurH((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->changerValeurV((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->enregister(); break;
        case 19: _t->charger(); break;
        case 20: _t->supprimer(); break;
        case 21: _t->vider(); break;
        case 22: _t->envoyerCoordH(); break;
        case 23: _t->envoyerCoordV(); break;
        case 24: _t->readData(); break;
        case 25: _t->traiterMessagServeur((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->deconnectionClient(); break;
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
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
