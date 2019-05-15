#include "linaroparser.h"

LinaroParser::LinaroParser(QObject *parent) :
    QObject( parent )
  , m_status( Stopped )
{
    m_multiarch = QStringList()
            << "aarch64-elf"
            << "aarch64-linux-gnu"
            << "aarch64_be-elf"
            << "aarch64_be-linux-gnu"
            << "arm-eabi"
            << "arm-linux-gnueabi"
            << "arm-linux-gnueabihf"
            << "armeb-eabi"
            << "armeb-linux-gnueabi"
            << "armeb-linux-gnueabihf"
            << "armv8l-linux-gnueabihf";
    m_hostarchs = QStringList() << "minw32" << "i686" << "x86_64";
}

LinaroParser::~LinaroParser()
{
    manager = nullptr;
    delete manager;

    reply = nullptr ;
    delete  reply;
}

void LinaroParser::parse()
{
    manager = new QNetworkAccessManager;
    reply = manager->get( QNetworkRequest( QUrl( uri ) ) );
    setStatus( Running );
    connect( manager, &QNetworkAccessManager::finished,
             this, &LinaroParser::replyFinished );
    connect( reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
             [=]( QNetworkReply::NetworkError code ){
        Q_UNUSED( code )
        setStatus(Stopped);
    });

}

QStringList LinaroParser::getMultiarchs() const
{
    return m_multiarch;
}

QStringList LinaroParser::getHostArchs() const
{
    return m_hostarchs;
}

LinaroParser::Status LinaroParser::status() const
{
    return m_status;
}
/*!
 * \brief LinaroParser::replyFinished
 * \param reply
 * a hacky way to get all the versions of the linaro toolchains
 */
void LinaroParser::replyFinished( QNetworkReply *reply )
{
    if( reply->isReadable() )
    {

        QString bat = reply->readAll();
        QStringList  sList = bat.split( "\n" );

        m_versions.clear();
        for( QString s : sList )
        {
            if( s.simplified().startsWith( ">" ) &&
                    s.simplified().endsWith( "</a>" ) )
            {
                QString hackedUpStr =  s.replace( ">","" ).replace( "</a","").replace(" ","");
                if( hackedUpStr.contains("."))
                {
                    m_versions.append( hackedUpStr );
                }
            }
        }
    }

    disconnect( manager, &QNetworkAccessManager::finished,
             this, &LinaroParser::replyFinished );

    manager = nullptr;
    delete manager;

    reply = nullptr ;
    delete  reply;

    setStatus( Finished );
    setStatus( Stopped );
}

void LinaroParser::setStatus(const Status &status)
{
    if (m_status != status)
    {
        m_status = status;
        emit statusChanged(m_status);
    }
}
