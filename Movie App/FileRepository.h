//
// Created by Teodora Schiau on 14.04.2024.
//

#ifndef OOP_A6_7_916_SCHIAU_TEODORA_FILEREPOSITORY_H
#define OOP_A6_7_916_SCHIAU_TEODORA_FILEREPOSITORY_H

#include "Repository.h"
#include "exceptions.h"
#include <fstream>
#include <iostream>
#include <ostream>
using namespace std;

class FileRepo: public Repository{
public:
    FileRepo(){};
    ///constructor
    FileRepo(string Filename);

    /// function that adds an element to the array
    /// \param title of the movie
    /// \param genre of the movie
    /// \param year of the movie
    /// \param likes of the movie
    /// \param trailer of the movie
    /// \return 1 if the element is added, 0 otherwise
    void add_element(string title, string genre, int year, int likes, string trailer) override;

    /// function that deletes an element from the array
    /// \param title of the movie
    /// \param year of the movie
    /// \param trailer of the movie
    /// \return 1 if the element is added, 0 otherwise
    void delete_element(string title,int year,string trailer) override;

    /// function that passes the array further
    /// \return a dynamic array
    vector<Movie>& GetDynArr() override;

    /// function that updates the title of a movie
    /// \param title of the movie
    /// \param year of the movie
    /// \param trailer of the movie
    /// \param new_title the title that is going to be replaced with
    /// \return 1 if the element is added, 0 otherwise
    void update_title(string title,int year,string trailer, string new_title) override;
    void update_genre(string title, int year, string trailer, string new_genre) override;
    void update_year(string title, int year, string trailer, int new_year) override;
    void update_likes(string title, int year, string trailer, int new_likes) override;
    void update_trailer(string title, int year, string trailer, string new_trailer) override;

protected:
    string Filename;

    ///function that reads data from a file
    vector<Movie> LoadData();

    ///function that writes data in a file
    virtual void WriteData(vector<Movie> filerepo);
    Movie GetElement(int position);
};
#endif //OOP_A6_7_916_SCHIAU_TEODORA_FILEREPOSITORY_H
