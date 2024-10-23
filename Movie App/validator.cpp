//
// Created by Teodora Schiau on 25.03.2024.
//

#include "validator.h"
#include "exceptions.h"
#include <ctype.h>
#include <string>
using namespace std;


bool Validator::validate_title(string title) {
    if(title == "")
        throw ExceptionsValidator("Invalid title!\n");
    else
        return true;
}
bool Validator::validate_genre(string genre) {
    for(char i : genre)
        if(isdigit(i))
            throw ExceptionsValidator("Invalid genre!\n");
    return true;
}
int Validator::validate_likes(string likes) {
    for(char i : likes)
        if(isalpha(i))
            throw ExceptionsValidator("Invalid number of likes!\n");
    int new_likes;
    new_likes = stoi(likes);
    return new_likes;
}
int Validator::validate_year(string year) {
    for(char i : year)
        if(isalpha(i))
            throw ExceptionsValidator("Invalid year!\n");
    int new_year;
    new_year = stoi(year);
    return new_year;
}
bool Validator::validate_trailer(std::string trailer) {
    if(trailer.length() < 10)
        throw ExceptionsValidator("Invalid trailer!\n");
    if(trailer[0] != 'h' || trailer[1] != 't' || trailer[2] != 't' || trailer[3] != 'p' ||
            trailer[4] != 's' || trailer[5] != ':' || trailer[6] != '/' || trailer[7] != '/')
        throw ExceptionsValidator("Invalid trailer!\n");
    return true;
}