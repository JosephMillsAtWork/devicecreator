#ifndef PACKAGEPARSER_H
#define PACKAGEPARSER_H

#include <QObject>

class PackageParser : public QObject
{
    Q_OBJECT
public:
    explicit PackageParser(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PACKAGEPARSER_H