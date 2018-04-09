#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    findTextEditApplication=new QTextEdit();
    findTextEditFlow=new QTextEdit();
    findHorBoxLayout=new QHBoxLayout();
    centralWidget()->setLayout(findHorBoxLayout);
    findHorBoxLayout->addWidget(findTextEditApplication,1);
    findHorBoxLayout->addWidget(findTextEditFlow,3);

}

MainWindow::~MainWindow()
{

    delete findHorBoxLayout;
    delete findTextEditApplication;
    delete findTextEditFlow;
    delete ui;
    //нужно закрыть процес close(), а потом уничтожить.
    while(!findProcessList.isEmpty())
    {
        (*findProcessList.begin())->close();
        delete *findProcessList.begin();
        findProcessList.pop_front();
    }

    /*if(!findProcessList.isEmpty())
    {
        for(int i=0;i<findProcessList.length();i++)
        {
            findProcessList[i]->close();
            delete findProcessList[i];
        }
    }*/
}

void MainWindow::setStartArgument(const QStringList & strArgv)
{
        for(int i=0;i<strArgv.length();i++)
        {
            findProcessList.append(new QProcess);
            QString setArg=strArgv[i];
            QStringList listArgument=setArg.split(' ');
            QStringList strList;
            findTextEditApplication->append(listArgument[0]);
            for (QList<QString>::iterator it = listArgument.begin()+1; it !=listArgument.end() ; ++it) //Перебирает все задачи в списке и выполняет
            {
                strList.append("--time");
                strList.append(*it);
            }
            connect(findProcessList[i],SIGNAL(readyReadStandardOutput()),this,SLOT(findSlotStOutput()));
            connect(findProcessList[i],SIGNAL(readyReadStandardError()),this,SLOT(findSlotStError()));
            findProcessList[i]->start(listArgument[i],strList);
        }
}

void MainWindow::findSlotStOutput()
{
    QProcess *processOut=dynamic_cast<QProcess*>(sender());
    QByteArray setByteFlow= processOut->readAllStandardOutput ();
    findTextEditFlow->append(setByteFlow);
}

void MainWindow::findSlotStError()
{   
    QProcess *processOut=dynamic_cast<QProcess*>(sender());
    QByteArray setByteFlow= processOut->readAllStandardError();   
    findTextEditFlow->append(setByteFlow);
}
