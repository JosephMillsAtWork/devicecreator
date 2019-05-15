#ifndef USERITEM_H
#define USERITEM_H
#include <QObject>
#include "macros/qqmlconstproperty.h"
class UserItem : public QObject
{
    Q_OBJECT
    // The extra user name
    QML_CONSTANT_CSTREF_PROPERTY(QString, username)
    // the extra user password
    QML_CONSTANT_CSTREF_PROPERTY(QString, passwd)
    // the groups that the user belongs to.
    QML_CONSTANT_CSTREF_PROPERTY(QStringList, groups)

public:
    explicit UserItem( QObject *parent = nullptr ) :  QObject( parent ) {  }
};
#endif // USERITEM_H
