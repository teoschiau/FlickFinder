//
// Created by Teodora Schiau on 25.03.2024.
//

#ifndef OOP_A4_5_916_SCHIAU_TEODORA_SERVICE_H
#define OOP_A4_5_916_SCHIAU_TEODORA_SERVICE_H

#include "Repository.h"
#include "FileRepository.h"
#include "Action.h"

class Service{
private:
    Repository& service;
    Repository& user_service;
    vector<Action*> undoAdmin;
    vector<Action*> redoAdmin;
    vector<Action*> undoUser;
    vector<Action*> redoUser;
public:
    void undoLastAction(std::vector<Action*>& currentUndoStack, std::vector<Action*>& currentRedoStack);
    void redoLastAction(std::vector<Action*>& currentUndoStack, std::vector<Action*>& currentRedoStack);
    void undoAdminMode();

    void redoAdminMode();

    void undoUserMode();

    void redoUserMode();

    ///constructor
    Service(Repository& repo, Repository&user_repo);

    ///destructor
    //~Service();

    /// function that adds the element to the service
    /// \param title of the new movie
    /// \param genre of the new movie
    /// \param year of the new movie
    /// \param likes of the new movie
    /// \param trailer of the new movie
    /// \return 1 if the element is added, 0 otherwise
    void add_element_service(string title, string genre, int year, int likes, string trailer);

    /// function that deletes the element from the array
    /// \param title of the movie
    /// \param year of the movie
    /// \param trailer of the movie
    /// \return 1 if the element is added, 0 otherwise
    void delete_element_service(string title, int year,string trailer);

    /// funtction that updates the movie by title
    /// \param title of the movie
    /// \param year of the movie
    /// \param trailer of the movie
    /// \param new_title the title that the movie is going to be replaced with
    /// \return 1 if the element is added, 0 otherwise
    void update_title_service(string title, int year,string trailer, string new_title);
    void update_genre_service(string title, int year,string trailer, string new_genre);
    void update_year_service(string title, int year,string trailer, int new_year);
    void update_likes_service(string title, int year,string trailer, int new_likes);
    void update_trailer_service(string title, int year,string trailer, string new_trailer);

    /// function that passes the list further
    /// \return the list
    vector<Movie> GetRepo();

    /// function that passes the watchlist of the user
    /// \return the list
    vector<Movie> GetUserRepo();

    vector<Movie> FilteredRepo(string genre);

    ///function that passes the size of the array further
    int GetSize();

    ///function that passes the size of the watch list further
    int GetUserSize();

    void add_element_user_service(string title, string genre, int year, int likes, string trailer);
    void delete_element_user_service(string title, int year,string trailer);
};
#endif //OOP_A4_5_916_SCHIAU_TEODORA_SERVICE_H
