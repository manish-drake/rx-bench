#include "rxmodel.h"
#include <iostream>
#include <regex>
#include <string.h>
#include <fstream>


void rxmodel::run()
{
    try{
        std::regex rx(pattern().toLatin1());
        std::smatch matches;
        std::string inputString = std::string(input().toLatin1());

        std::string mtch = "";
        this->m_qresults.clear();
        int position = 0;
        while(std::regex_search(inputString, matches, rx))
        {
            for(auto &match:matches)
            {
                mtch.append(match);
                mtch.append("\n");
                position += matches.position();
                m_qresults.append(
                            new qresult(
                                QString::fromStdString(match),
                                position,
                                matches.length(),
                                this));
            }
            inputString = matches.suffix().str();
            position += matches.length();
        }

        std::cout << mtch << std::endl;
        setResults(QString::fromStdString(mtch));
        emit qresultsChanged();
        this->writeCache(pattern().toStdString(), input().toStdString());
    }
    catch(std::regex_error ex)
    {
        std::cout << ex.what() << std::endl;
    }

}

void rxmodel::selectedIndex(const int &index)
{
    auto result = static_cast<qresult*>(m_qresults[index]);
    this->select(result->pos(), result->pos()+result->len());
}

void rxmodel::writeCache(const std::string &strPattern, const std::string &strInput)
{
    const char *pattern = strPattern.c_str();
    const char *input = strInput.c_str();
    int szPattern = strlen(pattern);
    int szInput = strlen(input);


    std::ofstream stream(CACHE, std::ios::binary);

    stream.write(reinterpret_cast<const char*>(&szPattern), sizeof(int));
    stream.write(pattern, szPattern);
    stream.write(reinterpret_cast<const char*>(&szInput), sizeof(int));
    stream.write(input, szInput);

    stream.close();

}

int rxmodel::readCache(std::string &strPattern, std::string &strInput)
{
    try{
        std::ifstream istream(CACHE, std::ios::binary);
        int szPattern, szInput;
        istream.read(reinterpret_cast<char *>(&szPattern), sizeof(int));
        char pattern[szPattern + 1] = {};
        istream.read(pattern, szPattern);
        istream.read(reinterpret_cast<char *>(&szInput), sizeof(int));
        char input[szInput + 1] = {};
        istream.read(input, szInput);
        istream.close();

        strPattern = std::string(pattern);
        strInput = std::string(input);
        return 0;
    }
    catch(std::exception)
    {
        return 1;
    }
}

rxmodel::rxmodel(QObject *parent) : QObject(parent)
{
    sprintf(CACHE, "%s/rx-bench.cache", getenv("HOME"));
    const int ERR = 1;
    std::string pattern, input;
    if(!(ERR && this->readCache(pattern, input)))
    {
        if(pattern.size() > 0)
            setPattern(QString::fromStdString(pattern));
        if(input.size() > 0)
            setInput(QString::fromStdString(input));
    }
}
