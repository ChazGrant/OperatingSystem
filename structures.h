#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <bitset>
#include <functional>
#include <QStringList>

enum UserRole {
    ADMIN='a',
    USER='u'
};

typedef struct superBlock {
    char file_system_name[6];
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
    std::bitset<3> file_attributes;
    std::bitset<5> access_rights;
    uint16_t user_id;
    uint64_t file_creation_date;
    uint64_t file_modification_date;
    uint16_t initial_cluster_number;
} rootDirectory;

typedef struct usersTable {
    char user_name[15];
    char user_password[32];
    char user_id[2];
    char user_role;
} usersTable;

typedef struct operatingSystem {
    superBlock super_block;
    rootDirectory root_directory;
    usersTable user_table;
} operatingSystem;

struct functionCaller {
    char* allias;
    std::function<void(QStringList commands_list)> action;

    functionCaller (char* allias, std::function<void(QStringList commands_list)> action) {
        this->allias = allias;
        this->action = action;
    };
};

#endif // STRUCTURES_H
