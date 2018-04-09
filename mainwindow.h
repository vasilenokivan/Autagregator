#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>
#include <QApplication>
#include <QString>
#include <QCommandLineParser>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setStartArgument(const QStringList & strArgv);

private:
    Ui::MainWindow *ui;
    QHBoxLayout* findHorBoxLayout;
    QTextEdit* findTextEditApplication;
    QTextEdit* findTextEditFlow;
    QList <QProcess*> findProcessList;
    //void startProcess(QString nameProcess);
    int count=0;
public slots:
    void findSlotStOutput();
    void findSlotStError();



};

#endif // MAINWINDOW_H
