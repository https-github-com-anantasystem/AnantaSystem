/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serveur/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[70];
    char stringdata0[1059];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 13), // "startTrayIcon"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 18), // "changetransparency"
QT_MOC_LITERAL(4, 41, 20), // "Qt::ApplicationState"
QT_MOC_LITERAL(5, 62, 5), // "state"
QT_MOC_LITERAL(6, 68, 8), // "condesed"
QT_MOC_LITERAL(7, 77, 25), // "server_displayMessagelist"
QT_MOC_LITERAL(8, 103, 7), // "message"
QT_MOC_LITERAL(9, 111, 12), // "startserveur"
QT_MOC_LITERAL(10, 124, 23), // "server_sentmessagetoall"
QT_MOC_LITERAL(11, 148, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(12, 170, 20), // "server_sentmessageto"
QT_MOC_LITERAL(13, 191, 6), // "messag"
QT_MOC_LITERAL(14, 198, 14), // "NoUtilisateure"
QT_MOC_LITERAL(15, 213, 4), // "type"
QT_MOC_LITERAL(16, 218, 5), // "psedo"
QT_MOC_LITERAL(17, 224, 9), // "usernaime"
QT_MOC_LITERAL(18, 234, 19), // "server_sentcomandto"
QT_MOC_LITERAL(19, 254, 3), // "arg"
QT_MOC_LITERAL(20, 258, 20), // "serveur_sentcommende"
QT_MOC_LITERAL(21, 279, 8), // "commende"
QT_MOC_LITERAL(22, 288, 16), // "server_newconect"
QT_MOC_LITERAL(23, 305, 14), // "server_connect"
QT_MOC_LITERAL(24, 320, 11), // "connectpack"
QT_MOC_LITERAL(25, 332, 19), // "server_datareceived"
QT_MOC_LITERAL(26, 352, 24), // "server_disconnectclients"
QT_MOC_LITERAL(27, 377, 18), // "server_writetofile"
QT_MOC_LITERAL(28, 396, 8), // "FluxFile"
QT_MOC_LITERAL(29, 405, 20), // "server_processcomand"
QT_MOC_LITERAL(30, 426, 7), // "command"
QT_MOC_LITERAL(31, 434, 8), // "noclient"
QT_MOC_LITERAL(32, 443, 19), // "server_generatedate"
QT_MOC_LITERAL(33, 463, 21), // "server_generatemesage"
QT_MOC_LITERAL(34, 485, 21), // "server_recoverallfile"
QT_MOC_LITERAL(35, 507, 16), // "server_findIndex"
QT_MOC_LITERAL(36, 524, 11), // "QTcpSocket*"
QT_MOC_LITERAL(37, 536, 6), // "socket"
QT_MOC_LITERAL(38, 543, 25), // "client_displayMessagelist"
QT_MOC_LITERAL(39, 569, 30), // "client_changestateconnectbuton"
QT_MOC_LITERAL(40, 600, 26), // "client_displayconnectlabel"
QT_MOC_LITERAL(41, 627, 4), // "text"
QT_MOC_LITERAL(42, 632, 22), // "on_conectbuton_clicked"
QT_MOC_LITERAL(43, 655, 20), // "on_sentbuton_clicked"
QT_MOC_LITERAL(44, 676, 22), // "client_processechatbot"
QT_MOC_LITERAL(45, 699, 16), // "client_connectto"
QT_MOC_LITERAL(46, 716, 2), // "ip"
QT_MOC_LITERAL(47, 719, 4), // "port"
QT_MOC_LITERAL(48, 724, 16), // "client_connected"
QT_MOC_LITERAL(49, 741, 17), // "client_desconnect"
QT_MOC_LITERAL(50, 759, 18), // "client_socketerror"
QT_MOC_LITERAL(51, 778, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(52, 807, 5), // "error"
QT_MOC_LITERAL(53, 813, 18), // "client_sentdatamap"
QT_MOC_LITERAL(54, 832, 7), // "sendmap"
QT_MOC_LITERAL(55, 840, 7), // "seconde"
QT_MOC_LITERAL(56, 848, 6), // "minute"
QT_MOC_LITERAL(57, 855, 5), // "heurs"
QT_MOC_LITERAL(58, 861, 6), // "NoJour"
QT_MOC_LITERAL(59, 868, 4), // "jour"
QT_MOC_LITERAL(60, 873, 19), // "client_sentcommende"
QT_MOC_LITERAL(61, 893, 19), // "client_datareceived"
QT_MOC_LITERAL(62, 913, 24), // "client_processthemessage"
QT_MOC_LITERAL(63, 938, 20), // "client_processcomand"
QT_MOC_LITERAL(64, 959, 7), // "commend"
QT_MOC_LITERAL(65, 967, 19), // "client_generatedate"
QT_MOC_LITERAL(66, 987, 4), // "date"
QT_MOC_LITERAL(67, 992, 21), // "client_generatemesage"
QT_MOC_LITERAL(68, 1014, 18), // "client_returnpsedo"
QT_MOC_LITERAL(69, 1033, 25) // "on_parametrebuton_clicked"

    },
    "Widget\0startTrayIcon\0\0changetransparency\0"
    "Qt::ApplicationState\0state\0condesed\0"
    "server_displayMessagelist\0message\0"
    "startserveur\0server_sentmessagetoall\0"
    "QMap<QString,QString>\0server_sentmessageto\0"
    "messag\0NoUtilisateure\0type\0psedo\0"
    "usernaime\0server_sentcomandto\0arg\0"
    "serveur_sentcommende\0commende\0"
    "server_newconect\0server_connect\0"
    "connectpack\0server_datareceived\0"
    "server_disconnectclients\0server_writetofile\0"
    "FluxFile\0server_processcomand\0command\0"
    "noclient\0server_generatedate\0"
    "server_generatemesage\0server_recoverallfile\0"
    "server_findIndex\0QTcpSocket*\0socket\0"
    "client_displayMessagelist\0"
    "client_changestateconnectbuton\0"
    "client_displayconnectlabel\0text\0"
    "on_conectbuton_clicked\0on_sentbuton_clicked\0"
    "client_processechatbot\0client_connectto\0"
    "ip\0port\0client_connected\0client_desconnect\0"
    "client_socketerror\0QAbstractSocket::SocketError\0"
    "error\0client_sentdatamap\0sendmap\0"
    "seconde\0minute\0heurs\0NoJour\0jour\0"
    "client_sentcommende\0client_datareceived\0"
    "client_processthemessage\0client_processcomand\0"
    "commend\0client_generatedate\0date\0"
    "client_generatemesage\0client_returnpsedo\0"
    "on_parametrebuton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  254,    2, 0x08 /* Private */,
       3,    1,  255,    2, 0x08 /* Private */,
       6,    0,  258,    2, 0x08 /* Private */,
       7,    1,  259,    2, 0x08 /* Private */,
       9,    0,  262,    2, 0x08 /* Private */,
      10,    1,  263,    2, 0x08 /* Private */,
      12,    2,  266,    2, 0x08 /* Private */,
      10,    3,  271,    2, 0x08 /* Private */,
      12,    2,  278,    2, 0x08 /* Private */,
      18,    2,  283,    2, 0x08 /* Private */,
      18,    3,  288,    2, 0x08 /* Private */,
      20,    2,  295,    2, 0x08 /* Private */,
      22,    0,  300,    2, 0x08 /* Private */,
      23,    2,  301,    2, 0x08 /* Private */,
      25,    0,  306,    2, 0x08 /* Private */,
      26,    0,  307,    2, 0x08 /* Private */,
      27,    1,  308,    2, 0x08 /* Private */,
      29,    2,  311,    2, 0x08 /* Private */,
      32,    0,  316,    2, 0x08 /* Private */,
      33,    2,  317,    2, 0x08 /* Private */,
      34,    0,  322,    2, 0x08 /* Private */,
      35,    1,  323,    2, 0x08 /* Private */,
      38,    1,  326,    2, 0x08 /* Private */,
      39,    1,  329,    2, 0x08 /* Private */,
      40,    1,  332,    2, 0x08 /* Private */,
      42,    0,  335,    2, 0x08 /* Private */,
      43,    0,  336,    2, 0x08 /* Private */,
      44,    1,  337,    2, 0x08 /* Private */,
      45,    2,  340,    2, 0x08 /* Private */,
      48,    0,  345,    2, 0x08 /* Private */,
      49,    0,  346,    2, 0x08 /* Private */,
      50,    1,  347,    2, 0x08 /* Private */,
      53,    1,  350,    2, 0x08 /* Private */,
      53,    1,  353,    2, 0x08 /* Private */,
      53,    8,  356,    2, 0x08 /* Private */,
      53,    3,  373,    2, 0x08 /* Private */,
      53,    2,  380,    2, 0x08 /* Private */,
      60,    1,  385,    2, 0x08 /* Private */,
      60,    2,  388,    2, 0x08 /* Private */,
      61,    0,  393,    2, 0x08 /* Private */,
      62,    1,  394,    2, 0x08 /* Private */,
      63,    1,  397,    2, 0x08 /* Private */,
      65,    0,  400,    2, 0x08 /* Private */,
      65,    1,  401,    2, 0x08 /* Private */,
      67,    2,  404,    2, 0x08 /* Private */,
      67,    1,  409,    2, 0x08 /* Private */,
      68,    0,  412,    2, 0x08 /* Private */,
      69,    0,  413,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    8,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   15,    8,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    8,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    8,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    8,   19,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,   19,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   24,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   28,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   30,   31,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,   16,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 36,   37,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   46,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 51,   52,
    QMetaType::Void, 0x80000000 | 11,   54,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::QDate,   15,    8,   16,   55,   56,   57,   58,   59,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   15,    8,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,    8,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,   19,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    8,
    QMetaType::Void, 0x80000000 | 11,   64,
    QMetaType::QString,
    QMetaType::QString, 0x80000000 | 11,   66,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,   16,
    QMetaType::QString, 0x80000000 | 11,    8,
    QMetaType::QString,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startTrayIcon(); break;
        case 1: _t->changetransparency((*reinterpret_cast< Qt::ApplicationState(*)>(_a[1]))); break;
        case 2: _t->condesed(); break;
        case 3: _t->server_displayMessagelist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->startserveur(); break;
        case 5: _t->server_sentmessagetoall((*reinterpret_cast< const QMap<QString,QString>(*)>(_a[1]))); break;
        case 6: _t->server_sentmessageto((*reinterpret_cast< const QMap<QString,QString>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->server_sentmessagetoall((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: _t->server_sentmessageto((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->server_sentcomandto((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->server_sentcomandto((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->serveur_sentcommende((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->server_newconect(); break;
        case 13: _t->server_connect((*reinterpret_cast< const QMap<QString,QString>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->server_datareceived(); break;
        case 15: _t->server_disconnectclients(); break;
        case 16: _t->server_writetofile((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 17: _t->server_processcomand((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: { QString _r = _t->server_generatedate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->server_generatemesage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->server_recoverallfile(); break;
        case 21: { int _r = _t->server_findIndex((*reinterpret_cast< QTcpSocket*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->client_displayMessagelist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->client_changestateconnectbuton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->client_displayconnectlabel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->on_conectbuton_clicked(); break;
        case 26: _t->on_sentbuton_clicked(); break;
        case 27: _t->client_processechatbot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->client_connectto((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 29: _t->client_connected(); break;
        case 30: _t->client_desconnect(); break;
        case 31: _t->client_socketerror((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 32: _t->client_sentdatamap((*reinterpret_cast< const QMap<QString,QString>(*)>(_a[1]))); break;
        case 33: _t->client_sentdatamap((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->client_sentdatamap((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QDateTime(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6])),(*reinterpret_cast< QDateTime(*)>(_a[7])),(*reinterpret_cast< QDate(*)>(_a[8]))); break;
        case 35: _t->client_sentdatamap((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 36: _t->client_sentdatamap((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 37: _t->client_sentcommende((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 38: _t->client_sentcommende((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 39: _t->client_datareceived(); break;
        case 40: _t->client_processthemessage((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 41: _t->client_processcomand((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 42: { QString _r = _t->client_generatedate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 43: { QString _r = _t->client_generatedate((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 44: { QString _r = _t->client_generatemesage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 45: { QString _r = _t->client_generatemesage((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 46: { QString _r = _t->client_returnpsedo();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 47: _t->on_parametrebuton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
