#ifndef LINAROPARSER_H
#define LINAROPARSER_H
#include <QObject>
#include <QNetworkReply>
#include <QUrl>

static QString uri = "https://releases.linaro.org/components/toolchain/binaries/";
class LinaroParser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)
    Q_ENUMS(Status)
public:
    explicit LinaroParser(QObject *parent = nullptr);
    ~LinaroParser();
    void parse();
    QStringList getVersions()const
    {
        return m_versions;
    }
    QStringList getMultiarchs() const;
    QStringList getHostArchs() const;
    enum Status{
        Running = 0,
        Finished =1,
        Stopped = 2,
    };
    Status status() const;

signals:
    void parsed();
    void statusChanged(Status status);

public slots:
    void replyFinished( QNetworkReply *reply );
    void setStatus( const Status &status );

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QStringList m_versions;
    QStringList m_multiarch;
    QStringList m_hostarchs;
    Status m_status;
};

#endif // LINAROPARSER_H

