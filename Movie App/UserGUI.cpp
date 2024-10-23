//
// Created by Teodora Schiau on 10.05.2024.
//

#include "UserGUI.h"
#include "qformlayout.h"
#include "qgridlayout.h"
#include <qlabel.h>
#include <QMessageBox>
#include <QMainWindow>
#include "validator.h"

UserMode::UserMode(Service &service, Repository& repo, WriteFile *wf, QWidget *parent):service{service},repo{repo}, wfile{wf}, QDialog{parent} {
    this->initUserMode();
    this->connectSignal();
    this->tableMode = new TableMode{this->repo};
    this->watchList= new QTableView{};
    this->watchList->setModel(this->tableMode);
}

void UserMode::initUserMode() {

    this->writefilelist = new QListWidget{};

    this->title = new QLineEdit{};
    this->year = new QLineEdit{};
    this->trailer= new QLineEdit{};

    this->genreBox = new QComboBox{};
    this->genreBox->addItem("All genres");
    this->genreBox->addItem("Adventure");
    this->genreBox->addItem("Comedy");
    this->genreBox->addItem("Drama");
    this->genreBox->addItem("Horror");
    this->genreBox->addItem("Romantic");
    this->genreBox->addItem("Thriller");

    this->tableButton = new QPushButton{"Open Table View"};
    this->undoButton = new QPushButton{"Undo"};
    this->redoButton = new QPushButton{"Redo"};

    this->displayProductsButton = new QPushButton{"Display All Movies"};
    this->displayWatchListButton= new QPushButton{"Display Watch List"};
    this->deletemovie= new QPushButton{"Delete Watch List Movie"};
    this->openAppButton = new QPushButton{"Open Application"};
    QLabel *title = new QLabel();
    title->setText("Title:");

    QLabel *year = new QLabel();
    year->setText("Year:");

    QLabel *trailer = new QLabel();
    trailer->setText("Trailer:");

    QLabel *space = new QLabel();
    space->setText("");

    QLabel *genre = new QLabel();
    genre->setText("Genre:");

    QFormLayout* moviesDelete = new QFormLayout();
    moviesDelete->addRow(title, this->title);
    moviesDelete->addRow(year, this->year);
    moviesDelete->addRow(trailer, this->trailer);

    QLabel *moviesText = new QLabel();
    moviesText->setText("Watch List:");


    QVBoxLayout* userLayouts = new QVBoxLayout(this);
    userLayouts->addWidget(moviesText);
    userLayouts->addWidget(this->writefilelist);

    QFormLayout* moviesDetails = new QFormLayout();
    moviesDetails->addRow(genre, this->genreBox);
    userLayouts->addLayout(moviesDetails);

    userLayouts->addLayout(moviesDelete);

    QGridLayout* buttons = new QGridLayout();
    buttons->addWidget(this->displayProductsButton, 1,0);
    buttons->addWidget(this->displayWatchListButton, 2, 0);
    buttons->addWidget(this->deletemovie, 3, 0);
    buttons->addWidget(this->openAppButton, 4, 0);
    buttons->addWidget(this->undoButton, 5, 0);
    buttons->addWidget(this->redoButton, 6, 0);
    buttons->addWidget(this->tableButton, 7, 0);

    userLayouts->addLayout(buttons);

    QWidget *userDisplayWindow = new QWidget();
    this->undoShortcut = new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Z), userDisplayWindow);

    this->redoShortcut = new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Y), userDisplayWindow);

    userDisplayWindow->setLayout(userLayouts);
    userDisplayWindow->show();
}

void UserMode::connectSignal() {
    QObject::connect(this->writefilelist, &QListWidget::itemSelectionChanged, [this](){
        int index = this->getSelectedItemsW();

        if(index<0)
            return;

        Movie m = this->service.GetUserRepo()[index];
        this->title->setText(QString::fromStdString(m.getTitle()));
        this->year->setText(QString::fromStdString(to_string(m.getYear())));
        this->trailer->setText(QString::fromStdString(m.getTrailer()));
    });
    QObject::connect(this->displayProductsButton, &QPushButton::clicked, this, &UserMode::displayProducts);
    QObject::connect(this->displayWatchListButton, &QPushButton::clicked, this, &UserMode::populateWatchList);
    QObject::connect(this->openAppButton, &QPushButton::clicked, this, &UserMode::openApp);
    QObject::connect(this->deletemovie,&QPushButton::clicked,this,&UserMode::deleteMovie);
    QObject::connect(this->tableButton,&QPushButton::clicked,this,&UserMode::openTableView);
    QObject::connect(this->undoButton,&QPushButton::clicked,this,&UserMode::undo);
    QObject::connect(this->redoButton,&QPushButton::clicked,this,&UserMode::redo);
    QObject::connect(this->undoShortcut, &QShortcut::activated, this, &UserMode::undo);
    QObject::connect(this->redoShortcut, &QShortcut::activated, this, &UserMode::redo);

}
void UserMode::connectSignalDisplay() {
    QObject::connect(this->nextButton, &QPushButton::clicked, this, &UserMode::nextProduct);
    QObject::connect(this->addButton, &QPushButton::clicked, this, &UserMode::addProduct);
    QObject::connect(this->exitButton, &QPushButton::clicked, this, &QMainWindow::close);
}
UserMode::~UserMode(){

}
int UserMode::getSelectedItemsW() {
    QModelIndexList index = this->writefilelist->selectionModel()->selectedIndexes();
    if(index. isEmpty())
        return -1;
    int indexes = index.at(0).row();
    return indexes;
}

