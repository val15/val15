/****************************************************************************
** Meta object code from reading C++ file 'Serveur.h'
**
** Created: Mon Dec 19 16:37:54 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fenetre0/Serveur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Serveur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Serveur[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,   32,   40,   40, 0x05,
      41,   40,   40,   40, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   40,   40,   40, 0x08,
      88,   40,   40,   40, 0x08,
     104,   40,   40,   40, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Serveur[] = {
    "Serveur\0emmetreMessage(QString)\0message\0"
    "\0emmetreDeconnecionClient()\0"
    "nouvelleConnexion()\0donneesRecues()\0"
    "deconnexionClient()\0"
};

void Serveur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Serveur *_t = static_cast<Serveur *>(_o);
        switch (_id) {
        case 0: _t->emmetreMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->emmetreDeconnecionClient(); break;
        case 2: _t->nouvelleConnexion(); break;
        case 3: _t->donneesRecues(); break;
        case 4: _t->deconnexionClient(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Serveur::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Serveur::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Serveur,
      qt_meta_data_Serveur, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Serveur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Serveur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Serveur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Serveur))
        return static_cast<void*>(const_cast< Serveur*>(this));
    return QWidget::qt_metacast(_clname);
}

int Serveur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Serveur::emmetreMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Serveur::emmetreDeconnecionClient()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
