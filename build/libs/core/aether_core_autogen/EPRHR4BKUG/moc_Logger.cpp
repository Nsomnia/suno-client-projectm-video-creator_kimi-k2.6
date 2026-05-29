/****************************************************************************
** Meta object code from reading C++ file 'Logger.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../libs/core/include/aether/core/Logger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Logger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_aether__core__QmlLogger_t {
    const uint offsetsAndSize[12];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_aether__core__QmlLogger_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_aether__core__QmlLogger_t qt_meta_stringdata_aether__core__QmlLogger = {
    {
QT_MOC_LITERAL(0, 23), // "aether::core::QmlLogger"
QT_MOC_LITERAL(24, 4), // "info"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 3), // "msg"
QT_MOC_LITERAL(34, 4), // "warn"
QT_MOC_LITERAL(39, 5) // "error"

    },
    "aether::core::QmlLogger\0info\0\0msg\0"
    "warn\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_aether__core__QmlLogger[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x02,    1 /* Public */,
       4,    1,   35,    2, 0x02,    3 /* Public */,
       5,    1,   38,    2, 0x02,    5 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void aether::core::QmlLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QmlLogger *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->info((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->warn((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject aether::core::QmlLogger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_aether__core__QmlLogger.offsetsAndSize,
    qt_meta_data_aether__core__QmlLogger,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_aether__core__QmlLogger_t
, QtPrivate::TypeAndForceComplete<QmlLogger, std::true_type>

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>

>,
    nullptr
} };


const QMetaObject *aether::core::QmlLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *aether::core::QmlLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_aether__core__QmlLogger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int aether::core::QmlLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
