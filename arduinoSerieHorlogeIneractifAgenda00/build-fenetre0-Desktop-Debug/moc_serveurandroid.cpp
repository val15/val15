/****************************************************************************
** Meta object code from reading C++ file 'serveurandroid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../arduinoSerieHorlogeIneractifAgendaServeur/fenetre0/serveurandroid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serveurandroid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ServeurAndroid_t {
    QByteArrayData data[10];
    char stringdata[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServeurAndroid_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServeurAndroid_t qt_meta_stringdata_ServeurAndroid = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 18),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 7),
QT_MOC_LITERAL(4, 43, 17),
QT_MOC_LITERAL(5, 61, 12),
QT_MOC_LITERAL(6, 74, 24),
QT_MOC_LITERAL(7, 99, 17),
QT_MOC_LITERAL(8, 117, 13),
QT_MOC_LITERAL(9, 131, 17)
    },
    "ServeurAndroid\0emmetreMessageRecu\0\0"
    "message\0indiceDeLEnvoyeur\0typeDuSeveur\0"
    "emmetreDeconnecionClient\0nouvelleConnexion\0"
    "donneesRecues\0deconnexionClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServeurAndroid[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       6,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   47,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ServeurAndroid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServeurAndroid *_t = static_cast<ServeurAndroid *>(_o);
        switch (_id) {
        case 0: _t->emmetreMessageRecu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->emmetreDeconnecionClient(); break;
        case 2: _t->nouvelleConnexion(); break;
        case 3: _t->donneesRecues(); break;
        case 4: _t->deconnexionClient(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ServeurAndroid::*_t)(QString , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServeurAndroid::emmetreMessageRecu)) {
                *result = 0;
            }
        }
        {
            typedef void (ServeurAndroid::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServeurAndroid::emmetreDeconnecionClient)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ServeurAndroid::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ServeurAndroid.data,
      qt_meta_data_ServeurAndroid,  qt_static_metacall, 0, 0}
};


const QMetaObject *ServeurAndroid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServeurAndroid::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServeurAndroid.stringdata))
        return static_cast<void*>(const_cast< ServeurAndroid*>(this));
    return QWidget::qt_metacast(_clname);
}

int ServeurAndroid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ServeurAndroid::emmetreMessageRecu(QString _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServeurAndroid::emmetreDeconnecionClient()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
