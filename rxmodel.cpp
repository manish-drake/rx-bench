#include "rxmodel.h"
#include <iostream>
#include <regex>
#include <string.h>

void rxmodel::run()
{
    try{
        std::regex rx(pattern().toLatin1());
        std::smatch matches;
        std::string inputString = std::string(input().toLatin1());

        std::string mtch = "";
        this->m_qresults.clear();
        while(std::regex_search(inputString, matches, rx))
        {
            for(auto &match:matches)
            {
                mtch.append(match);
                mtch.append("\n");
                m_qresults.append(new qresult(QString::fromStdString(match), this));
            }
            inputString = matches.suffix().str();
        }


        setResults(QString::fromStdString(mtch));
        emit qresultsChanged();
    }
    catch(std::regex_error ex)
    {
        std::cout << ex.what() << std::endl;
    }

}

rxmodel::rxmodel(QObject *parent) : QObject(parent)
{

}
