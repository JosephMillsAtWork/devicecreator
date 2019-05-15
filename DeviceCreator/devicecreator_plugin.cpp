#include "devicecreator_plugin.h"
#include "devicecreator.h"

#include <qqml.h>

void DeviceCreatorPlugin::registerTypes(const char *uri)
{
    // @uri DeviceCreator
    qmlRegisterType<DeviceCreator>(uri, 1, 0, "DeviceCreator");
}

