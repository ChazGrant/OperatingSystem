#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include <qDebug>

#include "structures.h"
#include "mainwindow.h"


namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(operatingSystem t_os, QWidget *parent = nullptr);
    ~AuthForm();

    void login();

private:
    Ui::AuthForm *ui;
    operatingSystem os;
};

#endif // AUTHFORM_H
