/****************************************************************************
** Meta object code from reading C++ file 'ivprotocol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../nanosizer/ivprotocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ivprotocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IVProtocol_t {
    QByteArrayData data[29];
    char stringdata0[646];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVProtocol_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVProtocol_t qt_meta_stringdata_IVProtocol = {
    {
QT_MOC_LITERAL(0, 0, 10), // "IVProtocol"
QT_MOC_LITERAL(1, 11, 21), // "RequestUpdateProgress"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "sweepnumber"
QT_MOC_LITERAL(4, 46, 27), // "RequestAddSweepToSweepTable"
QT_MOC_LITERAL(5, 74, 7), // "IVSweep"
QT_MOC_LITERAL(6, 82, 7), // "ivsweep"
QT_MOC_LITERAL(7, 90, 32), // "RequestDeleteSweepFromSweepTable"
QT_MOC_LITERAL(8, 123, 41), // "RequestAddSweepAverageToSweep..."
QT_MOC_LITERAL(9, 165, 15), // "IVSweepAverage&"
QT_MOC_LITERAL(10, 181, 14), // "ivsweepaverage"
QT_MOC_LITERAL(11, 196, 46), // "RequestDeleteSweepAverageFrom..."
QT_MOC_LITERAL(12, 243, 15), // "IVSweepAverage*"
QT_MOC_LITERAL(13, 259, 24), // "RequestUpdateAveragePlot"
QT_MOC_LITERAL(14, 284, 9), // "QCPGraph*"
QT_MOC_LITERAL(15, 294, 5), // "graph"
QT_MOC_LITERAL(16, 300, 15), // "QVector<double>"
QT_MOC_LITERAL(17, 316, 1), // "x"
QT_MOC_LITERAL(18, 318, 1), // "y"
QT_MOC_LITERAL(19, 320, 32), // "RequestSetPlotStyleActiveForward"
QT_MOC_LITERAL(20, 353, 39), // "RequestSetPlotStyleAverageAct..."
QT_MOC_LITERAL(21, 393, 32), // "RequestSetPlotStyleActiveReverse"
QT_MOC_LITERAL(22, 426, 39), // "RequestSetPlotStyleAverageAct..."
QT_MOC_LITERAL(23, 466, 34), // "RequestSetPlotStyleInactiveFo..."
QT_MOC_LITERAL(24, 501, 41), // "RequestSetPlotStyleAverageIna..."
QT_MOC_LITERAL(25, 543, 34), // "RequestSetPlotStyleInactiveRe..."
QT_MOC_LITERAL(26, 578, 41), // "RequestSetPlotStyleAverageIna..."
QT_MOC_LITERAL(27, 620, 10), // "RunRoutine"
QT_MOC_LITERAL(28, 631, 14) // "UnpauseRoutine"

    },
    "IVProtocol\0RequestUpdateProgress\0\0"
    "sweepnumber\0RequestAddSweepToSweepTable\0"
    "IVSweep\0ivsweep\0RequestDeleteSweepFromSweepTable\0"
    "RequestAddSweepAverageToSweepAverageTable\0"
    "IVSweepAverage&\0ivsweepaverage\0"
    "RequestDeleteSweepAverageFromSweepAverageTable\0"
    "IVSweepAverage*\0RequestUpdateAveragePlot\0"
    "QCPGraph*\0graph\0QVector<double>\0x\0y\0"
    "RequestSetPlotStyleActiveForward\0"
    "RequestSetPlotStyleAverageActiveForward\0"
    "RequestSetPlotStyleActiveReverse\0"
    "RequestSetPlotStyleAverageActiveReverse\0"
    "RequestSetPlotStyleInactiveForward\0"
    "RequestSetPlotStyleAverageInactiveForward\0"
    "RequestSetPlotStyleInactiveReverse\0"
    "RequestSetPlotStyleAverageInactiveReverse\0"
    "RunRoutine\0UnpauseRoutine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVProtocol[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       7,    1,  100,    2, 0x06 /* Public */,
       8,    1,  103,    2, 0x06 /* Public */,
      11,    1,  106,    2, 0x06 /* Public */,
      13,    3,  109,    2, 0x06 /* Public */,
      19,    1,  116,    2, 0x06 /* Public */,
      20,    1,  119,    2, 0x06 /* Public */,
      21,    1,  122,    2, 0x06 /* Public */,
      22,    1,  125,    2, 0x06 /* Public */,
      23,    1,  128,    2, 0x06 /* Public */,
      24,    1,  131,    2, 0x06 /* Public */,
      25,    1,  134,    2, 0x06 /* Public */,
      26,    1,  137,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      27,    0,  140,    2, 0x0a /* Public */,
      28,    0,  141,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   10,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 16, 0x80000000 | 16,   15,   17,   18,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IVProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IVProtocol *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestUpdateProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->RequestAddSweepToSweepTable((*reinterpret_cast< const IVSweep(*)>(_a[1]))); break;
        case 2: _t->RequestDeleteSweepFromSweepTable((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 3: _t->RequestAddSweepAverageToSweepAverageTable((*reinterpret_cast< IVSweepAverage(*)>(_a[1]))); break;
        case 4: _t->RequestDeleteSweepAverageFromSweepAverageTable((*reinterpret_cast< IVSweepAverage*(*)>(_a[1]))); break;
        case 5: _t->RequestUpdateAveragePlot((*reinterpret_cast< QCPGraph*(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 6: _t->RequestSetPlotStyleActiveForward((*reinterpret_cast< QCPGraph*(*)>(_a[1]))); break;
        case 7: _t->RequestSetPlotStyleAverageActiveForward((*reinterpret_cast< QCPGraph*(*)>(_a[1]))); break;
        case 8: _t->RequestSetPlotStyleActiveReverse((*reinterpret_cast< QCPGraph*(*)>(_a[1]))); break;
        case 9: _t->RequestSetPlotStyleAverageActiveReverse((*reinterpret_cast< QCPGraph*(*)>(_a[1]))); break;
        case 10: _t->RequestSetPlotStyleInactiveForward((*reinterpret_cast< QCPGraph*(*)>(_a[1]))); break;
        case 11: _t->RequestSetPlotStyleAverageInactiveForward((*reinterpret_cast< QCPGraph*(*)>(_a[1]))); break;
        case 12: _t->RequestSetPlotStyleInactiveReverse((*reinterpret_cast< QCPGraph*(*)>(_a[1]))); break;
        case 13: _t->RequestSetPlotStyleAverageInactiveReverse((*reinterpret_cast< QCPGraph*(*)>(_a[1]))); break;
        case 14: _t->RunRoutine(); break;
        case 15: _t->UnpauseRoutine(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
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
            using _t = void (IVProtocol::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestUpdateProgress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(const IVSweep & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestAddSweepToSweepTable)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(const unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestDeleteSweepFromSweepTable)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(IVSweepAverage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestAddSweepAverageToSweepAverageTable)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(IVSweepAverage * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestDeleteSweepAverageFromSweepAverageTable)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(QCPGraph * , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestUpdateAveragePlot)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(QCPGraph * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestSetPlotStyleActiveForward)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(QCPGraph * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestSetPlotStyleAverageActiveForward)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(QCPGraph * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestSetPlotStyleActiveReverse)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(QCPGraph * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestSetPlotStyleAverageActiveReverse)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(QCPGraph * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestSetPlotStyleInactiveForward)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(QCPGraph * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestSetPlotStyleAverageInactiveForward)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(QCPGraph * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestSetPlotStyleInactiveReverse)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (IVProtocol::*)(QCPGraph * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IVProtocol::RequestSetPlotStyleAverageInactiveReverse)) {
                *result = 13;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IVProtocol::staticMetaObject = { {
    QMetaObject::SuperData::link<MeasurementProtocol::staticMetaObject>(),
    qt_meta_stringdata_IVProtocol.data,
    qt_meta_data_IVProtocol,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IVProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IVProtocol.stringdata0))
        return static_cast<void*>(this);
    return MeasurementProtocol::qt_metacast(_clname);
}

int IVProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MeasurementProtocol::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void IVProtocol::RequestUpdateProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IVProtocol::RequestAddSweepToSweepTable(const IVSweep & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IVProtocol::RequestDeleteSweepFromSweepTable(const unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IVProtocol::RequestAddSweepAverageToSweepAverageTable(IVSweepAverage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void IVProtocol::RequestDeleteSweepAverageFromSweepAverageTable(IVSweepAverage * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void IVProtocol::RequestUpdateAveragePlot(QCPGraph * _t1, QVector<double> _t2, QVector<double> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void IVProtocol::RequestSetPlotStyleActiveForward(QCPGraph * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void IVProtocol::RequestSetPlotStyleAverageActiveForward(QCPGraph * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void IVProtocol::RequestSetPlotStyleActiveReverse(QCPGraph * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void IVProtocol::RequestSetPlotStyleAverageActiveReverse(QCPGraph * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void IVProtocol::RequestSetPlotStyleInactiveForward(QCPGraph * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void IVProtocol::RequestSetPlotStyleAverageInactiveForward(QCPGraph * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void IVProtocol::RequestSetPlotStyleInactiveReverse(QCPGraph * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void IVProtocol::RequestSetPlotStyleAverageInactiveReverse(QCPGraph * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
