#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(operatingSystem t_os, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , os(t_os)
{
    ui->setupUi(this);

    setWindowTitle(t_os.super_block.file_system_name);

    ui->commandsInput_textEdit->installEventFilter(this);
    ui->greetingsUser_label->setText("Здравствуй, " + QString(os.user_table.user_name));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == ui->commandsInput_textEdit) {
        if (e->type() == QEvent::KeyPress) {
            QKeyEvent *key_event = static_cast<QKeyEvent *>(e);
            int key_value = key_event->key();
            if (key_value == Qt::Key_Enter || key_value == Qt::Key_Return) {
                executeCommand(ui->commandsInput_textEdit->toPlainText());
                ui->commandsInput_textEdit->clear();
                return true;
            }
        }
    }
    return obj->eventFilter(obj, e);
}

void MainWindow::executeCommand(QString command)
{
    QString current_text = ui->commandsOutput_label->text();
    if (command == "ls") {
        ui->commandsOutput_label->setText(current_text + "\nls command has been called");
    } else {
        ui->commandsOutput_label->setText(current_text + "\nДанной команды не существует");
    }
    // return ui->commandsInput_textEdit->setAlignment(Qt::AlignTop);
}
