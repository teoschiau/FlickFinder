//
// Created by Teodora Schiau on 16.05.2024.
//

#ifndef OOP_A8_9_916_SCHIAU_TEODORA_QTGUI_H
#define OOP_A8_9_916_SCHIAU_TEODORA_QTGUI_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class QTGUI; }
QT_END_NAMESPACE

class QTGUI : public QWidget {
Q_OBJECT

public:
    explicit QTGUI(QWidget *parent = nullptr);

    ~QTGUI() override;

private:
    Ui::QTGUI *ui;
};


#endif //OOP_A8_9_916_SCHIAU_TEODORA_QTGUI_H
