//
// Created by Teodora Schiau on 09.05.2024.
//

#include "AdminGUI.h"
#include "qformlayout.h"
#include "qgridlayout.h"
#include "qlabel.h"
#include <QMessageBox>
#include "validator.h"

AdminMode::AdminMode(Service &service, QWidget *parent):service{service}, QDialog{parent} {
    this->initAdminMode();
    this->populateList();
    this->connectSignals();
}

void AdminMode::initAdminMode() {
    this->moviesList = new QListWidget{};

    this->title = new QLineEdit{};
    this->genre = new QLineEdit{};
    this->year = new QLineEdit{};
    this->likes = new QLineEdit{};
    this->trailer= new QLineEdit{};

    this->addButton = new QPushButton{"ADD"};
    this->deleteButton = new QPushButton{"DELETE"};
    this->updateTitleButton = new QPushButton{"UPDATE TITLE"};
    this->updateGenreButton = new QPushButton{"UPDATE GENRE"};
    this->updateYearButton = new QPushButton{"UPDATE YEAR"};
    this->updateLkesButton = new QPushButton{"UPDATE LIKES"};
    this->updateTrailerButton = new QPushButton{"UPDATE TRAILER"};
    this->undoButton = new QPushButton{"UNDO"};
    this->redoButton = new QPushButton{"REDO"};
    this->displayButton = new QPushButton{"DISPLAY"};

    auto *space = new QLabel();
    space->setText("");

    QLabel *moviesText = new QLabel();
    moviesText->setText("The list of movies:");

    QLabel *title = new QLabel();
    title->setText("Title:");

    QLabel *genre = new QLabel();
    genre->setText("Genre:");

    QLabel *year = new QLabel();
    year->setText("Year:");

    QLabel *likes = new QLabel();
    likes->setText("Likes:");

    QLabel *trailer = new QLabel();
    trailer->setText("Trailer:");

    QVBoxLayout* adminlayout = new QVBoxLayout();
    adminlayout->addWidget(moviesText);
    adminlayout->addWidget(this->moviesList);

    QFormLayout* moviesDetails = new QFormLayout();
    moviesDetails->addRow(title, this->title);
    moviesDetails->addRow(genre, this->genre);
    moviesDetails->addRow(year, this->year);
    moviesDetails->addRow(likes, this->likes);
    moviesDetails->addRow(trailer, this->trailer);

    adminlayout->addLayout(moviesDetails);

    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->addButton, 0, 1);
    buttonsLayout->addWidget(this->deleteButton, 0,2);
    //buttonsLayout->addWidget(this->displayButton, 0,3);
    buttonsLayout->addWidget(this->undoButton, 2,1);
    buttonsLayout->addWidget(this->updateGenreButton, 1,1);
    buttonsLayout->addWidget(this->updateLkesButton, 1,2);
    buttonsLayout->addWidget(this->redoButton, 2,2);

    adminlayout->addLayout(buttonsLayout);
    QWidget*admindisplayWindow = new QWidget();
    this->undoShortcut = new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Z), admindisplayWindow);

    this->redoShortcut = new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Y), admindisplayWindow);
    admindisplayWindow->setLayout(adminlayout);
    admindisplayWindow->show();

}

void AdminMode::populateList() {
    this->moviesList->clear();
    vector<Movie> Movies = this->service.GetRepo();
    for(Movie &m: Movies){
        this->moviesList->addItem(QString::fromStdString(m.getTitle()+"-"+ m.getGenre()+"-"+ to_string(m.getYear())+"-"+ to_string(m.getLikes())+"-"+ m.getTrailer()));
    }
}

void AdminMode::connectSignals() {
    QObject::connect(this->moviesList, &QListWidget::itemSelectionChanged, [this](){
        int index = this->getSelectedIndex();

        if(index<0)
            return;

        Movie m = this->service.GetRepo()[index];
        this->title->setText(QString::fromStdString(m.getTitle()));
        this->genre->setText(QString::fromStdString(m.getGenre()));
        this->year->setText(QString::fromStdString(to_string(m.getYear())));
        this->likes->setText(QString::fromStdString(to_string(m.getLikes())));
        this->trailer->setText(QString::fromStdString(m.getTrailer()));
    });
    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminMode::addMovie);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminMode::deleteMovie);
    QObject::connect(this->updateTitleButton, &QPushButton::clicked, this, &AdminMode::updateTitle);
    QObject::connect(this->updateGenreButton, &QPushButton::clicked, this, &AdminMode::updateGenre);
    QObject::connect(this->updateYearButton, &QPushButton::clicked, this, &AdminMode::updateYear);
    QObject::connect(this->updateLkesButton, &QPushButton::clicked, this, &AdminMode::updateLikes);
    QObject::connect(this->updateTrailerButton, &QPushButton::clicked, this, &AdminMode::updateTrailer);
    QObject::connect(this->undoButton, &QPushButton::clicked, this, &AdminMode::undo);
    QObject::connect(this->redoButton, &QPushButton::clicked, this, &AdminMode::redo);
    QObject::connect(this->redoShortcut, &QShortcut::activated, this, &AdminMode::redo);
    QObject::connect(this->undoShortcut, &QShortcut::activated, this, &AdminMode::undo);
    QObject::connect(this->displayButton, &QPushButton::clicked, this, &AdminMode::populateList);
}

