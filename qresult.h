#ifndef QRESULT_H
#define QRESULT_H

#include <QObject>

class qresult : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString result READ result WRITE setResult NOTIFY resultChanged)
    Q_PROPERTY(int pos READ pos WRITE setPos NOTIFY posChanged)
    Q_PROPERTY(int len READ len WRITE setLen NOTIFY lenChanged)

    QString m_result;
    int m_pos, m_len;
public:
    explicit qresult(QObject *parent = nullptr);
    qresult(const QString &result, const int &pos, const int &len, QObject *parent = nullptr);
    inline QString result() const
    {
        return m_result;
    }
    inline void setResult(const QString &result)
    {
        m_result = result;
        emit resultChanged();
    }
    inline int pos() const
    {
        return m_pos;
    }
    inline void setPos(const int &pos)
    {
        m_pos = pos;
        emit posChanged();
    }
    inline int len() const
    {
        return m_len;
    }
    inline void setLen(const int &len)
    {
        m_len = len;
        emit lenChanged();
    }

signals:
    void resultChanged();
    void posChanged();
    void lenChanged();

public slots:
};

#endif // QRESULT_H
