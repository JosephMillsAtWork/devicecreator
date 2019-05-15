#ifndef WGETRUNNER_H
#define WGETRUNNER_H

#include <QObject>
#include <QProcess>
#include <QUrl>
#include "macros/qqmlconstproperty.h"

class WgetRunner : public QProcess
{
    Q_OBJECT
    QML_CONSTANT_CSTREF_PROPERTY( QString, downloadDir )
    QML_CONSTANT_CSTREF_PROPERTY( QString, url)

    QML_CONSTANT_CSTREF_PROPERTY( QString, outputName )
    QML_CONSTANT_CSTREF_PROPERTY( QString, environment )

public:

    explicit WgetRunner( QObject *parent = nullptr );

    QString get_arguments() const 
    {
        QString ret = QString();
        QString outName = m_outputName.isEmpty() ? QUrl( m_url ).fileName() : m_outputName;
        if( !m_url.isEmpty() && !m_downloadDir.isEmpty() )
        {
        ret = QString( "-c /usr/bin/env wget -t 2 -T 30 --passive-ftp --no-check-certificate -P %1 '%2' -O '%3' --progress=dot -v" )
                .arg( m_downloadDir )
                .arg( m_url )
                .arg( outName );
        }
        return ret;
    }

private: 
    QString m_bash;
};

#endif // WGETRUNNER_H