int AdminMode::getSelectedIndex() const {
    QModelIndexList index = this->moviesList->selectionModel()->selectedIndexes();
    if(index.isEmpty())
    {
        this->title->clear();
        this->genre->clear();
        this->year->clear();
        this->likes->clear();
        this->trailer->clear();
        return -1;
    }
    int indexes = index.at(0).row();
    return indexes;
}

void AdminMode::addMovie() {
    string title = this->title->text().toStdString();
    string genre = this->genre->text().toStdString();
    string year = this->year->text().toStdString();
    string likes = this->likes->text().toStdString();
    string trailer = this->trailer->text().toStdString();

    try{
        int v_year = Validator::validate_year(year);
        int v_likes = Validator::validate_likes(likes);
        Validator::validate_title(title);
        Validator::validate_genre(genre);
        Validator::validate_trailer(trailer);
        this->service.add_element_service(title,genre,stoi(year), stoi(likes), trailer);
    }catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    this->populateList();
    int lastel = this->service.GetRepo().size()-1;
    this->moviesList->setCurrentRow(lastel);
}

void AdminMode::deleteMovie() {
    string title = this->title->text().toStdString();
    string year = this->year->text().toStdString();
    string trailer = this->trailer->text().toStdString();

    try{
        int v_year = Validator::validate_year(year);
        Validator::validate_title(title);
        Validator::validate_trailer(trailer);
        this->service.delete_element_service(title,stoi(year),trailer);
    }catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    this->populateList();
    int lastel = this->service.GetRepo().size()-1;
    this->moviesList->setCurrentRow(lastel);
}
void AdminMode::updateTitle() {
    string title = this->title->text().toStdString();
    string new_title = this->title->text().toStdString();
    string year = this->year->text().toStdString();
    string trailer = this->trailer->text().toStdString();
    try{

        Validator::validate_title(title);
        Validator::validate_title(new_title);
        Validator::validate_trailer(trailer);
        this->service.update_title_service(title,stoi(year),trailer, new_title);
    }catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    this->populateList();
    int lastel = this->service.GetRepo().size()-1;
    this->moviesList->setCurrentRow(lastel);
}
void AdminMode::updateGenre() {
    string title = this->title->text().toStdString();
    string new_genre = this->genre->text().toStdString();
    string year = this->year->text().toStdString();
    string trailer = this->trailer->text().toStdString();
    try{

        Validator::validate_title(title);
        Validator::validate_genre(new_genre);
        Validator::validate_trailer(trailer);
        this->service.update_genre_service(title,stoi(year),trailer, new_genre);
    }catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    this->populateList();
    int lastel = this->service.GetRepo().size()-1;
    this->moviesList->setCurrentRow(lastel);
}
void AdminMode::updateYear() {
    string title = this->title->text().toStdString();
    string new_year = this->year->text().toStdString();
    string year = this->year->text().toStdString();
    string trailer = this->trailer->text().toStdString();
    try{

        Validator::validate_title(title);
        Validator::validate_trailer(trailer);
        this->service.update_year_service(title,stoi(year),trailer, stoi(new_year));
    }catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    this->populateList();
    int lastel = this->service.GetRepo().size()-1;
    this->moviesList->setCurrentRow(lastel);
}
void AdminMode::updateLikes() {
    string title = this->title->text().toStdString();
    string new_likes = this->likes->text().toStdString();
    string year = this->year->text().toStdString();
    string trailer = this->trailer->text().toStdString();
    try{

        Validator::validate_title(title);
        Validator::validate_trailer(trailer);
        this->service.update_likes_service(title,stoi(year),trailer, stoi(new_likes));
    }catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    this->populateList();
    int lastel = this->service.GetRepo().size()-1;
    this->moviesList->setCurrentRow(lastel);
}
void AdminMode::updateTrailer() {
    string title = this->title->text().toStdString();
    string new_trailer = this->trailer->text().toStdString();
    string year = this->year->text().toStdString();
    string trailer = this->trailer->text().toStdString();
    try{

        Validator::validate_title(title);
        Validator::validate_trailer(new_trailer);
        Validator::validate_trailer(trailer);
        this->service.update_trailer_service(title,stoi(year),trailer, new_trailer);
    }catch(...)
    {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    this->populateList();
    int lastel = this->service.GetRepo().size()-1;
    this->moviesList->setCurrentRow(lastel);
}
AdminMode::~AdminMode(){}

void AdminMode::undo() {
    try{
        this->service.undoAdminMode();
        this->populateList();
    }catch(...){
        QMessageBox::critical(this,"Error","There are no more undos!");
        return;
    }
}
void AdminMode::redo(){
    try{
        this->service.redoAdminMode();
        this->populateList();
    }catch(...){
        QMessageBox::critical(this,"Error","There are no more redos!");
        return;
    }
}