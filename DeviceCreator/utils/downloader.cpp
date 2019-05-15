#include "downloader.h"

Downloader::Downloader(QObject *parent) :
    QObject(parent)
{
}

Downloader::Provider Downloader::provider() const
{
    return m_provider;
}

void Downloader::setProvider(const Downloader::Provider &provider)
{
    if ( m_provider != provider )
    {
        m_provider = provider;
        emit providerChanged();
    }
}
