/****************************************************************************
** Meta object code from reading C++ file 'succees.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serveur/succees.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'succees.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sucees_t {
    QByteArrayData data[13];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sucees_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sucees_t qt_meta_stringdata_sucees = {
    {
QT_MOC_LITERAL(0, 0, 6), // "sucees"
QT_MOC_LITERAL(1, 7, 20), // "on_message10_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 21), // "on_message100_clicked"
QT_MOC_LITERAL(4, 51, 22), // "on_message1000_clicked"
QT_MOC_LITERAL(5, 74, 24), // "on_messagemaxint_clicked"
QT_MOC_LITERAL(6, 99, 24), // "on_saveNbMessage_toggled"
QT_MOC_LITERAL(7, 124, 7), // "checked"
QT_MOC_LITERAL(8, 132, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(9, 156, 26), // "on_userdifferent10_clicked"
QT_MOC_LITERAL(10, 183, 26), // "on_userdifferent30_clicked"
QT_MOC_LITERAL(11, 210, 27), // "on_userdifferent100_clicked"
QT_MOC_LITERAL(12, 238, 19) // "on_server20_clicked"

    },
    "sucees\0on_message10_clicked\0\0"
    "on_message100_clicked\0on_message1000_clicked\0"
    "on_messagemaxint_clicked\0"
    "on_saveNbMessage_toggled\0checked\0"
    "on_pushButton_2_clicked\0"
    "on_userdifferent10_clicked\0"
    "on_userdifferent30_clicked\0"
    "on_userdifferent100_clicked\0"
    "on_server20_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sucees[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void sucees::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<sucees *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_message10_clicked(); break;
        case 1: _t->on_message100_clicked(); break;
        case 2: _t->on_message1000_clicked(); break;
        case 3: _t->on_messagemaxint_clicked(); break;
        case 4: _t->on_saveNbMessage_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_userdifferent10_clicked(); break;
        case 7: _t->on_userdifferent30_clicked(); break;
        case 8: _t->on_userdifferent100_clicked(); break;
        case 9: _t->on_server20_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject sucees::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_sucees.data,
    qt_meta_data_sucees,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *sucees::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sucees::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sucees.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int sucees::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
