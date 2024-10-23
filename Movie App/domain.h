//
// Created by Teodora Schiau on 09.04.2024.
//

#ifndef OOP_A6_7_916_SCHIAU_TEODORA_DOMAIN_H
#define OOP_A6_7_916_SCHIAU_TEODORA_DOMAIN_H
#include <string>
#include <vector>

using namespace std;

class Movie{
private:
    string title;
    string genre;
    int year;
    int number_of_likes;
    string trailer;

public:
    ///constructor
    Movie();

    /// copy contructor
    /// \param title the title of the movie
    /// \param genre the genre of the movie
    /// \param year the year when the movie was released
    /// \param number_of_likes number of likes of the movie
    /// \param trailer the link to the trailer
    Movie(string title,string genre,int year,int number_of_likes, string trailer);

    /// title getter
    /// \return the title of the movie
    const string& getTitle() const {return this->title;}

    /// genre getter
    /// \return the genre of the movie
    const string& getGenre() const {return this->genre;}

    /// year getter
    /// \return the year when the movie was released
    const int& getYear() const {return this->year;}

    /// likes getter
    /// \return the number of likes
    const int& getLikes() const {return this->number_of_likes;}//return (*this).number_of_likes

    /// trailer getter
    /// \return
    const string& getTrailer() const {return this->trailer;}

    /// title setter - sets a new title to a movie
    /// \param new_title
    void setTitle(string new_title);

    /// genre setter - sets a new genre to a movie
    /// \param new_genre
    void setGenre(string new_genre);

    /// trailer setter - sets a new trailer to a movie
    /// \param new_trailer
    void setTrailer(string new_trailer);

    /// year setter - changes the year to a movie
    /// \param new_year
    void setYear(int new_year);

    ///likes setter
    /// \param new_likes
    void setLikes(int new_likes);

    static vector<string> tokenize(string str, char delimiter);

    friend ostream& operator<<(ostream&, const Movie&);

    friend istream& operator>>(istream&, Movie&);

    Movie& operator=(const Movie &m);
};
#endif //OOP_A6_7_916_SCHIAU_TEODORA_DOMAIN_H
