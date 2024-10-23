//
// Created by Teodora Schiau on 23.03.2024.
//

#ifndef OOP_A4_5_916_SCHIAU_TEODORA_REPOSITORY_H
#define OOP_A4_5_916_SCHIAU_TEODORA_REPOSITORY_H
#include "DynamicArray.h"
#include "domain.h"
class Repository{
protected:
    vector<Movie> repo;
    vector<Movie> repo_user;
public:
    ///constructor
    //Repository(vector<Movie> da, vector<Movie> da1);

    ///destructor
    //~Repository();

    Repository();

    ///function that initialize the repository with 10 entries
    void init_repo();

    /// function that checks the existence of a movie in the array
    /// \param title of the movie
    /// \param year of the movie
    /// \param trailer of the movie
    /// \return the position of the element if found, -1 otherwise
    int check_existance(string title,int year,string trailer);

    int check_existance_user(string title, int year, string thriler);

    /// function that adds an element to the array
    /// \param title of the movie
    /// \param genre of the movie
    /// \param year of the movie
    /// \param likes of the movie
    /// \param trailer of the movie
    /// \return 1 if the element is added, 0 otherwise
    virtual void add_element(string title, string genre, int year, int likes, string trailer);

    /// function that deletes an element from the array
    /// \param title of the movie
    /// \param year of the movie
    /// \param trailer of the movie
    /// \return 1 if the element is added, 0 otherwise
    virtual void delete_element(string title,int year,string trailer);
    virtual void delete_element_user(string title,int year,string trailer);

    ///function that gets the size of the array and pass it further
    virtual int GetSize();

    ///function that gets the size of the array and pass it further
    virtual int GetSizeUser();

    virtual void add_element_user(string title, string genre, int year, int likes, string trailer);

    /// function that passes the array further
    /// \return a dynamic array
    virtual vector<Movie>& GetDynArr();

    virtual vector<Movie>& GetDynArrUser();

    /// function that updates the title of a movie
    /// \param title of the movie
    /// \param year of the movie
    /// \param trailer of the movie
    /// \param new_title the title that is going to be replaced with
    /// \return 1 if the element is added, 0 otherwise
    virtual void update_title(string title,int year,string trailer, string new_title);
    virtual void update_genre(string title, int year, string trailer, string new_genre);
    virtual void update_year(string title, int year, string trailer, int new_year);
    virtual void update_likes(string title, int year, string trailer, int new_likes);
    virtual void update_trailer(string title, int year, string trailer, string new_trailer);
    virtual Movie operator[](int position);
    Movie getMovie(string title,int year, string trailer);
};
#endif //OOP_A4_5_916_SCHIAU_TEODORA_REPOSITORY_H
