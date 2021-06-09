/****************************************************************************
** Meta object code from reading C++ file 'measurementprotocol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../nanosizer/measurementprotocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'measurementprotocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MeasurementProtocol_t {
    QByteArrayData data[15];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeasurementProtocol_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeasurementProtocol_t qt_meta_stringdata_MeasurementProtocol = {
    {
QT_MOC_LITERAL(0, 0, 19), // "MeasurementProtocol"
QT_MOC_LITERAL(1, 20, 17), // "RequestRunRoutine"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 17), // "RequestEndRoutine"
QT_MOC_LITERAL(4, 57, 17), // "RequestUpdatePlot"
QT_MOC_LITERAL(5, 75, 9), // "QCPGraph*"
QT_MOC_LITERAL(6, 85, 5), // "graph"
QT_MOC_LITERAL(7, 91, 15), // "QVector<double>"
QT_MOC_LITERAL(8, 107, 1), // "x"
QT_MOC_LITERAL(9, 109, 1), // "y"
QT_MOC_LITERAL(10, 111, 11), // "graphnumber"
QT_MOC_LITERAL(11, 123, 22), // "RequestCoProtocolPause"
QT_MOC_LITERAL(12, 146, 24), // "RequestCoProtocolUnpause"
QT_MOC_LITERAL(13, 171, 10), // "RunRoutine"
QT_MOC_LITERAL(14, 182, 14) // "UnpauseRoutine"

    },
    "MeasurementProtocol\0RequestRunRoutine\0"
    "\0RequestEndRoutine\0RequestUpdatePlot\0"
    "QCPGraph*\0graph\0QVector<double>\0x\0y\0"
    "graphnumber\0RequestCoProtocolPause\0"
    "RequestCoProtocolUnpause\0RunRoutine\0"
    "UnpauseRoutine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeasurementProtocol[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    3,   56,    2, 0x06 /* Public */,
       4,    3,   63,    2, 0x06 /* Public */,
      11,    0,   70,    2, 0x06 /* Public */,
      12,    0,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   72,    2, 0x0a /* Public */,
      14,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 7,    6,    8,    9,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7, 0x80000000 | 7,   10,    8,    9,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MeasurementProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MeasurementProtocol *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestRunRoutine(); break;
        case 1: _t->RequestEndRoutine(); break;
        case 2: _t->RequestUpdatePlot((*reinterpret_cast< QCPGraph*(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 3: _t->RequestUpdatePlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 4: _t->RequestCoProtocolPause(); break;
        case 5: _t->RequestCoProtocolUnpause(); break;
        case 6: _t->RunRoutine(); break;
        case 7: _t->UnpauseRoutine(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MeasurementProtocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementProtocol::RequestRunRoutine)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MeasurementProtocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementProtocol::RequestEndRoutine)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MeasurementProtocol::*)(QCPGraph * , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementProtocol::RequestUpdatePlot)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MeasurementProtocol::*)(int , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementProtocol::RequestUpdatePlot)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MeasurementProtocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementProtocol::RequestCoProtocolPause)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MeasurementProtocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasurementProtocol::RequestCoProtocolUnpause)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MeasurementProtocol::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MeasurementProtocol.data,
    qt_meta_data_MeasurementProtocol,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MeasurementProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeasurementProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MeasurementProtocol.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MeasurementProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MeasurementProtocol::RequestRunRoutine()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MeasurementProtocol::RequestEndRoutine()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MeasurementProtocol::RequestUpdatePlot(QCPGraph * _t1, QVector<double> _t2, QVector<double> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MeasurementProtocol::RequestUpdatePlot(int _t1, QVector<double> _t2, QVector<double> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MeasurementProtocol::RequestCoProtocolPause()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MeasurementProtocol::RequestCoProtocolUnpause()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
