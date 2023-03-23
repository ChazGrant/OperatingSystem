#ifndef SYSTEMSELECTOR_H
#define SYSTEMSELECTOR_H

#include <QWidget>
#include <QFileDialog>
#include <QDebug>

#include <fstream>

#include "structures.h"

namespace Ui {
class SystemSelector;
}

class SystemSelector : public QWidget
{
    Q_OBJECT

public:
    explicit SystemSelector(QWidget *parent = nullptr);
    ~SystemSelector();

private:
    Ui::SystemSelector *ui;

    void chooseFileSystem();
    void createFileSystem();
    void readFromFile(std::string t_file_name, operatingSystem &os);
};

#endif // SYSTEMSELECTOR_H
