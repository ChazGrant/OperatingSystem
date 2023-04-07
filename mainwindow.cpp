#include "mainwindow.h"
#include "ui_mainwindow.h"


bool login(char t_user_name[15], char t_user_password[32])
{

}

void logout(char t_user_name[15])
{

}

//void login(char t_user_name[15], char t_user_password[32]);
//void logout(char t_user_name[15]);

void MainWindow::addToTheOutput(QString t_string)
{
    QString current_output_text = ui->commandsOutput_label->text();
    return ui->commandsOutput_label->setText(current_output_text + t_string + "\n");
}

void MainWindow::saveOSState()
{
    QString file_system_name;
    file_system_name += m_os.super_block.file_system_name;
    file_system_name += ".bin";

    std::ofstream output_file(file_system_name.toStdString());
    output_file.write((char*)&m_os.super_block, sizeof(m_os.super_block));
    output_file.write((char*)&m_os.root_directory, sizeof(m_os.root_directory));
    output_file.write((char*)&m_os.user_table, sizeof(m_os.user_table));
    output_file.close();
}

void MainWindow::createFile(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* path = (char*)t_commands_list[1].toStdString().c_str();
        char* file_name = (char*)t_commands_list[2].toStdString().c_str();
    }
}

void MainWindow::copyFile(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* source = (char*)t_commands_list[1].toStdString().c_str();
        char* destination = (char*)t_commands_list[2].toStdString().c_str();
    }
}

void MainWindow::moveFile(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* source = (char*)t_commands_list[1].toStdString().c_str();
        char* destination = (char*)t_commands_list[2].toStdString().c_str();
    }
}

void MainWindow::renameFile(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* old_file_name = (char*)t_commands_list[1].toStdString().c_str();
        char* new_file_name = (char*)t_commands_list[2].toStdString().c_str();
    }
}

// (d)(user)rwx(group)rwx(other)rwx
void MainWindow::changeAccessRights(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* file_name = (char*)t_commands_list[1].toStdString().c_str();
        char* destination = (char*)t_commands_list[2].toStdString().c_str();
        std::bitset<9> access_rights(destination);

        m_os.root_directory.access_rights = access_rights;
    }
}

void MainWindow::changeProcessPriority(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        addToTheOutput("Неверное количество параметров");
    } else {
        int process_id = t_commands_list[1].toInt();
        int priority = t_commands_list[2].toInt();
    }
}

void MainWindow::writeToTheEnd(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* file_name = (char*)t_commands_list[1].toStdString().c_str();
        char* data = (char*)t_commands_list[2].toStdString().c_str();
    }
}

void MainWindow::createDirectory(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* directory_name = (char*)t_commands_list[1].toStdString().c_str();
    }
}

void MainWindow::createUser(QStringList t_commands_list)
{
    if (t_commands_list.length() != 4) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* user_name = (char*)t_commands_list[1].toStdString().c_str();
        char* user_password = (char*)t_commands_list[2].toStdString().c_str();
        char user_role = t_commands_list[3].at(0).unicode();
    }
}

void MainWindow::createGroup(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* group_name = (char*)t_commands_list[1].toStdString().c_str();
    }
}

void MainWindow::deleteFile(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* file_name = (char*)t_commands_list[1].toStdString().c_str();
    }
}

void MainWindow::deleteDirectory(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* directory_name = (char*)t_commands_list[1].toStdString().c_str();
    }
}

void MainWindow::killProcess(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        addToTheOutput("Неверное количество параметров");
    } else {
        int process_id = t_commands_list[1].toInt();
    }
}

void MainWindow::changeDirectory(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        addToTheOutput("Неверное количество параметров");
    } else {
        char* directory_name = (char*)t_commands_list[1].toStdString().c_str();
    }
}

void MainWindow::getProcsInfo(QStringList t_commands_list)
{
    if (t_commands_list.length() != 1) {
        addToTheOutput("Неверное количество параметров");
    } else {

    }
}

void MainWindow::getUsersInfo(QStringList t_commands_list)
{
    if (t_commands_list.length() != 1) {
        addToTheOutput("Неверное количество параметров");
    } else {

    }
}

MainWindow::MainWindow(operatingSystem t_os, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_os(t_os)
{
    ui->setupUi(this);

    setWindowTitle(m_os.super_block.file_system_name);

    setFunctionCallers();

    ui->commandsInput_textEdit->installEventFilter(this);
    ui->greetingsUser_label->setText("Здравствуй, " + QString(m_os.user_table.user_name));
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
    QStringList command_text = command.split(" ");
    command = command_text[0];

    for (auto &function_caller:m_function_callers) {
        if (function_caller.allias == command) {
            function_caller.action(command_text);
            return saveOSState();
        }
    }

    return addToTheOutput("Неизвестная команда");
}

void MainWindow::setFunctionCallers()
{
    m_function_callers.append(functionCaller((char*)"touch", [&](QStringList commands_list){ createFile(commands_list); }));
    m_function_callers.append(functionCaller((char*)"move", [&](QStringList commands_list){ moveFile(commands_list); }));
    m_function_callers.append(functionCaller((char*)"mkdir", [&](QStringList commands_list){ createDirectory(commands_list); }));
    m_function_callers.append(functionCaller((char*)"add_user", [&](QStringList commands_list){ createUser(commands_list); }));
    m_function_callers.append(functionCaller((char*)"add_group", [&](QStringList commands_list){ createGroup(commands_list); }));
    m_function_callers.append(functionCaller((char*)"rename", [&](QStringList commands_list){ renameFile(commands_list); }));
    m_function_callers.append(functionCaller((char*)"rm", [&](QStringList commands_list){ deleteFile(commands_list); }));
    m_function_callers.append(functionCaller((char*)"rmdir", [&](QStringList commands_list){ deleteDirectory(commands_list); }));
    m_function_callers.append(functionCaller((char*)"append", [&](QStringList commands_list){ writeToTheEnd(commands_list); }));
    m_function_callers.append(functionCaller((char*)"chmod", [&](QStringList commands_list){ changeAccessRights(commands_list); }));
    m_function_callers.append(functionCaller((char*)"ps", [&](QStringList commands_list){ getProcsInfo(commands_list); }));
    m_function_callers.append(functionCaller((char*)"chpr", [&](QStringList commands_list){ changeProcessPriority(commands_list); }));
    m_function_callers.append(functionCaller((char*)"kill", [&](QStringList commands_list){ killProcess(commands_list); }));
    m_function_callers.append(functionCaller((char*)"cd", [&](QStringList commands_list){ changeDirectory(commands_list); }));
    m_function_callers.append(functionCaller((char*)"ul", [&](QStringList commands_list){ getUsersInfo(commands_list); }));
}
