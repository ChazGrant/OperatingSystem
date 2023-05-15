#include "authform.h"
#include "ui_authform.h"


AuthForm::AuthForm(operatingSystem t_os, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm),
    os(t_os)
{
    ui->setupUi(this);

    connect(ui->login_pushButton, &QPushButton::clicked, this, &AuthForm::login);
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::login()
{
    ui->userName_textEdit->setText("ChazGrant");
    ui->userPassword_textEdit->setText("password");
    QString username = ui->userName_textEdit->toPlainText();
    QString password = ui->userPassword_textEdit->toPlainText();
    bool login_failed = true;
    for (int i = 0; i < os.users.size(); ++i) {
        if (os.users[i].user_name == username && os.users[i].user_password == password) {
            login_failed = false;
        }
    }
        if (login_failed) {
            qDebug() << "NOT MATCH";
            return;
        }
    MainWindow *mw = new MainWindow(this->os);
    mw->show();
    this->close();
}
