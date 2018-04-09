#include "mainwindow.h"
#include <QApplication>
//#include <QDebug>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QCommandLineParser parser;

    QApplication a(argc, argv);

    QCommandLineOption commandOption("process1", "Start program", "Argument");
    QCommandLineOption commandOption1("process2", "Start program", "Argument");
    parser.addOption(commandOption);
    parser.addOption(commandOption1);
    parser.process(a);
    QStringList setStrListCommand;   
    setStrListCommand.append(parser.value(commandOption));
    setStrListCommand.append(parser.value(commandOption1));


    MainWindow w;
    w.setWindowTitle("AutAgregator");
    w.setStartArgument(setStrListCommand);
    w.show();

    return a.exec();
}

