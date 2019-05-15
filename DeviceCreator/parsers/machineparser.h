#ifndef MACHINEPARSER_H
#define MACHINEPARSER_H

#include <QObject>

class MachineParser : public QObject
{
    Q_OBJECT
public:
    explicit MachineParser(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MACHINEPARSER_H