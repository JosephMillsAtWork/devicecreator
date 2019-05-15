#include "wgetrunner.h"

WgetRunner::WgetRunner( QObject *parent ) :
    QProcess( parent )
  , m_bash( "/bin/bash" )
{

}
