#ifndef BBPARSER_H
#define BBPARSER_H

#include <QObject>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include <QDebug>
#include <QRegularExpression>


class BBParser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString directory READ directory WRITE setDirectory NOTIFY directoryChanged)
public:
    explicit BBParser(QObject *parent = nullptr);

    void scanDirectory(  )
    {
        QDirIterator dIt("/home/fluke/tmp/poky", QDirIterator::Subdirectories );
        while (dIt.hasNext() )
        {
            qDebug() << dIt.next();
        }

    }

    QString directory() const
    {
        return m_directory;
    }
    void setDirectory( const QString &directory )
    {
        if ( m_directory != directory )
        {
            m_directory = directory;
            emit directoryChanged(m_directory);
        }
    }

signals:
    void directoryChanged(QString directory);

private:

    QString m_directory;
    QStringList m_allowedSuffixs;

    QHash<int, QString> m_bbFiles;
    QHash<int, QString> m_bbAppendFiles;
    QHash<int, QString> m_bbIncludeFiles;
    QHash<int, QString> m_bbClassFiles;

};

#endif // BBPARSER_H
