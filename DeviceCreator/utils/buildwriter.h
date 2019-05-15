#ifndef BUILDWRITER_H
#define BUILDWRITER_H

#include <QObject>

class BuildWriter : public QObject
{
    Q_OBJECT
public:
    explicit BuildWriter(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BUILDWRITER_H