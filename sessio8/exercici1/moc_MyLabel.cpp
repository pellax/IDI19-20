/****************************************************************************
** Meta object code from reading C++ file 'MyLabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyLabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyLabel_t {
    QByteArrayData data[10];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLabel_t qt_meta_stringdata_MyLabel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyLabel"
QT_MOC_LITERAL(1, 8, 17), // "setTextMajuscules"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "addOneCar"
QT_MOC_LITERAL(4, 37, 10), // "addOneMoto"
QT_MOC_LITERAL(5, 48, 11), // "addOneTruck"
QT_MOC_LITERAL(6, 60, 6), // "addOne"
QT_MOC_LITERAL(7, 67, 16), // "setRecaudacioCar"
QT_MOC_LITERAL(8, 84, 17), // "setRecaudacioMoto"
QT_MOC_LITERAL(9, 102, 18) // "setRecaudacioTruck"

    },
    "MyLabel\0setTextMajuscules\0\0addOneCar\0"
    "addOneMoto\0addOneTruck\0addOne\0"
    "setRecaudacioCar\0setRecaudacioMoto\0"
    "setRecaudacioTruck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       3,    0,   57,    2, 0x0a /* Public */,
       4,    0,   58,    2, 0x0a /* Public */,
       5,    0,   59,    2, 0x0a /* Public */,
       6,    0,   60,    2, 0x0a /* Public */,
       7,    0,   61,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyLabel *_t = static_cast<MyLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTextMajuscules((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addOneCar(); break;
        case 2: _t->addOneMoto(); break;
        case 3: _t->addOneTruck(); break;
        case 4: _t->addOne(); break;
        case 5: _t->setRecaudacioCar(); break;
        case 6: _t->setRecaudacioMoto(); break;
        case 7: _t->setRecaudacioTruck(); break;
        default: ;
        }
    }
}

const QMetaObject MyLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MyLabel.data,
      qt_meta_data_MyLabel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyLabel.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int MyLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
