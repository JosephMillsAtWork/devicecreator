#ifndef HOSTINFORMATION_H
#define HOSTINFORMATION_H

#include <QObject>
#include <QSysInfo>
#include <QProcess>
#include <QFile>
#include <QStorageInfo>
#include <QDebug>

class HostInformation : public QObject
{
    Q_OBJECT
public:
    explicit HostInformation( QObject *parent = nullptr ) :
        QObject( parent )
    {
    }

    QStringList getReqHostTools() const
    {
        return m_reqHostTools;
    }

    void setReqHostTools() {
        if( !m_reqHostTools.isEmpty() )
        {
            m_reqHostTools.clear();
        }

        m_reqHostTools = QStringList()
                << "["
                << "ar"
                << "as"
                << "awk"
                << "basename"
                << "bash"
                << "bzip2"
                << "bzr"
                << "cat"
                << "chgrp"
                << "chmod"
                << "chown"
                << "chrpath"
                << "cmp"
                << "comm"
                << "cp"
                << "cpio"
                << "cpp"
                << "cut"
                << "date"
                << "dd"
                << "diff"
                << "diffstat"
                << "dirname"
                << "du"
                << "echo"
                << "egrep"
                << "env"
                << "expand"
                << "expr"
                << "false"
                << "fgrep"
                << "file"
                << "find"
                << "flock"
                << "g++"
                << "gawk"
                << "gcc"
                << "gcc-ar"
                << "getconf"
                << "getopt"
                << "git"
                << "gpg"
                << "grep"
                << "gunzip"
                << "gzip"
                << "head"
                << "hostname"
                << "id"
                << "install"
                << "join"
                << "ld"
                << "ld.bfd"
                << "ldd"
                << "ld.gold"
                << "ln"
                << "ls"
                << "make"
                << "makeinfo"
                << "md5sum"
                << "mkdir"
                << "mknod"
                << "mktemp"
                << "mv"
                << "nc"
                << "nl"
                << "nm"
                << "objcopy"
                << "objdump"
                << "od"
                << "patch"
                << "perl"
                << "pod2man"
                << "pr"
                << "printf"
                << "pwd"
                << "python"
                << "python2"
                << "python2.7"
                << "python3"
                << "ranlib"
                << "readelf"
                << "readlink"
                << "realpath"
                << "rm"
                << "rmdir"
                << "rpcgen"
                << "scp"
                << "sed"
                << "seq"
                << "sftp"
                << "sh"
                << "sha256sum"
                << "size"
                << "sleep"
                << "socat"
                << "sort"
                << "split"
                << "ssh"
                << "stat"
                << "strings"
                << "strip"
                << "sudo"
                << "tail"
                << "tar"
                << "tee"
                << "test"
                << "touch"
                << "tr"
                << "true"
                << "uname"
                << "uniq"
                << "wc"
                << "wget"
                << "which"
                << "xargs"
                << "yes"
                << "zcat" ;
    }

    void checkReqHostTools(){

        setReqHostTools();

        QProcess whichProcess;
        for( QString tool : m_reqHostTools )
        {
            whichProcess.setProgram( "/bin/bash" );
            whichProcess.setArguments( QStringList() << "-c" << QString( "which %1" ).arg( tool ) );
            whichProcess.start();
            whichProcess.waitForFinished();
            QString whichProcessPath = whichProcess.readAllStandardOutput().simplified().replace( " ", "" );
            if( !whichProcessPath.isEmpty() )
            {
                qDebug() << tool << whichProcessPath;
            }
            else
            {
                qDebug() << "REQUIRED TOOL NOT FOUND QUIT " << tool;
            }
        }

        qDebug() << "HOST ARCH " << QSysInfo::buildCpuArchitecture();
        qDebug() << "HOST Kernel Verion " << QSysInfo::kernelVersion();
        qDebug() << "HOST Name  " << QSysInfo::machineHostName();
        qDebug() << "Host CPU count" << getCpuNumbers();
        qDebug() << "Host Ram" << getRamAmmount() << "MB";

        QStorageInfo storage = QStorageInfo::root();
        qDebug() << "DiskSpace Total" << storage.bytesTotal() /1000/1000 << "MB" ;
        qDebug() << "DiskSpace Available" << storage.bytesAvailable() /1000/1000 << "MB" ;

    }



    int getRamAmmount()const
    {
        int ret = 0;
        QFile f( "/proc/meminfo" );
        if( f.open( QIODevice::ReadOnly | QIODevice::Text ) )
        {
            QTextStream s( &f );
            QString line = s.readLine();
            while ( !line.isNull() )
            {
                // Maybe want to also get the swap from here
                if( line.startsWith( "MemTotal" ) )
                {
                    QStringList li =line.replace("kB","")
                                 .replace(" ","").split(":");
                    if ( li.count() == 2 )
                    {
                        ret = li[1].toInt() / 1000 ;
                    }
                    break;
                }
                line = s.readLine();
            }
            f.close();
        }
        return ret;
    }

    int getCpuNumbers() const {
        int ret = 0;
        QFile cpuCountFile( "/proc/cpuinfo" );
        if( cpuCountFile.open( QIODevice::ReadOnly | QIODevice::Text ) )
        {
            QTextStream stream( &cpuCountFile );
            QString line = stream.readLine();
            while ( !line.isNull() )
            {
                line = stream.readLine();
                if( line.startsWith( "processor" ) )
                {
                    ret++;
                }
            }
            cpuCountFile.close();
        }
        else
        {
            qDebug() << "Could not open the file :( ";
        }
        return ret;
    }

private:
    QStringList m_reqHostTools;
};

#endif // HOSTINFORMATION_H
