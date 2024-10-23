//
// Created by Teodora Schiau on 09.05.2024.
//

#ifndef OOP_A8_9_916_SCHIAU_TEODORA_ADMINGUI_H
#define OOP_A8_9_916_SCHIAU_TEODORA_ADMINGUI_H
#include "service.h"
#include <QWidget>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QComboBox>
#include <QVBoxLayout>
#include <QDialog>
#include <QShortcut>

class AdminMode: public QDialog
{
private:
    Service& service;
    QListWidget* moviesList;
    QLineEdit *title, *genre, *year, *likes, *trailer;
    QPushButton *addButton, *deleteButton, *updateTitleButton, *updateGenreButton, *updateYearButton, *updateLkesButton, *updateTrailerButton, *displayButton,*undoButton, *redoButton;
    QShortcut* undoShortcut, *redoShortcut;

public:
    AdminMode(Service& service, QWidget* parent = NULL);
    ~AdminMode();
    void initAdminMode();
    void connectSignals();
    int getSelectedIndex() const;
    void populateList();
    void addMovie();
    void deleteMovie();
    void updateTitle();
    void updateGenre();
    void updateYear();
    void updateLikes();
    void updateTrailer();
    void undo();
    void redo();
};
#endif //OOP_A8_9_916_SCHIAU_TEODORA_ADMINGUI_H
