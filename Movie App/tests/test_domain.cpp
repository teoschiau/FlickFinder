//
// Created by Teodora Schiau on 23.03.2024.
//

#include "test_domain.h"
#include "domain.h"
#include <assert.h>

void Test_Domain::Test_Getters() {
    Movie m("Metropolis", "psychology", 2007, 12345, "www.metropolis");
    assert(m.getTitle() == "Metropolis");
    assert(m.getGenre() == "psychology");
    assert(m.getYear() == 2007);
    assert(m.getLikes() == 12345);
    assert(m.getTrailer()=="www.metropolis");
}

void Test_Domain::Test_Setters() {
    Movie m("Metropolis", "psychology", 2007, 12345, "www.metropolis");
    try {
        m.setTitle("");
        assert(false);
    }catch(const exception& e){}
    m.setTitle("Star Wars");
    assert(m.getTitle() == "Star Wars");

    try {
        m.setGenre("");
        assert(false);
    }catch(const exception& e){}
    m.setGenre("action");
    assert(m.getGenre() == "action");

    try {
        m.setYear(-23);
        assert(false);
    }catch(const exception& e){}
    m.setYear(2012);
    assert(m.getYear() == 2012);

    m.setLikes(12346);
    assert(m.getLikes() == 12346);

    try {
        m.setTrailer("");
        assert(false);
    }catch(const exception& e){}
    m.setTrailer("https://www.metropolis");
    assert(m.getTrailer()=="https://www.metropolis");
}
void Test_Domain::Test_all() {
    Test_Getters();
    Test_Setters();
}