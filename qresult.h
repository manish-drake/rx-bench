#ifndef QRESULT_H
#define QRESULT_H

#include <QObject>

class qresult : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString result READ result WRITE setResult NOTIFY resultChanged)
    QString m_result;
public:
    explicit qresult(QObject *parent = nullptr);
    qresult(const QString &result, QObject *parent = nullptr);
    inline QString result() const
    {
        return m_result;
    }
    inline void setResult(const QString &result)
    {
        m_result = result;
        emit resultChanged();
    }

signals:
    void resultChanged();

public slots:
};

#endif // QRESULT_H
