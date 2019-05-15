#ifndef DISTROPARSER_H
#define DISTROPARSER_H

#include <QObject>

class DistroParser : public QObject
{
    Q_OBJECT
public:
    explicit DistroParser(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DISTROPARSER_H