#ifndef DEBOOTSTRAPITEM_H
#define DEBOOTSTRAPITEM_H
#include <QObject>
#include "macros/qqmlconstproperty.h"
class DebootstrapItem : public QObject
{
    Q_OBJECT
    QML_CONSTANT_CSTREF_PROPERTY( QString, type )
    QML_CONSTANT_CSTREF_PROPERTY( bool, cache )
public:
    explicit DebootstrapItem( QObject *parent = nullptr ) :
        QObject( parent )
    , m_type( "minbase" )
    , m_cache( true )
    {}
};
#endif // DEBOOTSTRAPITEM_H
