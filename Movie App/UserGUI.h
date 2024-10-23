//
// Created by Teodora Schiau on 10.05.2024.
//

#ifndef OOP_A8_9_916_SCHIAU_TEODORA_USERGUI_H
#define OOP_A8_9_916_SCHIAU_TEODORA_USERGUI_H
#include "service.h"
#include <QVBoxLayout>
#include <qwidget.h>
#include <qlistwidget.h>
#include "WriteFile.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QComboBox>
#include <QDialog>
#include <QTableView>
#include "TableMode.h"
#include <QShortcut>

class UserMode: public QDialog{

private:
    int position;
    string genre;
    QComboBox *genreBox;
    WriteFile* wfile;
    Service& service;
    Repository& repo;
    QListWidget* moviesList;
    QListWidget* writefilelist;
    QPushButton* displayProductsButton, *openAppButton, *displayWatchListButton, *deletemovie, *undoButton, *redoButton;
    QPushButton* nextButton, *addButton, *exitButton;
    QPushButton* tableButton;
    QLineEdit *title, *year, *trailer;
    QTableView* watchList;
    TableMode* tableMode;
    QShortcut* undoShortcut;
    QShortcut* redoShortcut;

public:
    UserMode(Service& service,Repository& repo, WriteFile* wf, QWidget* parent = NULL);
    ~UserMode();
    void connectSignal();
    int getSelectedItems();
    int getSelectedItemsW();
    void initUserMode();
    void connectSignalDisplay();
    void populateWatchList();
    void openApp();
    void populateDisplayProducts(int position, vector<Movie> movie);
    void displayWatchList();
    void nextProduct();
    void addProduct();
    void initWatchList();
    void displayProducts();
    void deleteMovie();
    void openTableView();
    void notifyMode();
    void undo();
    void redo();
};

#endif //OOP_A8_9_916_SCHIAU_TEODORA_USERGUI_H
