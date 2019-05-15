#ifndef MACHINEITEM_H
#define MACHINEITEM_H
#include <QObject>
#include "macros/qqmlconstproperty.h"
class MachineItem : public QObject
{
    Q_OBJECT
    QML_CONSTANT_CSTREF_PROPERTY( QString, name )
    QML_CONSTANT_CSTREF_PROPERTY( QString, decription )
    QML_CONSTANT_CSTREF_PROPERTY( QString, codeName )
    QML_CONSTANT_CSTREF_PROPERTY( int, majVersion )
    QML_CONSTANT_CSTREF_PROPERTY( int, minVersion )

    QML_CONSTANT_CSTREF_PROPERTY( QStringList, features )
    QML_CONSTANT_CSTREF_PROPERTY( QString, serial )

public:
    explicit MachineItem( QObject *parent = nullptr ) :  QObject( parent ) {}
};

#endif // MACHINEITEM_H
