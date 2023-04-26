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

int main(int argc, char *argv[])
{
//    std::remove("OperatingSystem.bin");
//    writeIntoFile("OperatingSystem.bin");
//    readFromFile("OperatingSystem.bin");

//    char some_char[3];
//    char another_char[3];
//    strcpy(some_char, "abcdef");
//    some_char[3] = '\0';
//    std::cout << some_char << std::endl;
//    std::cout << another_char << std::endl;
//    std::bitset<8>set("01001001");
//    std::cout << set << std::endl;
//    return 0;

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

//    usersTable current_user = ut;
//    while (true) {
//        std::cout << "1" << std::endl;
//        std::cout << current_user.user_name << std::endl;
//        if (current_user.next == nullptr) {
//            break;
//        }
//        current_user = *current_user.next;
//    }

//    return 0;
    QApplication a(argc, argv);
    SystemSelector ss;
    ss.show();
    return a.exec();
}
