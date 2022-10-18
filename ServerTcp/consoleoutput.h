#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H
#include <QVariant>
#include <iostream>
#include <windows.h>
#include <QDateTime>

using namespace std;

class ConsoleOutput
{
public:
    ConsoleOutput();
    void outMsg(QVariantList msg);
    void outError(QVariantList error);
    void outInfo(QVariantList info);
    void outStatus(QVariantList status, QString color);
    void outTitle(QString appVersion);

private:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};

#endif // CONSOLEOUTPUT_H
