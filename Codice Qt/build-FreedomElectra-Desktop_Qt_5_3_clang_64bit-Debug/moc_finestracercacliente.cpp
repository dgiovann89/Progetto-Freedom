/****************************************************************************
** Meta object code from reading C++ file 'finestracercacliente.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FreedomElectra/finestracercacliente.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'finestracercacliente.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FinestraCercaCliente_t {
    QByteArrayData data[7];
    char stringdata[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FinestraCercaCliente_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FinestraCercaCliente_t qt_meta_stringdata_FinestraCercaCliente = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 30),
QT_MOC_LITERAL(2, 52, 0),
QT_MOC_LITERAL(3, 53, 12),
QT_MOC_LITERAL(4, 66, 25),
QT_MOC_LITERAL(5, 92, 23),
QT_MOC_LITERAL(6, 116, 5)
    },
    "FinestraCercaCliente\0"
    "apriFinestraClienteSelezionato\0\0"
    "cercaCliente\0rimuoviClienteSelezionato\0"
    "mostraBottoneVisualizza\0torna"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FinestraCercaCliente[] = {

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

void FinestraCercaCliente::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FinestraCercaCliente *_t = static_cast<FinestraCercaCliente *>(_o);
        switch (_id) {
        case 0: _t->apriFinestraClienteSelezionato(); break;
        case 1: _t->cercaCliente(); break;
        case 2: _t->rimuoviClienteSelezionato(); break;
        case 3: _t->mostraBottoneVisualizza(); break;
        case 4: _t->torna(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FinestraCercaCliente::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FinestraCercaCliente.data,
      qt_meta_data_FinestraCercaCliente,  qt_static_metacall, 0, 0}
};


const QMetaObject *FinestraCercaCliente::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FinestraCercaCliente::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FinestraCercaCliente.stringdata))
        return static_cast<void*>(const_cast< FinestraCercaCliente*>(this));
    return QDialog::qt_metacast(_clname);
}

int FinestraCercaCliente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
