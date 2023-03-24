#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qDebug>
#include <QKeyEvent>

#include "structures.h"


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

    operatingSystem os;
};
#endif // MAINWINDOW_H
