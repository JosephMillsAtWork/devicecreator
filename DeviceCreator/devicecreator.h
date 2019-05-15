#ifndef DEVICECREATOR_H
#define DEVICECREATOR_H

#include <QObject>

class DeviceCreator : public QObject
{
    Q_OBJECT

public:
    DeviceCreator( QObject *parent = nullptr );
    ~DeviceCreator();
};

#endif // DEVICECREATOR_H
