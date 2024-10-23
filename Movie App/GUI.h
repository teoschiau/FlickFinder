//
// Created by Teodora Schiau on 09.05.2024.
//

#ifndef OOP_A8_9_916_SCHIAU_TEODORA_GUI_H
#define OOP_A8_9_916_SCHIAU_TEODORA_GUI_H
#include "service.h"
#include "WriteFile.h"
#include "AdminGUI.h"
#include <QVBoxLayout>
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QComboBox>
#include <QMainWindow>

class GUI: public QMainWindow
{
private:
    string type="empty";
    Service& service;
    Repository& repo;
    WriteFile* wf;
    QComboBox * filetype;
    QPushButton* adminMode, *userMode, *save, *open;
    void initGUI();

public:
    GUI(Service& service, Repository& repo,QWidget *parent = 0);
    ~GUI();
    void connectSignal();
    void startUserMode();
    void startAdminMode();
    void saveFile();
    void createChart();
};
#endif //OOP_A8_9_916_SCHIAU_TEODORA_GUI_H
