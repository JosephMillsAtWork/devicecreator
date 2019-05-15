TEMPLATE = lib
TARGET = DeviceCreator
QT += qml quick core network concurrent
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = DeviceCreator

# Input
SOURCES += \
    $$PWD/devicecreator_plugin.cpp \
    $$PWD/devicecreator.cpp \
    $$PWD/parsers/packageparser.cpp \
    $$PWD/parsers/machineparser.cpp \
    $$PWD/parsers/distroparser.cpp \
    $$PWD/parsers/linaroparser.cpp \
    $$PWD/utils/downloader.cpp \
    $$PWD/utils/buildwriter.cpp \
    $$PWD/utils/wgetrunner.cpp \
    $$PWD/utils/hostinformation.cpp \
    parsers/bbparser.cpp

HEADERS += \
    $$PWD/devicecreator_plugin.h \
    $$PWD/devicecreator.h \
    $$PWD/models/qqmlobjectlistmodel.h \
    $$PWD/macros/qqmlassert.h \
    $$PWD/macros/qqmlconstproperty.h \
    $$PWD/macros/qqmlhelperscommon.h \
    $$PWD/macros/qqmlptrpropertyhelpers.h \
    $$PWD/macros/qqmlsingletonhelper.h \
    $$PWD/items/useritem.h \
    $$PWD/items/debootstrapitem.h \
    $$PWD/items/packageitem.h \
    $$PWD/items/fetcheritem.h \
    $$PWD/items/packagebaseitem.h \
    $$PWD/items/machineitem.h \
    $$PWD/items/imageitem.h \
    $$PWD/items/distroitem.h \
    $$PWD/items/toolchainitem.h \
    $$PWD/parsers/packageparser.h \
    $$PWD/parsers/machineparser.h \
    $$PWD/parsers/distroparser.h \
    $$PWD/parsers/linaroparser.h \
    $$PWD/utils/downloader.h \
    $$PWD/utils/buildwriter.h \
    $$PWD/utils/wgetrunner.h \
    $$PWD/utils/hostinformation.h \
    parsers/bbparser.h

DISTFILES = $$PWD/qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir

unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
