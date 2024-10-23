//
// Created by Teodora Schiau on 23.03.2024.
//

#include "Repository.h"
#include "exceptions.h"
#include <algorithm>


Repository::Repository() {
}

Movie Repository::operator[](int position)
{
    return this->repo.operator[](position);
}

int Repository::check_existance(string title, int year, string thriler) {

    auto iter = std::find_if(this->repo.begin(), this->repo.end(), [&](const Movie& item) {
        return (item.getTitle() == title && item.getYear() == year && item.getTrailer() == thriler);
    });

    if (iter != this->repo.end()) {
        return std::distance(this->repo.begin(), iter);
    }
    return -1;
}

void Repository::add_element(string title, string genre, int year, int likes, string trailer) {
    int position;
    position = check_existance(title, year, trailer);
    if(position == -1)
    {
        Movie m(title, genre, year,likes,trailer);
        this->repo.push_back(m);
    }
    else
        throw ExceptionRepo("The element already exist!\n");
}

void Repository::add_element_user(string title, string genre, int year, int likes, string trailer) {

    Movie m(title, genre, year,likes,trailer);
    this->repo_user.push_back(m);
}

void Repository::init_repo() {

    add_element("Shadow of Serenity","Thriller", 2000,213,"https://www.fantasyflicks.com/shadow-of-serenity");
    add_element("Echoes of Eternity","Romantic", 2010,43566,"https://www.adventurecinema.com/echoes-of-eternity");
    add_element("Mirage","Adventure", 2007,435,"https://www.mysterymovies.net/midnight-mirage");
    add_element("Whispers","Adventure", 1999,54765,"https://www.horrorhaven.com/whispers-in-the-dark");
    add_element("Forgotten","Comedy",2020,4534,"https://www.dreamlandcinemas.com/forgotten-dreams");
    add_element("Starlight","Horror",2023,435,"https://www.scifispectacle.com/starlight-symphony");
    add_element("Horizon","Drama",2004,676,"https://www.thrillermadness.com/crimson-horizon");
    add_element("Enigma","Comedy",2003,46,"https://www.enigmamoviehub.com/enigmas-end");
    add_element("Twilight","Romantic",2007,345,"https://www.neonnightmares.com/neon-twilight");
    add_element("Quantum Quest","Drama",2024,4356,"https://www.questflicks.net/quantum-quest");

}

void Repository::delete_element(string title, int year, string trailer) {
    int position;
    position = check_existance(title, year, trailer);
    if(position!= -1)
    {
        this->repo.erase(this->repo.begin() + position);
    }
    else
        throw ExceptionRepo("The element doesn't exist!\n");
}

int Repository::check_existance_user(string title, int year, string thriler) {
    auto iter = std::find_if(this->repo_user.begin(), this->repo_user.end(),[&](const Movie& item){
        return (item.getTitle() == title && item.getYear() == year && item.getTrailer() == thriler);
    });

    if(iter != this->repo_user.end()){
        return std::distance(this->repo_user.begin(), iter);
    }
    return -1;
}

void Repository::delete_element_user(string title, int year, string trailer) {
    int position;
    position = check_existance_user(title, year, trailer);
    if(position!= -1)
    {
        this->repo_user.erase(this->repo_user.begin() + position);
    }
    else
        throw ExceptionRepo("The element doesn't exist!\n");
}

vector<Movie>& Repository::GetDynArr() {
    return this->repo;
}
vector<Movie>& Repository::GetDynArrUser() {
    return this->repo_user;
}
int Repository::GetSizeUser() {
    return this->repo_user.size();
}
int Repository::GetSize() {
    return this->repo.size();
}

void Repository::update_title(string title, int year, string trailer, string new_title) {
    int position;
    position = check_existance(title,year,trailer);
    if(position!=-1)
    {
        int likes = this->repo[position].getLikes();
        string gen = this->repo[position].getGenre();
        Movie m(new_title,gen,year,likes,trailer);
        this->repo[position]=m;
    }
    else
        throw ExceptionRepo("The movie doesn't exist!\n");
}
void Repository::update_genre(string title, int year, string trailer, string new_genre) {
    int position;
    position = check_existance(title,year,trailer);
    if(position!=-1)
    {
        int likes = this->repo[position].getLikes();
        Movie m(title,new_genre,year,likes,trailer);
        this->repo[position]=m;
    }
    else
        throw ExceptionRepo("The movie doesn't exist!\n");
}
void Repository::update_year(string title, int year, string trailer, int new_year) {
    int position;
    position = check_existance(title,year,trailer);
    if(position!=-1)
    {
        int likes = this->repo[position].getLikes();
        string gen = this->repo[position].getGenre();
        Movie mov(title,gen,new_year,likes,trailer);
        this->repo[position]=mov;

    }
    else
        throw ExceptionRepo("The movie doesn't exist!\n");
}
void Repository::update_likes(string title, int year, string trailer, int new_likes) {
    int position;
    position = check_existance(title,year,trailer);
    if(position!=-1)
    {
        string gen = this->repo[position].getGenre();
        Movie m(title,gen,year,new_likes,trailer);
        this->repo[position]=m;
    }
    else
        throw ExceptionRepo("The movie doesn't exist!\n");
}
void Repository::update_trailer(string title, int year, string trailer, string new_trailer) {
    int position;
    position = check_existance(title,year,trailer);
    if(position!=-1)
    {
        int likes = this->repo[position].getLikes();
        string gen = this->repo[position].getGenre();
        Movie m(title,gen,year,likes,new_trailer);
        this->repo[position]=m;
    }
    else
        throw ExceptionRepo("The movie doesn't exist!\n");
}
Movie Repository::getMovie(std::string title, int year, std::string trailer) {
    int pos = check_existance(title,year, trailer);
    if(pos!=-1)
        return this->repo[pos];
    else
        throw ExceptionRepo("The movie doesn't exist!\n");
}

