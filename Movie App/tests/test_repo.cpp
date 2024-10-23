//
// Created by Teodora Schiau on 23.03.2024.
//

#include "test_repo.h"
#include "exceptions.h"
#include "Repository.h"
#include "DynamicArray.h"
#include <iostream>
#include <assert.h>
void Test_Repo::test_existance() {


    Repository repo, user_repo;
    repo.init_repo();
    assert(user_repo.GetSizeUser()==0);
    user_repo.add_element_user("Liceenii","comedy",1999,234,"https://www.comedyflicks.com/liceenii");
    int posit = user_repo.check_existance_user("Liceenii",1999,"https://www.comedyflicks.com/liceenii");
    assert(posit == 0);
    int pos = repo.check_existance("Shadow of Serenity",2000,"https://www.fantasyflicks.com/shadow-of-serenity");
    assert(pos==0);
    int posi = repo.check_existance("Shadw of Serenity",2000,"https://www.fantasyflicks.com/shadow-of-serenity");
    assert(posi==-1);
}
void Test_Repo::test_add()
{
    Repository repo;
    repo.init_repo();
    assert(repo.GetSize()==10);
    assert(repo[0].getTrailer()== "https://www.fantasyflicks.com/shadow-of-serenity");
    assert(repo[0].getTitle()=="Shadow of Serenity");
    assert(repo[0].getGenre()=="Thriller");
    assert(repo[0].getYear()==2000);
    assert(repo[0].getLikes()==213);
    repo.add_element("After","romantic",2024,17643,"https://www.romanceflicks.com/after");
    assert(repo.GetSize()==11);
    assert(repo[10].getTrailer()== "https://www.romanceflicks.com/after");
    assert(repo[10].getTitle()=="After");
    assert(repo[10].getGenre()=="romantic");
    assert(repo[10].getYear()==2024);
    assert(repo[10].getLikes()==17643);
    int pos = repo.check_existance("After",2024,"https://www.romanceflicks.com/after");
    assert(pos==10);

}
void Test_Repo::test_delete() {

    Repository repo, user_repo;
    assert(user_repo.GetSizeUser()==0);
    user_repo.add_element_user("Liceenii","comedy",1999,234,"https://www.comedyflicks.com/liceenii");
    assert(user_repo.GetSizeUser()==1);
    int posit = user_repo.check_existance_user("Liceenii",1999,"https://www.comedyflicks.com/liceenii");
    int positr = user_repo.check_existance_user("Licenii",1999,"https://www.comedyflicks.com/liceenii");
    assert(posit == 0);
    assert(positr == -1);
    try{
        user_repo.delete_element_user("Liceii",1999,"https://www.comedyflicks.com/liceenii");
        user_repo.delete_element_user("Liceenii",1999,"https://www.comedyflicks.com/liceenii");
        assert(false);
    }
    catch(ExceptionRepo&)
    {
        assert(true);
    }
    assert(user_repo.GetSizeUser()==1);
    user_repo.GetDynArrUser();
    repo.init_repo();
    assert(repo.GetSize()==10);
    assert(repo.GetSizeUser()==0);
    repo.delete_element("Shadow of Serenity",2000,"https://www.fantasyflicks.com/shadow-of-serenity");
    assert(repo.GetSize()==9);
    assert(repo[0].getTrailer()== "https://www.adventurecinema.com/echoes-of-eternity");
    assert(repo[0].getTitle()=="Echoes of Eternity");
    assert(repo[0].getGenre()=="Romantic");
    assert(repo[0].getYear()==2010);
    assert(repo[0].getLikes()==43566);

}
void Test_Repo::test_update() {

    Repository repo;
    repo.init_repo();
    assert(repo.GetSize()==10);
    repo.update_title("Shadow of Serenity",2000,"https://www.fantasyflicks.com/shadow-of-serenity", "Harry Potter");
    assert(repo[0].getTitle()=="Harry Potter");
    repo.update_genre("Harry Potter",2000,"https://www.fantasyflicks.com/shadow-of-serenity", "fantasy");
    assert(repo[0].getGenre()=="fantasy");
    repo.update_year("Harry Potter",2000,"https://www.fantasyflicks.com/shadow-of-serenity", 2004);
    assert(repo[0].getYear()==2004);
    repo.update_likes("Harry Potter",2004,"https://www.fantasyflicks.com/shadow-of-serenity", 5);
    assert(repo[0].getLikes()==5);
    repo.update_trailer("Harry Potter",2004,"https://www.fantasyflicks.com/shadow-of-serenity", "nu_stiu_nimic");
    assert(repo[0].getTrailer()=="nu_stiu_nimic");
    try {
        repo.update_trailer("Harry Potter", 2004, "https://www.fantasyflicks.com/shadow-of-serenity", "nu_stiu_nimic");
        assert(false);
    } catch(ExceptionRepo&){
        assert(true);
    }
    repo.GetDynArr();

}
void Test_Repo::test_all(){
    test_add();
    test_delete();
    test_update();
    test_existance();
}