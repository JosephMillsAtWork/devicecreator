#ifndef PACKAGEITEM_H
#define PACKAGEITEM_H
#include "packagebaseitem.h"
class PackageItem : public PackageBaseItem
{
    Q_OBJECT
    // instructions to fetch
    QML_CONSTANT_CSTREF_PROPERTY( QString, fetch )
    QML_CONSTANT_CSTREF_PROPERTY( QString, pre_fetch )
    QML_CONSTANT_CSTREF_PROPERTY( QString, post_fetch )
    // instructions to configure.
    QML_CONSTANT_CSTREF_PROPERTY( QString, configure )
    QML_CONSTANT_CSTREF_PROPERTY( QString, pre_configure )
    QML_CONSTANT_CSTREF_PROPERTY( QString, post_configure )
    // instructions to compile
    QML_CONSTANT_CSTREF_PROPERTY( QString, compile )
    QML_CONSTANT_CSTREF_PROPERTY( QString, pre_compile )
    QML_CONSTANT_CSTREF_PROPERTY( QString, post_compile )
    // instructions to install
    QML_CONSTANT_CSTREF_PROPERTY( QString, install )
    QML_CONSTANT_CSTREF_PROPERTY( QString, pre_install )
    QML_CONSTANT_CSTREF_PROPERTY( QString, post_install )

    // instructions to clean
    QML_CONSTANT_CSTREF_PROPERTY( QString, clean )
    QML_CONSTANT_CSTREF_PROPERTY( QString, pre_clean )
    QML_CONSTANT_CSTREF_PROPERTY( QString, post_clean )
    // instructions to package
    QML_CONSTANT_CSTREF_PROPERTY( QString, package )
    QML_CONSTANT_CSTREF_PROPERTY( QString, pre_package )
    QML_CONSTANT_CSTREF_PROPERTY( QString, post_package )
public:
    explicit PackageItem( PackageBaseItem *parent = nullptr ) :
        PackageBaseItem( parent )
    {
    }
};

#endif // PACKAGEITEM_H
