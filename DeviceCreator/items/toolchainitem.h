#ifndef TOOLCHAINITEM_H
#define TOOLCHAINITEM_H
#include <QObject>
#include <QSysInfo>
#include <QStandardPaths>
#include "macros/qqmlconstproperty.h"

#include "parsers/linaroparser.h"

// need
// * the toolchain
// * the sysroot (NN mingw)
// * the runtime (NN mingw)


class ToolchainItem : public LinaroParser
{
    Q_OBJECT
    // DEFULT arm-linux-gnueabihf
    QML_CONSTANT_CSTREF_PROPERTY( QString, multiArch )
    // DEFAULT = x86_64
    QML_CONSTANT_CSTREF_PROPERTY( QString, hostArch )
    // 4 , 5 , 6 . 7 , 8
    QML_CONSTANT_CSTREF_PROPERTY( int, version )
    QML_CONSTANT_CSTREF_PROPERTY(QString, cacheDir )
    
    // wget -O gccVERSION   https://releases.linaro.org/components/toolchain/binaries/latest-7/arm-linux-gnueabihf/gcc-linaro-*-x86_64_arm-linux-gnueabihf.tar.xz
public:
    explicit ToolchainItem( LinaroParser *parent = nullptr ) :
        LinaroParser( parent )
      , m_multiArch( "arm-linux-gnueabihf" )
      , m_hostArch( QSysInfo::buildCpuArchitecture() )
      , m_version( 7 )
      , m_cacheDir( QStandardPaths::writableLocation( QStandardPaths::CacheLocation ).append("/toolchains") )
      , m_linaroUrl( QString( "https://releases.linaro.org/components/toolchain/binaries/%1/%2" ).arg( m_version ).arg(m_multiArch) )
      , m_armUrl( "https://developer.arm.com/-/media/Files/downloads/gnu-a" )
    {
        
    }
    
    enum Provider {
        LINARO = 0, 
        ARMPROJECT = 1,
    };
    
    enum Type {
        Toolchain =0, 
        SysRoot = 1,
        RunTime = 2,
    };
    
    ~ToolchainItem() {}
    
    
    QString getBaseType( const Provider &provider = LINARO, const Type &type = Toolchain ) const
    {
        QString ret;
        switch ( type )
        {
        case Toolchain: 
            //                                                              VERSION     multiarch                    VERSION       ARCH   multiarch
            // https://releases.linaro.org/components/toolchain/binaries/7.4-2019.02/arm-linux-gnueabihf/gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf.tar.xz
            ret = provider == LINARO ? QString( "%1/gcc-linaro-%3-%4_%2.tar.xz" )
                                       .arg( m_linaroUrl )
                                       .arg( m_multiArch )
                                       .arg( m_version )
                                       .arg( m_hostArch )
                                     : QString("");
            break;
        case SysRoot: 
            // https://releases.linaro.org/components/toolchain/binaries/7.4-2019.02/arm-linux-gnueabihf/sysroot-glibc-linaro-2.25-2019.02-arm-linux-gnueabihf.tar.xz
            ret = provider == LINARO ? "" : "";
            break;
        case RunTime:
            // https://releases.linaro.org/components/toolchain/binaries/7.4-2019.02/arm-linux-gnueabihf/runtime-gcc-linaro-7.4.1-2019.02-arm-linux-gnueabihf.tar.xz
            ret = provider == LINARO ?
                        QString( "%1/runtime-gcc-linaro-%3-%4_%2.tar.xz" )
                                                               .arg( m_linaroUrl )
                                                               .arg( m_multiArch )
                                                               .arg( m_version )
                                                               .arg( m_hostArch )
                      : "";
            break;
        }
        return ret;
    }
    QString constructUrl( const Type &type = Toolchain ) const 
    {
        QString ret = QString();
        QString baseUrl = m_version < 8 ? m_linaroUrl : m_armUrl ;
        if( m_version < 8 )
        {
            ret = getBaseType( );
        }
        else 
        {
            ret = getBaseType( ARMPROJECT, type );
        }
        return ret;
    }


private:
    QString m_linaroUrl;
    QString m_armUrl;

};

#endif // TOOLCHAINITEM_H