int UserMode::getSelectedItems() {
    QModelIndexList index = this->moviesList->selectionModel()->selectedIndexes();
    if(index. isEmpty())
        return -1;
    int indexes = index.at(0).row();
    return indexes;
}
void UserMode::displayProducts() {
    if(this->service.GetRepo().size()==0){
        QMessageBox::critical(this, "Error", "There are no movies at the cinema!");
        return;
    }else{
        this->genre = this->genreBox->currentText().toStdString();
        this->initWatchList();
        this->displayWatchList();
    }
}
void UserMode::initWatchList() {
    this->moviesList = new QListWidget{};
    this->nextButton = new QPushButton{"NEXT"};
    this->addButton = new QPushButton{"ADD"};
    this->exitButton = new QPushButton{"EXIT"};

    QLabel *moviesText = new QLabel();
    moviesText->setText("Movies:");

    QVBoxLayout* displayLayout = new QVBoxLayout();
    displayLayout->addWidget(moviesText);
    displayLayout->addWidget(this->moviesList);

    QGridLayout* buttons = new QGridLayout();
    buttons->addWidget(this->nextButton, 0, 0);
    buttons->addWidget(this->addButton, 0, 1);
    //buttons->addWidget(this->exitButton, 0, 2);


    displayLayout->addLayout(buttons);
    QWidget *mainDisplay = new QWidget();
    mainDisplay->setLayout(displayLayout);
    mainDisplay->show();
}

void UserMode::populateDisplayProducts(int position, vector<Movie> movie) {
    this->moviesList->clear();
    Movie m = movie[position];
    this->moviesList->addItem(QString::fromStdString(m.getTitle() + "-" + m.getGenre() + "-" + to_string(m.getYear()) + "-" +
                                                             to_string(m.getLikes()) + "-" + m.getTrailer()));
}

void UserMode::populateWatchList() {
    this->writefilelist->clear();
    vector<Movie> movies = this->service.GetUserRepo();
    if(movies.size() == 0)
    {
        QMessageBox::critical(this, "Error","There are no movies!");
        return;
    }
    for(Movie &m : movies)
        this->writefilelist->addItem(QString::fromStdString(m.getTitle() + "-" + m.getGenre() + "-" + to_string(m.getYear()) + "-" +
                                                         to_string(m.getLikes()) + "-" + m.getTrailer()));
}

void UserMode::nextProduct() {
    vector<Movie> movies = this->service.FilteredRepo(this->genre);
    if(movies.size() == 0)
    {
        QMessageBox::critical(this, "Error","There are no movies!");
        return;
    }
    if(this->position == movies.size()-1){
        QMessageBox::critical(this, "Error","You arrived at the end of the list!");
        this->position = 0;
    }
    else
        this->position +=1;
    this->populateDisplayProducts(this->position, movies);
    this->notifyMode();
}

void UserMode::addProduct() {
    vector<Movie> movies = this->service.FilteredRepo(this->genre);
    if(movies.size() == 0)
    {
        QMessageBox::critical(this, "Error","There are no movies!");
        return;
    }
    int pos = this->position;
    int i = this->getSelectedItems();
    if( i == -1)
    {
        QMessageBox::critical(this, "Error","Please select an item!");
        return;
    }else{
        if(this->position == movies.size()-1){
            this->service.add_element_user_service(movies[pos].getTitle(), movies[pos].getGenre(),
                                                   movies[pos].getYear(), movies[pos].getLikes(),
                                                   movies[pos].getTrailer());
            QMessageBox::critical(this, "Error","You arrived at the end of the list!");
            this->position = 0;
        }else {
            this->service.add_element_user_service(movies[pos].getTitle(), movies[pos].getGenre(),
                                                   movies[pos].getYear(), movies[pos].getLikes(),
                                                   movies[pos].getTrailer());
            this->position++;
            pos++;
        }
        this->populateDisplayProducts(this->position, movies);
    }
    this->notifyMode();
}

void UserMode::displayWatchList() {
    this->position =0;
    vector<Movie> movies = this->service.FilteredRepo(this->genre);
    if( movies.size() == 0)
    {
        QMessageBox::critical(this, "Error","There are no movies!");
        return;
    }
    this->populateDisplayProducts(0, movies);
    this->connectSignalDisplay();
}
void UserMode::openApp() {
    this->wfile->setData(this->service.GetUserRepo());
    this->wfile->WriteData();
    this->wfile->openFile();
}

void UserMode::deleteMovie() {
    string title = this->title->text().toStdString();
    string year = this->year->text().toStdString();
    string trailer = this->trailer->text().toStdString();

    try{
        int v_year = Validator::validate_year(year);
        Validator::validate_title(title);
        Validator::validate_trailer(trailer);
        this->service.delete_element_user_service(title,stoi(year),trailer);
    }catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    this->populateWatchList();
    int lastel = this->service.GetUserRepo().size()-1;
    this->writefilelist->setCurrentRow(lastel);
    this->notifyMode();
}
void UserMode::undo(){
    try{
        this->service.undoUserMode();
        this->notifyMode();
        this->populateWatchList();
    }catch(...)
    {
        QMessageBox::critical(this,"Error","No more undos!");
        return;
    }
}
void UserMode::redo(){
    try{
        this->service.redoUserMode();
        this->notifyMode();
        this->populateWatchList();
    }catch(...)
    {
        QMessageBox::critical(this,"Error","No more redos!");
        return;
    }
}
void UserMode::openTableView() {
    this->watchList->resize(1000,600);
    this->watchList->resizeColumnsToContents();
    this->watchList->resizeRowsToContents();
    this->watchList->show();
}
void UserMode::notifyMode() {
    this->tableMode->updateInternalData();
    this->watchList->resize(1000,600);
    this->watchList->resizeColumnsToContents();
    this->watchList->resizeRowsToContents();
}