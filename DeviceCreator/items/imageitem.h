#ifndef IMAGEITEM_H
#define IMAGEITEM_H
#include <QObject>
#include "macros/qqmlconstproperty.h"
class ImageItem : public QObject
{
    Q_OBJECT
    QML_CONSTANT_CSTREF_PROPERTY( QString, name )
    QML_CONSTANT_CSTREF_PROPERTY( QString, codeName )
    QML_CONSTANT_CSTREF_PROPERTY( QString, description )
    QML_CONSTANT_CSTREF_PROPERTY( QString, maintainer )

    QML_CONSTANT_CSTREF_PROPERTY( QStringList, features )
    QML_CONSTANT_CSTREF_PROPERTY( QStringList, fsType )

    QML_CONSTANT_CSTREF_PROPERTY( QString, bootPartitionType )
    QML_CONSTANT_CSTREF_PROPERTY( int, bootPartitionSize )

    QML_CONSTANT_CSTREF_PROPERTY( QString, fsPartitionType )
    QML_CONSTANT_CSTREF_PROPERTY( int, fsPartitionSize )

public:
    explicit ImageItem( QObject *parent = nullptr ) :
        QObject( parent )
    {

    }
};

#endif // IMAGEITEM_H
