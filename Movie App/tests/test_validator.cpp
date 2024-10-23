//
// Created by Teodora Schiau on 25.03.2024.
//

#include "test_validator.h"
#include "exceptions.h"
#include "validator.h"
#include <assert.h>

void Test_Validator::test_title(){
    Validator* validator = new Validator();
    try{
        validator->validate_title("");
    }catch(ExceptionsValidator&){}

    assert(validator->validate_title("Eu")==true);
    delete validator;
}
void Test_Validator::test_genre() {
    Validator* validator = new Validator();
    try{
        validator->validate_genre("12");
        validator->validate_genre("12arg");
    }catch(ExceptionsValidator&){}

    assert(validator->validate_genre("romantic")==true);
    delete validator;
}
void Test_Validator::test_likes() {
    Validator* validator = new Validator();
    try{
        validator->validate_likes("Eu74");
    }catch(ExceptionsValidator&){}
    assert(validator->validate_likes("100")==100);
    delete validator;
}
void Test_Validator::test_year() {
    Validator* validator = new Validator();
    assert(validator->validate_year("2024")==2024);
    try{
        validator->validate_year("Eu74");
    }catch(ExceptionsValidator&){}

    delete validator;
}
void Test_Validator::test_trailer(){
    Validator* validator = new Validator();
    try{
        assert(validator->validate_trailer("https//")==false);
        assert(validator->validate_trailer("https//gsdfghjsjefr")==false);
    }catch(ExceptionsValidator&){}
    assert(validator->validate_trailer("https://filme_seriale online")==true);
    delete validator;
}
void Test_Validator::test_all()
{
    test_title();
    test_genre();
    test_likes();
    test_year();
    test_trailer();

}