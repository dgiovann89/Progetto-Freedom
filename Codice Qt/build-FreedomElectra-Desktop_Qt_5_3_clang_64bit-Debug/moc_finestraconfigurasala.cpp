/****************************************************************************
** Meta object code from reading C++ file 'finestraconfigurasala.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FreedomElectra/finestraconfigurasala.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'finestraconfigurasala.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FinestraConfiguraSala_t {
    QByteArrayData data[7];
    char stringdata[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FinestraConfiguraSala_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FinestraConfiguraSala_t qt_meta_stringdata_FinestraConfiguraSala = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 25),
QT_MOC_LITERAL(2, 48, 0),
QT_MOC_LITERAL(3, 49, 31),
QT_MOC_LITERAL(4, 81, 32),
QT_MOC_LITERAL(5, 114, 17),
QT_MOC_LITERAL(6, 132, 5)
    },
    "FinestraConfiguraSala\0apriFinestraInserisciSala\0"
    "\0apriFinestraInserisciComponente\0"
    "apriFinestraVisualizzaComponente\0"
    "eliminaComponente\0torna"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FinestraConfiguraSala[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FinestraConfiguraSala::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FinestraConfiguraSala *_t = static_cast<FinestraConfiguraSala *>(_o);
        switch (_id) {
        case 0: _t->apriFinestraInserisciSala(); break;
        case 1: _t->apriFinestraInserisciComponente(); break;
        case 2: _t->apriFinestraVisualizzaComponente(); break;
        case 3: _t->eliminaComponente(); break;
        case 4: _t->torna(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FinestraConfiguraSala::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FinestraConfiguraSala.data,
      qt_meta_data_FinestraConfiguraSala,  qt_static_metacall, 0, 0}
};


const QMetaObject *FinestraConfiguraSala::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FinestraConfiguraSala::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FinestraConfiguraSala.stringdata))
        return static_cast<void*>(const_cast< FinestraConfiguraSala*>(this));
    return QDialog::qt_metacast(_clname);
}

int FinestraConfiguraSala::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
