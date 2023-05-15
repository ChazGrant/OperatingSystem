#include "systemselector.h"
#include "ui_systemselector.h"
#include "authform.h"


SystemSelector::SystemSelector(QWidget *parent) :
    QWidget(parent)
    , ui(new Ui::SystemSelector)
{
    ui->setupUi(this);

    connect(ui->chooseFileSystem_pushButton, &QPushButton::clicked, this, &SystemSelector::chooseFileSystem);
    connect(ui->createFileSystem_pushButton, &QPushButton::clicked, this, &SystemSelector::createFileSystem);
}

SystemSelector::~SystemSelector()
{
    delete ui;
}

void SystemSelector::readFromFile(std::string t_file_name, operatingSystem &t_os)
{
    superBlock sb;
    rootDirectory rd;
    std::vector<usersTable> users;

    std::ifstream input_file(t_file_name);

    input_file.read((char*)&sb, sizeof(sb));
    input_file.seekg(sb.root_dir_offset);
    input_file.read((char*)&rd, sizeof(rd));
    input_file.seekg(sb.user_table_offset);
    input_file.read((char*)&users, sizeof(users));

    t_os.super_block = sb;
    t_os.root_directory = rd;
    t_os.users = users;

//    std::cout << "Super Block: " << std::endl;
//    std::cout << sb.file_system_name << std::endl;
//    std::cout << sb.cluster_size << std::endl;
//    std::cout << sb.cluster_amount << std::endl;
//    std::cout << sb.root_dir_size << std::endl;
//    std::cout << sb.root_dir_offset << std::endl;
//    std::cout << sb.user_table_offset << std::endl;
//    std::cout << sb.data_area_offset << std::endl;
//    std::cout << sb.hard_disk_size << std::endl << std::endl;

//    std::cout << "Root Directory: " << std::endl;
//    std::cout << rd.user_id << std::endl;
//    std::cout << rd.file_size << std::endl;
//    std::cout << rd.access_rights << std::endl;
//    std::cout << rd.file_name_size << std::endl;
//    std::cout << rd.file_attributes << std::endl;
//    std::cout << rd.file_creation_date << std::endl;
//    std::cout << rd.file_extension_size << std::endl;
//    std::cout << rd.file_modification_date << std::endl;
//    std::cout << rd.initial_cluster_number << std::endl << std::endl;

//    std::cout << "Users Table" << std::endl;
//    std::cout << ut.user_name << std::endl;
//    std::cout << ut.user_password << std::endl;
//    std::cout << ut.user_id << std::endl;
//    std::cout << ut.user_role << std::endl;
}

void SystemSelector::chooseFileSystem()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open BIN"), ".", tr("Bin Files(*.bin)"));
    if (file_name == "") {
        return;
    }

    operatingSystem os;
    this->readFromFile(file_name.toStdString(), os);
    AuthForm *af = new AuthForm(os);
    af->show();
    this->close();
}

void SystemSelector::createFileSystem()
{
    if (ui->fileSystemName_textEdit->toPlainText().isEmpty()) {
        return;
    }
    const char* file_system_name = ui->fileSystemName_textEdit->toPlainText().toStdString().c_str();
    // strcpy(file_system_name, ui->fileSystemName_textEdit->toPlainText().toStdString().c_str());
    superBlock sb;
    strcpy(sb.file_system_name, "test");
    sb.cluster_size = 4;
    sb.cluster_amount = 3;
    sb.root_dir_size = 50;
    sb.root_dir_offset = sizeof(superBlock);
    sb.user_table_offset = sb.root_dir_offset + sizeof(rootDirectory);
    sb.data_area_offset = sb.user_table_offset + sizeof(usersTable);
    sb.hard_disk_size = 100;

    rootDirectory rd;
    rd.user_id = 515;
    rd.file_size = 25;
    rd.access_rights = 0b10100;
    rd.file_name_size = 4;
    rd.file_attributes = 0b101;
    rd.file_creation_date = 15;
    rd.file_extension_size = 20;
    rd.file_modification_date = 17;
    rd.initial_cluster_number = 1;

    usersTable ut;
    strcpy(ut.user_name, "ChazGrant\0");
    strcpy(ut.user_password, "password\0");
    strcpy(ut.user_id, "1\0");
    ut.user_role = (char)UserRole::USER;

    usersTable new_user;
    strcpy(new_user.user_name, "NewUser\0");
    strcpy(new_user.user_password, "password\0");
    strcpy(new_user.user_id, "2\0");
    new_user.user_role = (char)UserRole::USER;

    std::vector<usersTable> users;
    users.push_back(ut);
    users.push_back(new_user);

    // sprintf(file_system_name, "%s%s", file_system_name, ".bin");
    // std::ofstream output_file(file_system_name);
    std::ofstream output_file(file_system_name);

    output_file.write((char*)&sb, sizeof(sb));
    output_file.write((char*)&rd, sizeof(rd));
    output_file.write((char*)&users, sizeof(users) * users.size());
    output_file.close();
    qDebug() << "File System Has Been Created";
}
