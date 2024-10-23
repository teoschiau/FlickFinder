//
// Created by Teodora Schiau on 09.04.2024.
//

#include "domain.h"
#include <cstring>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

Movie::Movie() {}

Movie::Movie(string title, string genre,int year, int nr_of_likes, string trailer):
        title{title}, genre{genre}, year{year}, number_of_likes{nr_of_likes}, trailer{trailer}{
}

void Movie::setTitle(string new_title)
{
    if(new_title == "")
        throw std::invalid_argument{"The title must contain a string!"};
    this->title = new_title;
}

void Movie::setGenre(string new_genre)
{
    if(new_genre == "")
        throw std::invalid_argument{"The genre must contain a string!"};
    this->genre = new_genre;
}

void Movie::setTrailer(string new_trailer)
{
    if(new_trailer == "")
        throw std::invalid_argument{"The trailer must contain a link!"};
    this->trailer = new_trailer;
}

void Movie::setYear(int new_year)
{
    if (new_year < 0)
        throw std::invalid_argument{"The year must be > 0!"};
    this->year = new_year;
}

void Movie::setLikes(int new_likes)
{
    this->number_of_likes = new_likes;
}

vector<string>  Movie::tokenize(std::string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}
ostream &operator<<(ostream &output, const Movie &m) {
    output<<m.title<<","<<m.genre<<","<<m.year<<","<<m.number_of_likes<<","<<m.trailer;
    return output;
}

istream &operator>>(istream &input, Movie &m) {
    string line;
    getline(input,line);
    vector<string> tokens = Movie::tokenize(line,',');
    if(tokens.size()!=5)
        return input;
    m.title = tokens[0];
    m.genre = tokens[1];
    m.year = stoi(tokens[2]);
    m.number_of_likes = stoi(tokens[3]);
    m.trailer = tokens[4];
    //input>>m.title>>m.genre>>m.year>>m.number_of_likes>>m.trailer;
    return input;
}

Movie& Movie::operator=(const Movie &m) {
    this->title = m.title;
    this->genre = m.genre;
    this->year = m.year;
    this->number_of_likes = m.number_of_likes;
    this->trailer = m.trailer;
    return *this;
}