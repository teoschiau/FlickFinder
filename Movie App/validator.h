//
// Created by Teodora Schiau on 25.03.2024.
//

#ifndef OOP_A4_5_916_SCHIAU_TEODORA_VALIDATOR_H
#define OOP_A4_5_916_SCHIAU_TEODORA_VALIDATOR_H
#pragma once
#include <string>
using namespace std;

class Validator{
public:
    /// function that validates the title of a movie
    /// \param title the string inputed for title
    /// \return true if the title is valid, false otherwise
    static bool validate_title(string title);

    /// function that validates the genre of a movie
    /// \param genre he string inputed for genre
    /// \return true if the genre is valid, false otherwise
    static bool validate_genre(string genre);

    /// function that validates the year and transforms the string into a int
    /// \param year the string
    /// \return the int
    static int validate_year(string year);

    /// function that validates the number of likes and transforms the string into a int
    /// \param likes the string
    /// \return the int
    static int validate_likes(string likes);

    /// function that validates the trailer of a movie
    /// \param trailer he string inputed for the trailer
    /// \return true if is valid, false otherwise
    static bool validate_trailer(string trailer);
};

#endif //OOP_A4_5_916_SCHIAU_TEODORA_VALIDATOR_H
