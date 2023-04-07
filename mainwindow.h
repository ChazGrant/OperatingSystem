#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qDebug>
#include <QKeyEvent>

#include "structures.h"
#include <fstream>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(operatingSystem t_os, QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *obj, QEvent *e) override;
    void executeCommand(QString command);

private:
    Ui::MainWindow *ui;

    void setFunctionCallers();

    void addToTheOutput(QString t_string);
    void saveOSState();

    void createFile(QStringList t_commands_list);
    void copyFile(QStringList t_commands_list);
    void moveFile(QStringList t_commands_list);
    void renameFile(QStringList t_commands_list);
    void changeAccessRights(QStringList t_commands_list);
    void changeProcessPriority(QStringList t_commands_list);
    void writeToTheEnd(QStringList t_commands_list);
    void createDirectory(QStringList t_commands_list);
    void createUser(QStringList t_commands_list);
    void createGroup(QStringList t_commands_list);
    void deleteFile(QStringList t_commands_list);
    void deleteDirectory(QStringList t_commands_list);
    void killProcess(QStringList t_commands_list);
    void changeDirectory(QStringList t_commands_list);
    void getProcsInfo(QStringList t_commands_list);
    void getUsersInfo(QStringList t_commands_list);

    operatingSystem m_os;
    QList<functionCaller> m_function_callers;
    QStringList m_function_alliases;
};
#endif // MAINWINDOW_H
