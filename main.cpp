#include "mainwindow.h"
#include <QApplication>
//#include <QDebug>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int findArgc=argc;
    QStringList findStrListArgv;
    for(int i=1;i<findArgc;i++){
        findStrListArgv.append(argv[i]);}
    MainWindow w;
    w.setWindowTitle("AutAgregator");
    w.setStartArgument(findStrListArgv);
    w.show();

    return a.exec();
}

