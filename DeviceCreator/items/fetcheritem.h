#ifndef FETCHERITEM_H
#define FETCHERITEM_H
#include <QObject>
#include "macros/qqmlconstproperty.h"

class FetcherItem : public QObject
{
    Q_OBJECT

    // ssh://whatever.com/something.git
    QML_CONSTANT_CSTREF_PROPERTY( QString, uri )
    // git, ssh, file, http[s]
    QML_CONSTANT_CSTREF_PROPERTY( QString, protocol )
    // branch
    QML_CONSTANT_CSTREF_PROPERTY( QString, branch )
    // sha
    QML_CONSTANT_CSTREF_PROPERTY( QString, srcRev )

public:
    explicit FetcherItem( QObject *parent = nullptr ) :  QObject( parent ) {  }
};

#endif // FETCHERITEM_H
