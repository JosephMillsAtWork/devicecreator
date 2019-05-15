#ifndef DISTROITEM_H
#define DISTROITEM_H
#include <QObject>
#include "macros/qqmlconstproperty.h"
class DistroItem : public QObject
{
    Q_OBJECT
    QML_CONSTANT_CSTREF_PROPERTY( QString, name )
    QML_CONSTANT_CSTREF_PROPERTY( QString, codeName )
    QML_CONSTANT_CSTREF_PROPERTY( QString, description )
    QML_CONSTANT_CSTREF_PROPERTY( QString, maintainer )

    QML_CONSTANT_CSTREF_PROPERTY( QStringList, features )

public:
    explicit DistroItem( QObject *parent = nullptr ) :
        QObject( parent )
    {
    }
};

#endif // DISTROITEM_H
