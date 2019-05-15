#include "bbparser.h"

BBParser::BBParser(QObject *parent) :
    QObject(parent)
{
    m_allowedSuffixs = QStringList()  << "bb" << "bbappend" << "inc" << "bbclass";
}
