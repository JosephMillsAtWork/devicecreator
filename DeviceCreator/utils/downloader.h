#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

using namespace  QtConcurrent;

class Downloader : public QObject
{
    Q_OBJECT
    Q_PROPERTY( Provider provider READ provider WRITE setProvider NOTIFY providerChanged )
    Q_ENUMS( Provider )

public:
    explicit Downloader(QObject *parent = nullptr);
    enum Provider{
        WGET = 0,
        GIT = 1,
        SVN = 2,
        BZR = 3,
        QNAM = 4,
        CVS = 5,
        HG = 6,
        CURL = 7,
    };

    Provider provider() const;
    void setProvider( const Provider &provider );


signals:
    void providerChanged();

private:
    Provider m_provider;

};

#endif // DOWNLOADER_H
