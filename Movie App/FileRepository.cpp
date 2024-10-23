//
// Created by Teodora Schiau on 14.04.2024.
//

#include "FileRepository.h"
#include "exceptions.h"


FileRepo::FileRepo(std::string Filename) {
    this->Filename = Filename;
    this->repo = LoadData();
}

void FileRepo::add_element(std::string title, std::string genre, int year, int likes, std::string trailer) {
    int position;
    position = check_existance(title, year, trailer);
    if(position == -1)
    {
        Movie m(title, genre, year,likes,trailer);
        repo.push_back(m);
        WriteData(repo);
    }
    else
        throw ExceptionRepo("The element already exist!");
}

void FileRepo::delete_element(string title, int year, string trailer) {
    int position;
    position = check_existance(title, year, trailer);
    if(position!= -1)
    {
        repo.erase(this->repo.begin() + position);
        WriteData(repo);
    }
    else
        throw ExceptionRepo("The element doesn't exist!");
}

void FileRepo::update_title(string title, int year, string trailer, string new_title) {
    int position;
    position = check_existance(title,year,trailer);
    if(position!=-1)
    {
        int likes = this->repo[position].getLikes();
        string gen = this->repo[position].getGenre();
        Movie m(new_title,gen,year,likes,trailer);
        this->repo[position]=m;
        WriteData(repo);
    }
    else
        throw ExceptionRepo("The movie doesn't exist!");
}
void FileRepo::update_genre(string title, int year, string trailer, string new_genre) {
    int position;
    position = check_existance(title,year,trailer);
    if(position!=-1)
    {
        int likes = this->repo[position].getLikes();
        Movie m(title,new_genre,year,likes,trailer);
        this->repo[position]=m;
        WriteData(repo);
    }
    else
        throw ExceptionRepo("The movie doesn't exist!");
}
void FileRepo::update_year(string title, int year, string trailer, int new_year) {
    int position;
    position = check_existance(title,year,trailer);
    if(position!=-1)
    {
        int likes = this->repo[position].getLikes();
        string gen = this->repo[position].getGenre();
        Movie mov(title,gen,new_year,likes,trailer);
        this->repo[position]=mov;
        WriteData(repo);

    }
    else
        throw ExceptionRepo("The movie doesn't exist!");
}
void FileRepo::update_likes(string title, int year, string trailer, int new_likes) {
    int position;
    position = check_existance(title,year,trailer);
    if(position!=-1)
    {
        string gen = this->repo[position].getGenre();
        Movie m(title,gen,year,new_likes,trailer);
        this->repo[position]=m;
        WriteData(repo);
    }
    else
        throw ExceptionRepo("The movie doesn't exist!");
}
void FileRepo::update_trailer(string title, int year, string trailer, string new_trailer) {
    int position;
    position = check_existance(title,year,trailer);
    if(position!=-1)
    {
        int likes = this->repo[position].getLikes();
        string gen = this->repo[position].getGenre();
        Movie m(title,gen,year,likes,new_trailer);
        this->repo[position]=m;
        WriteData(repo);
    }
    else
        throw ExceptionRepo("The movie doesn't exist!");
}
void FileRepo::WriteData(vector<Movie> filerepo) {
    ofstream g(this->Filename);
    for(auto CurrentElement: filerepo)
        g << CurrentElement<<"\n";

}

vector<Movie> FileRepo::LoadData()
{
    ifstream f(this->Filename);
    vector<Movie> repo;
    Movie Currentelement;
    while (f >> Currentelement)
    {
        repo.push_back(Currentelement);
    }
    return repo;
}
vector<Movie> &FileRepo::GetDynArr() {
    return repo;
}




