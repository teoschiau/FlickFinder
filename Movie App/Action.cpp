//
// Created by Teodora Schiau on 29.05.2024.
//

#include "Action.h"
AddAction::AddAction(Repository &repo, Movie addedMovie):repo{repo} {
    this->addedMovie = addedMovie;
}

void AddAction::executeUndo() {
    this->repo.delete_element(addedMovie.getTitle(),addedMovie.getYear(),addedMovie.getTrailer());
}
void AddAction::executeRedo() {
    this->repo.add_element(addedMovie.getTitle(),addedMovie.getGenre(),addedMovie.getYear(),addedMovie.getLikes(),addedMovie.getTrailer());
}
DeleteAction::DeleteAction(Repository &repo, Movie deletedMovie):repo{repo} {
    this->deletedMovie = deletedMovie;
}
void DeleteAction::executeUndo() {
    this->repo.add_element(deletedMovie.getTitle(),deletedMovie.getGenre(),deletedMovie.getYear(),deletedMovie.getLikes(),deletedMovie.getTrailer());
}
void DeleteAction::executeRedo() {
    this->repo.delete_element(deletedMovie.getTitle(),deletedMovie.getYear(),deletedMovie.getTrailer());
}

UpdateGenderAction::UpdateGenderAction(Repository &repo, Movie oldupdatedMovie, Movie newupdateMovie):repo{repo} {
    this->oldupdatedMovie = oldupdatedMovie;
    this->newupdatedMovie = newupdateMovie;
}

void UpdateGenderAction::executeUndo() {
    this->repo.update_genre(oldupdatedMovie.getTitle(),oldupdatedMovie.getYear(),oldupdatedMovie.getTrailer(),oldupdatedMovie.getGenre());
}
void UpdateGenderAction::executeRedo() {
    this->repo.update_genre(newupdatedMovie.getTitle(),newupdatedMovie.getYear(),newupdatedMovie.getTrailer(),newupdatedMovie.getGenre());
}
UpdatedLikesAction::UpdatedLikesAction(Repository &repo, Movie oldupdatedMovie, Movie newupdateMovie):repo{repo} {
    this->oldupdatedMovie = oldupdatedMovie;
    this->newupdatedMovie = newupdateMovie;
}

void UpdatedLikesAction::executeUndo() {
    this->repo.update_likes(oldupdatedMovie.getTitle(),oldupdatedMovie.getYear(),oldupdatedMovie.getTrailer(),oldupdatedMovie.getLikes());
}
void UpdatedLikesAction::executeRedo() {
    this->repo.update_likes(newupdatedMovie.getTitle(),newupdatedMovie.getYear(),newupdatedMovie.getTrailer(),newupdatedMovie.getLikes());
}
AddActionUser::AddActionUser(Repository &repo, Movie addedMovie):repo{repo} {
    this->addedMovie = addedMovie;
}

void AddActionUser::executeUndo() {
    this->repo.delete_element_user(addedMovie.getTitle(),addedMovie.getYear(),addedMovie.getTrailer());
}
void AddActionUser::executeRedo() {
    this->repo.add_element_user(addedMovie.getTitle(),addedMovie.getGenre(),addedMovie.getYear(),addedMovie.getLikes(),addedMovie.getTrailer());
}
DeleteActionUser::DeleteActionUser(Repository &repo, Movie deletedMovie):repo{repo} {
    this->deletedMovie = deletedMovie;
}
void DeleteActionUser::executeUndo() {
    this->repo.add_element_user(deletedMovie.getTitle(),deletedMovie.getGenre(),deletedMovie.getYear(),deletedMovie.getLikes(),deletedMovie.getTrailer());
}
void DeleteActionUser::executeRedo() {
    this->repo.delete_element_user(deletedMovie.getTitle(),deletedMovie.getYear(),deletedMovie.getTrailer());
}
