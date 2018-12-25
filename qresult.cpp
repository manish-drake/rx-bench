#include "qresult.h"

qresult::qresult(QObject *parent) : QObject(parent)
{

}

qresult::qresult(const QString &result, QObject *parent): m_result{result}, QObject(parent)
{

}
