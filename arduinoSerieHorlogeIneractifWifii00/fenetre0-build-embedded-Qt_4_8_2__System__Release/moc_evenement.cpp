/****************************************************************************
** Meta object code from reading C++ file 'evenement.h'
**
** Created: Mon Dec 19 16:37:39 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fenetre0/evenement.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'evenement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_evenement[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      35,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_evenement[] = {
    "evenement\0lireListe()\0\0supprimer()\0"
    "enregister()\0"
};

void evenement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        evenement *_t = static_cast<evenement *>(_o);
        switch (_id) {
        case 0: _t->lireListe(); break;
        case 1: _t->supprimer(); break;
        case 2: _t->enregister(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData evenement::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject evenement::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_evenement,
      qt_meta_data_evenement, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &evenement::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *evenement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *evenement::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_evenement))
        return static_cast<void*>(const_cast< evenement*>(this));
    return QWidget::qt_metacast(_clname);
}

int evenement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void evenement::lireListe()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
