#include "qresult.h"

qresult::qresult(QObject *parent) : QObject(parent)
{

}

qresult::qresult(const QString &result, const int &pos, const int &len, QObject *parent):
    m_result{result},
    m_pos{pos},
    m_len{len},
    QObject(parent)
{

}
