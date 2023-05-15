#include "systemselector.h"

#include <QApplication>

#include <fstream>
#include <iostream>
#include <bitset>

#include "structures.h"

/*
58 вариант
    Режим работы: мультипрограммный, многопользовательский
    Управление процессами: квантование времени, относительные приоритеты, динамические приоритеты
    Средства взаимодействия процессов: каналы, сообщения, разделяемая память
    Организация ОП: страничная
    Внешние устройства: клавиатура, мышь, монитор
    Организация файловой системы: одноуровневая, битовая карта свободных/занятых кластеров,
файлы с последовательным доступом, файлы с прямым доступом
    Команды эмулятора: Копирование создание файла,
каталога, Вход и выход в систему , создание пользователей, групп, Перемещение, переименование,
Создание файла, каталога, удаление, дописать в конец файла, Изменение прав доступа,
Информация о процессах, Изменение приоритета процесса, Уничтожение
    Эмуляция планировщика
*/

// Служебная область
/*
 * Суперблок
 * FAT
 * Копия FAT
 * Корневой каталог
*/

// Область данных
/*
 * Файл с таблицей пользователей
 * Файлы и каталоги
*/

void createFile(char* t_path, char* t_file_name);
void copyFile(char* t_source, char* t_destination);
void moveFile(char* t_source, char* t_destination);
void createDirectory(char* t_directory_name);
void login(char t_user_name[15], char t_user_password[32]);
void logout(char t_user_name[15]);
void createUser(char t_user_name[15], char t_user_password[32], char t_user_role);
void createGroup(char* t_group_name);
void renameFile(char* t_old_file_name, char* t_new_file_name);
void deleteFile(char* t_file_name);
void deleteDirectory(int t_directory_name);
void writeToTheEnd(int t_file_name, char* t_data);
void changeAccessRights(int t_file_name, std::bitset<5> t_access_rights);
void getProcsInfo();
void changeProcessPriority(int t_process_id, int t_priority);
void killProcess(int t_process_id);

void readFromFile(std::string t_file_name, operatingSystem &t_os)
{
    superBlock sb;
    rootDirectory rd;
    std::vector<usersTable> users;

    std::ifstream input_file(t_file_name, std::ios::binary);

    users.reserve(2);

    input_file.read((char*)&sb, sizeof(sb));
    input_file.seekg(sb.root_dir_offset);
    input_file.read((char*)&rd, sizeof(rd));
    input_file.seekg(sb.user_table_offset);
    input_file.read((char*)&users, sizeof(users) * 2);

    t_os.super_block = sb;
    t_os.root_directory = rd;
    t_os.users = users;
}

void createFileSystem(char* file_system_name)
{
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
    strcpy(ut.user_name, "ChazGrant");
    strcpy(ut.user_password, "password");
    strcpy(ut.user_id, "1");
    ut.user_role = (char)UserRole::USER;

    usersTable new_user;
    strcpy(new_user.user_name, "NewUser");
    strcpy(new_user.user_password, "password");
    strcpy(new_user.user_id, "2");
    new_user.user_role = (char)UserRole::USER;

    std::vector<usersTable> users;
    users.push_back(ut);
    users.push_back(new_user);

    std::ofstream output_file(file_system_name, std::ios::binary);

    output_file.write((char*)&sb, sizeof(sb));
    output_file.write((char*)&rd, sizeof(rd));
    output_file.write((char*)&users, sizeof(users) * users.size());
    output_file.close();
    qDebug() << "File System Has Been Created";
}

int main(int argc, char *argv[])
{
    operatingSystem os;
    std::remove("OperatingSystem.bin");
    createFileSystem("OperatingSystem.bin");
    readFromFile("OperatingSystem.bin", os);

//    usersTable ut;
//    strcpy(ut.user_name, "ChazGrant");
//    strcpy(ut.user_password, "password");
//    strcpy(ut.user_id, "1");
//    ut.user_role = (char)UserRole::USER;

//    usersTable new_user;
//    strcpy(new_user.user_name, "NewUser");
//    strcpy(new_user.user_password, "password");
//    strcpy(new_user.user_id, "2");
//    new_user.user_role = (char)UserRole::USER;
//    ut.next = &new_user;

    int users_count = os.users.size();
    qDebug() << users_count;
    for (int i = 0; i < users_count; ++i) {
        usersTable current_user = os.users[i];
        std::cout << "User id: " << current_user.user_id << std::endl;
        std::cout << "User name: " << current_user.user_name << std::endl;
    }

    return 0;
    QApplication a(argc, argv);
    SystemSelector ss;
    ss.show();
    return a.exec();
}
