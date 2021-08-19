/****************************************************************************
** Meta object code from reading C++ file 'parametre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serveur/parametre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parametre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_parametre_t {
    QByteArrayData data[18];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_parametre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_parametre_t qt_meta_stringdata_parametre = {
    {
QT_MOC_LITERAL(0, 0, 9), // "parametre"
QT_MOC_LITERAL(1, 10, 10), // "starttheme"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "darkmode"
QT_MOC_LITERAL(4, 31, 9), // "whitemode"
QT_MOC_LITERAL(5, 41, 21), // "on_checkBox_3_toggled"
QT_MOC_LITERAL(6, 63, 7), // "checked"
QT_MOC_LITERAL(7, 71, 21), // "on_checkBox_2_toggled"
QT_MOC_LITERAL(8, 93, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(9, 113, 23), // "on_comboBox_2_activated"
QT_MOC_LITERAL(10, 137, 4), // "arg1"
QT_MOC_LITERAL(11, 142, 23), // "on_comboBox_3_activated"
QT_MOC_LITERAL(12, 166, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(13, 188, 21), // "on_deletbuton_clicked"
QT_MOC_LITERAL(14, 210, 15), // "on_site_clicked"
QT_MOC_LITERAL(15, 226, 18), // "on_discord_clicked"
QT_MOC_LITERAL(16, 245, 17), // "on_tweter_clicked"
QT_MOC_LITERAL(17, 263, 32) // "on_checkboxmodecondensee_toggled"

    },
    "parametre\0starttheme\0\0darkmode\0whitemode\0"
    "on_checkBox_3_toggled\0checked\0"
    "on_checkBox_2_toggled\0on_checkBox_toggled\0"
    "on_comboBox_2_activated\0arg1\0"
    "on_comboBox_3_activated\0on_comboBox_activated\0"
    "on_deletbuton_clicked\0on_site_clicked\0"
    "on_discord_clicked\0on_tweter_clicked\0"
    "on_checkboxmodecondensee_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_parametre[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    1,   87,    2, 0x08 /* Private */,
       7,    1,   90,    2, 0x08 /* Private */,
       8,    1,   93,    2, 0x08 /* Private */,
       9,    1,   96,    2, 0x08 /* Private */,
      11,    1,   99,    2, 0x08 /* Private */,
      12,    1,  102,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::QPalette,
    QMetaType::QPalette,
    QMetaType::QPalette,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void parametre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<parametre *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QPalette _r = _t->starttheme();
            if (_a[0]) *reinterpret_cast< QPalette*>(_a[0]) = std::move(_r); }  break;
        case 1: { QPalette _r = _t->darkmode();
            if (_a[0]) *reinterpret_cast< QPalette*>(_a[0]) = std::move(_r); }  break;
        case 2: { QPalette _r = _t->whitemode();
            if (_a[0]) *reinterpret_cast< QPalette*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_checkBox_3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_checkBox_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_2_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_comboBox_3_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_deletbuton_clicked(); break;
        case 10: _t->on_site_clicked(); break;
        case 11: _t->on_discord_clicked(); break;
        case 12: _t->on_tweter_clicked(); break;
        case 13: _t->on_checkboxmodecondensee_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject parametre::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_parametre.data,
    qt_meta_data_parametre,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *parametre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *parametre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_parametre.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int parametre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
