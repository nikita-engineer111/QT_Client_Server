#include "consoleoutput.h"

/*
// 0 = Черный 8 = Серый
// 1 = Синий 9 = Светло-голубой
// 2 = Зеленый a = светло-зеленый
// 3 = Аква b = светло-аква
// 4 = Красный c = светло-красный
// 5 = Фиолетовый d = светло-фиолетовый
// 6 = Желтый e = СветлыйЖелтый
// 7 = белый f = ярко-белый
*/

ConsoleOutput::ConsoleOutput()
{
    system("color 07");
}
void ConsoleOutput::outMsg(QVariantList msg)
{
    SetConsoleTextAttribute(hConsole, 2);
    for(int i=0;i<msg.size();i++)
    {
        cout << msg[i].toString().toStdString() << " ";;
    }
    cout << endl;
}
void ConsoleOutput::outError(QVariantList error)
{
    SetConsoleTextAttribute(hConsole, 4);
    for(int i=0;i<error.size();i++)
    {
        cout << error[i].toString().toStdString() << " ";
    }
    cout << endl;
}
void ConsoleOutput::outInfo(QVariantList info)
{
    SetConsoleTextAttribute(hConsole, 11);
    for(int i=0;i<info.size();i++)
    {
        cout << info[i].toString().toStdString() << " ";;
    }
    cout << endl;
}
void ConsoleOutput::outStatus(QVariantList status, QString color)
{
    SetConsoleTextAttribute(hConsole, 5);
    cout << "Status:    ";
    SetConsoleTextAttribute(hConsole, color=="red" ? 4 : 2);
    for(int i=0;i<status.size();i++)
    {
        cout << status[i].toString().toStdString();
    }
    cout << endl<< endl<< endl<< endl;
}

void ConsoleOutput::outTitle(QString appVersion)
{
    SetConsoleTextAttribute(hConsole, 11);//
    cout << "WELCOME TO TCP_SERVER" << endl;

    SetConsoleTextAttribute(hConsole, 5);
    cout << "Version:   ";
    SetConsoleTextAttribute(hConsole, 2);
    cout << appVersion.toStdString() << endl;

    SetConsoleTextAttribute(hConsole, 5);
    cout << "Build:     ";
    SetConsoleTextAttribute(hConsole, 2);
    cout << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()<< endl;
}
