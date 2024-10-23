//
// Created by Teodora Schiau on 16.05.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QTGUI.h" resolved

#include "qtgui.h"
#include "ui_QTGUI.h"


QTGUI::QTGUI(QWidget *parent) :
        QWidget(parent), ui(new Ui::QTGUI) {
    ui->setupUi(this);
}

QTGUI::~QTGUI() {
    delete ui;
}
