//
// Created by Teodora Schiau on 09.05.2024.
//

#include "GUI.h"
#include "qformlayout.h"
#include "qgridlayout.h"
#include "qlabel.h"
#include <iostream>
#include <QMessageBox>
#include "AdminGUI.h"
#include "UserGUI.h"
#include "validator.h"
#include "qformlayout.h"
#include "qgridlayout.h"
#include <QChart>
#include <QtCharts>
#include <QBarSeries>
#include <QBarSet>


using namespace std;

GUI::GUI(Service &service,Repository& repo, QWidget *parent): service{service},repo{repo}, QMainWindow(parent){
    this->initGUI();
    this->connectSignal();
}

void GUI::initGUI() {
    //QFont buttonsFont("Consolas", 13, true);

    this->save = new QPushButton{"Save File"};
    this->adminMode = new QPushButton{"Admin Mode"};
    this->userMode = new QPushButton{"User Mode"};
    this->open = new QPushButton{"Open Chart"};

    this->filetype = new QComboBox{};
    this->filetype->addItem("HTML File");
    this->filetype->addItem("CSV File");

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QLabel* intro = new QLabel();
    intro->setText("Welcome to the cinema!");
    intro->setAlignment(Qt::AlignCenter);

    QLabel* space = new QLabel();
    space->setText("");

    QLabel *filename = new QLabel();
    filename->setText("Choose the type of the file");

    mainLayout->addWidget(intro);
    mainLayout->addWidget(space);

    QFormLayout* fileDetails = new QFormLayout();
    fileDetails->addRow(filename, this->filetype);

    mainLayout->addLayout(fileDetails);

    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->save, 0, 0);
    buttonsLayout->addWidget(this->adminMode, 1, 0);
    buttonsLayout->addWidget(this->userMode, 2, 0);
    buttonsLayout->addWidget(this->open, 3, 0);

    mainLayout->addLayout(buttonsLayout);

    QWidget* mainWindow = new QWidget();
    mainWindow->setLayout(mainLayout);
    setCentralWidget(mainWindow);
}

void GUI::connectSignal() {
    QObject::connect(this->save, &QPushButton::clicked, this, &GUI::saveFile);
    QObject::connect(this->userMode, &QPushButton::clicked, this, &GUI::startUserMode);
    QObject::connect(this->adminMode, &QPushButton::clicked, this, &GUI::startAdminMode);;
    QObject::connect(this->open, &QPushButton::clicked, this, &GUI::createChart);
}

void GUI::startAdminMode() {
    if (type == "empty") {
        QMessageBox::critical(this, "Error", "You have to choose a type for the file first!");
        return;
    } else {
        this->setCursor(Qt::WaitCursor);
        AdminMode* amg = new AdminMode{service};
        this->setCursor(Qt::ArrowCursor);
    }
}

void GUI::startUserMode() {
    if(type == "empty") {
        QMessageBox::critical(this, "Error", "You have to choose a type for the file first!");
        return;
    }
    else {
        this->setCursor(Qt::WaitCursor);
        UserMode* umg = new UserMode{service,repo, this->wf};
        this->setCursor(Qt::ArrowCursor);
    }
}

void GUI::saveFile() {
    this->type = this->filetype->currentText().toStdString();
    if(this->type == "HTML File")
        this->wf = new HTML();
    else if(this->type == "CSV File")
        this->wf = new CSV();
}

GUI::~GUI(){}

void GUI::createChart() {
    QBarSeries *Bars = new QBarSeries();
    for(auto m: this->service.GetRepo())
    {
        auto* set = new QBarSet(QString::fromStdString(m.getTitle()));
        *set << m.getLikes();
        Bars->append(set);
    }
    QChart *Chart = new QChart{};
    Chart->addSeries(Bars);
    Chart->setTitle("Movies displayes by the number of likes");
    Chart->setTheme(QChart::ChartThemeQt);

    Chart->setAnimationOptions(QChart::AllAnimations);
    Chart->setAnimationDuration(2000);

    Chart->createDefaultAxes();

    Chart->legend()->setVisible(true);
    Chart->legend()->setAlignment(Qt::AlignBottom);


    QChartView *ChartView = new QChartView(Chart);
    ChartView->setRenderHint(QPainter::SmoothPixmapTransform);
    ChartView->resize(1200,800);
    ChartView->show();

}