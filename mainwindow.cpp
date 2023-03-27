#include "mainwindow.h"
#include "ui_mainwindow.h"


void login(char t_user_name[15], char t_user_password[32])
{

}

void logout(char t_user_name[15])
{

}

//void login(char t_user_name[15], char t_user_password[32]);
//void logout(char t_user_name[15]);
void createUser(char t_user_name[15], char t_user_password[32], char t_user_role)
{

}

void createFile(char* t_path, char* t_file_name)
{

}

void copyFile(char* t_source, char* t_destination)
{

}


void moveFile(char* t_source, char* t_destination)
{

}

void renameFile(char* t_old_file_name, char* t_new_file_name)
{

}

void changeAccessRights(char* t_file_name, std::bitset<6> t_access_rights)
{
    qDebug() << "File name: " << t_file_name;
    char* bits = new char;
    for (size_t i = 0; i < t_access_rights.size(); ++i) {
        bits += t_access_rights[i];
    }
    std::string string_bits = t_access_rights.to_string<char, std::string::traits_type, std::string::allocator_type>();
    qDebug() << "Bits: " << string_bits.c_str();
}

void changeProcessPriority(int t_process_id, int t_priority)
{

}

void writeToTheEnd(char* t_file_name, char* t_data)
{

}

void createDirectory(char* t_directory_name)
{

}

void createGroup(char* t_group_name)
{

}

void createUser(char* t_user_name)
{

}

void deleteFile(char* t_file_name)
{

}

void deleteDirectory(char* t_directory_name)
{

}

void killProcess(int t_process_id)
{

}

void getProcsInfo()
{

}

void createFile(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* path = (char*)t_commands_list[1].toStdString().c_str();
        char* file_name = (char*)t_commands_list[2].toStdString().c_str();
        createFile(path, file_name);
    }
}

void copyFile(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* source = (char*)t_commands_list[1].toStdString().c_str();
        char* destination = (char*)t_commands_list[2].toStdString().c_str();
        copyFile(source, destination);
    }
}

void moveFile(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* source = (char*)t_commands_list[1].toStdString().c_str();
        char* destination = (char*)t_commands_list[2].toStdString().c_str();
        moveFile(source, destination);
    }
}

void renameFile(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* old_file_name = (char*)t_commands_list[1].toStdString().c_str();
        char* new_file_name = (char*)t_commands_list[2].toStdString().c_str();
        renameFile(old_file_name, new_file_name);
    }
}

// (d)(user)rwx(group)rwx(other)rwx
void changeAccessRights(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* file_name = (char*)t_commands_list[1].toStdString().c_str();
        char* destination = (char*)t_commands_list[2].toStdString().c_str();
        std::bitset<6> access_rights(destination);
        changeAccessRights(file_name, access_rights);
    }
}

void changeProcessPriority(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        qDebug() << "Неверное количество параметров";
    } else {
        int process_id = t_commands_list[1].toInt();
        int priority = t_commands_list[2].toInt();
        changeProcessPriority(process_id, priority);
    }
}

void writeToTheEnd(QStringList t_commands_list)
{
    if (t_commands_list.length() != 3) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* file_name = (char*)t_commands_list[1].toStdString().c_str();
        char* data = (char*)t_commands_list[2].toStdString().c_str();
        copyFile(file_name, data);
    }
}

void createDirectory(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* directory_name = (char*)t_commands_list[1].toStdString().c_str();
        createDirectory(directory_name);
    }
}

void createUser(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* user_name = (char*)t_commands_list[1].toStdString().c_str();
        createUser(user_name);
    }
}

void createGroup(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* group_name = (char*)t_commands_list[1].toStdString().c_str();
        createGroup(group_name);
    }
}

void deleteFile(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* file_name = (char*)t_commands_list[1].toStdString().c_str();
        deleteFile(file_name);
    }
}

void deleteDirectory(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        qDebug() << "Неверное количество параметров";
    } else {
        char* directory_name = (char*)t_commands_list[1].toStdString().c_str();
        deleteDirectory(directory_name);
    }
}

void killProcess(QStringList t_commands_list)
{
    if (t_commands_list.length() != 2) {
        qDebug() << "Неверное количество параметров";
    } else {
        int process_id = t_commands_list[1].toInt();
        killProcess(process_id);
    }
}

void getProcsInfo(QStringList t_commands_list)
{
    getProcsInfo();
}


MainWindow::MainWindow(operatingSystem t_os, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_os(t_os)
{
    ui->setupUi(this);

    setWindowTitle(t_os.super_block.file_system_name);

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
    QString current_output_text = ui->commandsOutput_label->text();
    QStringList command_text = command.split(" ");
    command = command_text[0];

    for (auto &function_caller:m_function_callers) {
        if (function_caller.allias == command) {
            return function_caller.action(command_text);
        }
    }

    return ui->commandsOutput_label->setText(current_output_text + "Неизвестная команда\n");
}

void MainWindow::setFunctionCallers()
{
    m_function_callers.append(functionCaller((char*)"touch", [&](QStringList commands_list){ createFile(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"move", [&](QStringList commands_list){ moveFile(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"mkdir", [&](QStringList commands_list){ createDirectory(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"add_user", [&](QStringList commands_list){ createUser(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"add_group", [&](QStringList commands_list){ createGroup(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"rename", [&](QStringList commands_list){ renameFile(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"rm", [&](QStringList commands_list){ deleteFile(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"rmdir", [&](QStringList commands_list){ deleteDirectory(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"append", [&](QStringList commands_list){ writeToTheEnd(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"chmod", [&](QStringList commands_list){ changeAccessRights(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"ps", [&](QStringList commands_list){ getProcsInfo(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"chpr", [&](QStringList commands_list){ changeProcessPriority(commands_list) ; }));
    m_function_callers.append(functionCaller((char*)"kill", [&](QStringList commands_list){ killProcess(commands_list) ; }));
}
