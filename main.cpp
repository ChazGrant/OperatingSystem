#include "mainwindow.h"

#include <QApplication>

#include <fstream>
#include <iostream>

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

typedef struct superBlock {
    char* file_system_name;
    uint16_t cluster_size;
    int cluster_amount;
    int root_dir_size;
    int root_dir_offset;
    int user_table_offset;
    int data_area_offset;
    int hard_disk_size;
} superBlock;

typedef struct rootDirectory {
    int file_name_size;
    uint32_t file_extension_size;
    uint32_t file_size;
    int file_attributes;
    int access_rights;
    uint16_t user_id;
    uint64_t file_creation_date;
    uint64_t file_modification_date;
    uint16_t initial_cluster_number;
} rootDirectory;

typedef struct usersTable {
    char user_name[15];
    char user_password[32];
    char user_id[2];
    char user_role[1];
} usersTable;

void writeIntoFile(std::string t_file_name)
{
    superBlock sb;
    sb.file_system_name = (char*)"FAT";
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
    strcpy(ut.user_id, "ab\0");
    strcpy(ut.user_name, "ChazGrant\0");
    strcpy(ut.user_role, "a\0");
    strcpy(ut.user_password, "password\0");

    std::ofstream output_file(t_file_name);

    output_file.write((char*)&sb, sizeof(sb));
    // output_file.seekp(sb.root_dir_offset);
    output_file.write((char*)&rd, sizeof(rd));
    // output_file.seekp(sb.user_table_offset);
    output_file.write((char*)&ut, sizeof(ut));
    output_file.close();
}

void readFromFile(std::string t_file_name)
{
    superBlock sb;
    rootDirectory rd;
    usersTable ut;

    std::ifstream input_file(t_file_name);

    // input_file.read((char*)&sb, sizeof(sb));
//    input_file.seekg(sb.root_dir_offset);
//    input_file.read((char*)&rd, sizeof(rd));
    input_file.seekg(sb.user_table_offset, std::ios::beg);
    input_file.read((char*)&ut, sizeof(ut));

//    std::cout << "Super Block: " << std::endl;
//    std::cout << sb.file_system_name << std::endl;
//    std::cout << sb.cluster_size << std::endl;
//    std::cout << sb.cluster_amount << std::endl;
//    std::cout << sb.root_dir_size << std::endl;
//    std::cout << sb.root_dir_offset << std::endl;
//    std::cout << sb.user_table_offset << std::endl;
//    std::cout << sb.data_area_offset << std::endl;
//    std::cout << sb.hard_disk_size << std::endl << std::endl;

    std::cout << "Users Table" << std::endl;
    /*char user_id[2] = {ut.user_id}*/;
    std::cout << ut.user_id << std::endl;
    std::cout << ut.user_name << std::endl;
    std::cout << ut.user_role << std::endl;
    std::cout << ut.user_password << std::endl;
}

int main(int argc, char *argv[])
{
    std::remove("OperatingSystem.bin");
    writeIntoFile("OperatingSystem.bin");
    readFromFile("OperatingSystem.bin");

    return 0;
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
}
