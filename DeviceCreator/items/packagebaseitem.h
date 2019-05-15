#ifndef PACKAGEBASEITEM_H
#define PACKAGEBASEITEM_H
#include "fetcheritem.h"
class PackageBaseItem : public FetcherItem
{
    Q_OBJECT
    // the name of the package
    QML_CONSTANT_CSTREF_PROPERTY( QString, name )
    // the description of the package
    QML_CONSTANT_CSTREF_PROPERTY( QString, description )
    // the license used
    QML_CONSTANT_CSTREF_PROPERTY( QString, license )
    // the sha to check against
    QML_CONSTANT_CSTREF_PROPERTY( QString, sha )
    // the license sha
    QML_CONSTANT_CSTREF_PROPERTY( QString, licSha )
    // the major version
    QML_CONSTANT_CSTREF_PROPERTY( int, majorVersion )
    // the minor version
    QML_CONSTANT_CSTREF_PROPERTY( int, minorVersion )
    // the major and minor version.  this is set automatcily
    QML_READONLY_CSTREF_PROPERTY( QString, version )

    // the section that your pakage goes to
    // "development" "education" "game" "graphics" "multimedia" "networking" "settings" "system" "utils"
    QML_CONSTANT_CSTREF_PROPERTY( QString, section )

    // runtime dependencies
    QML_CONSTANT_CSTREF_PROPERTY( QStringList, depends )
    // build time dependencies
    QML_CONSTANT_CSTREF_PROPERTY( QStringList, buildDepends )
    // suggeded enhancement packages
    QML_CONSTANT_CSTREF_PROPERTY( QStringList, suggestions )

public:
    explicit PackageBaseItem( FetcherItem *parent = nullptr ) :
       FetcherItem( parent )
    {
    }
};

#endif // PACKAGEBASEITEM_H
