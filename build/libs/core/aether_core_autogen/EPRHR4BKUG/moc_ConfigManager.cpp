/****************************************************************************
** Meta object code from reading C++ file 'ConfigManager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../libs/core/include/aether/core/ConfigManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfigManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_aether__core__ConfigManager_t {
    const uint offsetsAndSize[20];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_aether__core__ConfigManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_aether__core__ConfigManager_t qt_meta_stringdata_aether__core__ConfigManager = {
    {
QT_MOC_LITERAL(0, 27), // "aether::core::ConfigManager"
QT_MOC_LITERAL(28, 13), // "configChanged"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 3), // "key"
QT_MOC_LITERAL(47, 8), // "getValue"
QT_MOC_LITERAL(56, 12), // "defaultValue"
QT_MOC_LITERAL(69, 8), // "setValue"
QT_MOC_LITERAL(78, 5), // "value"
QT_MOC_LITERAL(84, 6), // "hasKey"
QT_MOC_LITERAL(91, 5) // "clear"

    },
    "aether::core::ConfigManager\0configChanged\0"
    "\0key\0getValue\0defaultValue\0setValue\0"
    "value\0hasKey\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_aether__core__ConfigManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   47,    2, 0x102,    3 /* Public | MethodIsConst  */,
       6,    2,   52,    2, 0x02,    6 /* Public */,
       8,    1,   57,    2, 0x102,    9 /* Public | MethodIsConst  */,
       9,    0,   60,    2, 0x02,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::QVariant, QMetaType::QString, QMetaType::QVariant,    3,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    3,    7,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void aether::core::ConfigManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConfigManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->configChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: { QVariant _r = _t->getValue((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setValue((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 3: { bool _r = _t->hasKey((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConfigManager::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigManager::configChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject aether::core::ConfigManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_aether__core__ConfigManager.offsetsAndSize,
    qt_meta_data_aether__core__ConfigManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_aether__core__ConfigManager_t
, QtPrivate::TypeAndForceComplete<ConfigManager, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>

, QtPrivate::TypeAndForceComplete<QVariant, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVariant &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>

>,
    nullptr
} };


const QMetaObject *aether::core::ConfigManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *aether::core::ConfigManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_aether__core__ConfigManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int aether::core::ConfigManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void aether::core::ConfigManager::configChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
