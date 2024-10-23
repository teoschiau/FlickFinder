//
// Created by Teodora Schiau on 25.03.2024.
//

#include "service.h"
#include "exceptions.h"
#include <iostream>

Service::Service(Repository &repo, Repository &user_repo): service{repo}, user_service{user_repo}{

}

void Service::add_element_service(string title, string genre, int year, int likes, string trailer) {
    this->service.add_element(title,genre,year,likes, trailer);
    Movie newMovie{title,genre,year,likes,trailer};
    Action* currentAction = new AddAction(this->service, newMovie);
    this->undoAdmin.push_back(currentAction);
    this->redoAdmin.clear();
}


void Service::delete_element_service(string title, int year, string trailer) {
    Movie m = this->service.getMovie(title,year, trailer);
    Action* currentAction = new DeleteAction(this->service,m);
    this->undoAdmin.push_back(currentAction);
    this->redoAdmin.clear();
    this->service.delete_element(title, year, trailer);
}

void Service::update_title_service(string title, int year, string trailer, string new_title) {

    this->service.update_title(title, year, trailer, new_title);
}

void Service::update_genre_service(string title, int year, string trailer, string new_genre) {
    Movie old_movie = this->service.getMovie(title,year,trailer);
    Movie new_movie = Movie{title,new_genre,year,old_movie.getLikes(),trailer};
    this->service.update_genre(title, year, trailer, new_genre);
    Action* currentAction = new UpdateGenderAction(this->service,old_movie,new_movie);
    this->undoAdmin.push_back(currentAction);
    this->redoAdmin.clear();

}

void Service::update_year_service(string title, int year, string trailer, int new_year) {
    this->service.update_year(title, year, trailer, new_year);
}

void Service::update_likes_service(string title, int year, string trailer, int new_likes) {
    Movie old_movie = this->service.getMovie(title,year,trailer);
    Movie new_movie = Movie{title,old_movie.getGenre(),year,old_movie.getLikes(),trailer};

    this->service.update_likes(title, year, trailer, new_likes);
    Action* currentAction = new UpdatedLikesAction(this->service,old_movie,new_movie);
    this->undoAdmin.push_back(currentAction);
    this->redoAdmin.clear();
}

void Service::update_trailer_service(string title, int year, string trailer, string new_trailer) {
    this->service.update_trailer(title, year, trailer, new_trailer);
}

vector<Movie> Service::GetRepo() {
    return this->service.GetDynArr();
}

int Service::GetSize() {
    return this->service.GetSize();
}

vector<Movie> Service::GetUserRepo() {
    return this->user_service.GetDynArrUser();
}

int Service::GetUserSize() {
    return this->user_service.GetSizeUser();
}

void Service::add_element_user_service(string title, string genre, int year, int likes, string trailer) {
    Movie m{title,genre,year,likes,trailer};
    this->user_service.add_element_user(title, genre, year,likes, trailer);
    Action* currentAction = new AddActionUser(this->user_service, m);
    this->undoUser.push_back(currentAction);
    this->redoUser.clear();
}

void Service::delete_element_user_service(string title, int year, string trailer) {
    Movie m = this->service.getMovie(title,year, trailer);
    this->user_service.delete_element_user(title, year, trailer);
    Action* currentAction = new DeleteActionUser(this->user_service,m);
    this->undoUser.push_back(currentAction);
    this->redoUser.clear();
}

vector<Movie> Service::FilteredRepo(std::string genre) {
    if( genre == "All genres")
        return this->GetRepo();
    else
    {
        vector<Movie> element = GetRepo();
        vector<Movie> result;
        for(int i=0;i<=element.size();i++)
        {
            if(element[i].getGenre() == genre)
                result.push_back(element[i]);
        }
        return result;
    }
}
void Service::undoLastAction(std::vector<Action*> &currentUndoStack, std::vector<Action*> &currentRedoStack) {
    if (currentUndoStack.empty()) {
        throw ExceptionRepo("no more undos");
    }

    Action* currentAction = currentUndoStack.back();
    currentAction->executeUndo();
    currentRedoStack.push_back(currentAction);
    currentUndoStack.pop_back();
}

void Service::redoLastAction(std::vector<Action*> &currentUndoStack, std::vector<Action*> &currentRedoStack) {
    if (currentRedoStack.size() == 0) {
        throw ExceptionRepo("no more redos");
    }

    Action* currentAction = currentRedoStack.back();
    currentAction->executeRedo();
    currentUndoStack.push_back(currentAction);
    currentRedoStack.pop_back();
}

void Service::undoAdminMode() {
    this->undoLastAction(this->undoAdmin, this->redoAdmin);
}

void Service::redoAdminMode() {
    this->redoLastAction(this->undoAdmin, this->redoAdmin);
}

void Service::undoUserMode() {
    this->undoLastAction(this->undoUser, this->redoUser);
}

void Service::redoUserMode() {
    this->redoLastAction(this->undoUser, this->redoUser);
}








