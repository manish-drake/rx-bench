#ifndef RXMODEL_H
#define RXMODEL_H

#include <QObject>
#include "qresult.h"

class rxmodel : public QObject
{
    Q_PROPERTY(QString pattern READ pattern WRITE setPattern NOTIFY patternChanged)
    Q_PROPERTY(QString input READ input WRITE setInput NOTIFY inputChanged)
    Q_PROPERTY(QString results READ results WRITE setResults NOTIFY resultsChanged)
    Q_PROPERTY(QList<QObject*> qresults READ qresults NOTIFY qresultsChanged)
    Q_OBJECT
    QString m_pattern, m_input, m_results;
    QList<QObject*> m_qresults;
    void writeCache(const std::string &strPattern, const std::string &strInput);
    int readCache(std::string &strPattern, std::string &strInput);
    char CACHE[255] = {};
public:
    explicit rxmodel(QObject *parent = nullptr);
    Q_INVOKABLE void run();
    Q_INVOKABLE void selectedIndex(const int &index);

    inline QString pattern() const
    {
        return m_pattern;
    }
    inline void setPattern(const QString &pattern)
    {
        m_pattern = pattern;
        emit patternChanged();
    }

    inline QString input() const
    {
        return m_input;
    }
    inline void setInput(const QString &input)
    {
        m_input = input;
        emit inputChanged();
    }


    inline QString results() const
    {
        return m_results;
    }
    inline void setResults(const QString &results)
    {
        m_results = results;
        emit resultsChanged();
    }
    inline QList<QObject*> qresults()
    {
        return m_qresults;
    }

signals:
    void patternChanged();
    void inputChanged();
    void resultsChanged();
    void qresultsChanged();
    void select(const int &start, const int &end);

public slots:
};

#endif // RXMODEL_H
