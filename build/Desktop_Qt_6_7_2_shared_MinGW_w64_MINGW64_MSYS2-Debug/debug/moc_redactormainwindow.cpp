/****************************************************************************
** Meta object code from reading C++ file 'redactormainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../redactormainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'redactormainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSredactorMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSredactorMainWindowENDCLASS = QtMocHelpers::stringData(
    "redactorMainWindow",
    "searchText",
    "",
    "_on_cursorPositionChanged",
    "line",
    "column",
    "_on_showHint",
    "hint",
    "_on_showSearchWindow",
    "_on_hideSearchWindow",
    "_on_pushButton_searchApply_clicked",
    "_on_animateFrameFont",
    "_on_comboBoxTextChanged",
    "newFontStr"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSredactorMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    2,   65,    2, 0x0a,    3 /* Public */,
       6,    1,   70,    2, 0x0a,    6 /* Public */,
       8,    0,   73,    2, 0x0a,    8 /* Public */,
       9,    0,   74,    2, 0x0a,    9 /* Public */,
      10,    0,   75,    2, 0x0a,   10 /* Public */,
      11,    0,   76,    2, 0x0a,   11 /* Public */,
      12,    1,   77,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    1,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject redactorMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSredactorMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSredactorMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSredactorMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<redactorMainWindow, std::true_type>,
        // method 'searchText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method '_on_cursorPositionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method '_on_showHint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method '_on_showSearchWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method '_on_hideSearchWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method '_on_pushButton_searchApply_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method '_on_animateFrameFont'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method '_on_comboBoxTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void redactorMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<redactorMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->searchText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->_on_cursorPositionChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->_on_showHint((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->_on_showSearchWindow(); break;
        case 4: _t->_on_hideSearchWindow(); break;
        case 5: _t->_on_pushButton_searchApply_clicked(); break;
        case 6: _t->_on_animateFrameFont(); break;
        case 7: _t->_on_comboBoxTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (redactorMainWindow::*)(QString );
            if (_t _q_method = &redactorMainWindow::searchText; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *redactorMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *redactorMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSredactorMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int redactorMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void redactorMainWindow::searchText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
