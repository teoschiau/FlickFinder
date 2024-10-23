//
// Created by Teodora Schiau on 25.03.2024.
//

#include "test_service.h"
#include "service.h"
#include "exceptions.h"
#include <assert.h>


void Test_Service::test_add() {

    Repository repo, repo_user;
    Service service(repo,repo_user);
    service.add_element_service("Harry Potter","fantasy",2024,134,"www.harry_potter.ro");
    try{
        service.add_element_service("Harry Potter","fantasy",2024,134,"www.harry_potter.ro");
        assert(false);
    }catch(ExceptionRepo&)
    {
        assert(true);
    }

    assert(service.GetSize()==1);
    service.add_element_user_service("Harry Potter","fantasy",2024,134,"www.harry_potter.ro");
    assert(service.GetUserSize()==1);
}
void Test_Service::test_delete() {


    Repository repo, repo_user;
    Service service(repo, repo_user);
    service.add_element_service("Harry Potter","fantasy",2024,134,"www.harry_potter.ro");
    try{
        service.delete_element_service("Hary Potter",2024,"www.harry_potter.ro");
        assert(false);
    }catch(ExceptionRepo&)
    {
        assert(true);
    }
    service.delete_element_service("Harry Potter",2024,"www.harry_potter.ro");
    service.GetRepo();
    service.add_element_user_service("Harry Potter","fantasy",2024,134,"www.harry_potter.ro");
    assert(service.GetUserSize()==1);

    try{
        service.delete_element_user_service("Hary Potter", 2024,"www.harry_potter.ro");
        service.delete_element_user_service("Harry Potter", 2024,"www.harry_potter.ro");
        assert(false);
    }catch(ExceptionRepo&)
    {
        assert(true);
    }
    assert(service.GetUserSize()==1);
    service.GetUserRepo();


}
void Test_Service::test_update() {
    Repository repo, repo_user;
    Service service(repo, repo_user);
    service.add_element_service("Harry Potter","fantasy",2024,134,"www.harry_potter.ro");
    try {
        service.update_title_service("Hary Potter", 2024, "www.harry_potter.ro", "Narnia");
        assert(false);
    }
    catch(ExceptionRepo&){
        assert(true);
    }
    service.update_title_service("Harry Potter",2024,"www.harry_potter.ro","Narnia");
    try{
        service.update_genre_service("Narnia",204,"www.harry_potter.ro","Childs");
        assert(false);
    }catch(ExceptionRepo&)
    {
        assert(true);
    }
    service.update_genre_service("Narnia",2024,"www.harry_potter.ro","Childs");
    try{
        service.update_year_service("Narnia",2024,"www.hay_potter.ro",2023);
        assert(false);
    }catch(ExceptionRepo&)
    {
        assert(true);
    }
    service.update_year_service("Narnia",2024,"www.harry_potter.ro",2023);
    try{
        service.update_likes_service("Naria",2023,"www.harry_potter.ro",22);
        assert(false);
    }catch(ExceptionRepo&)
    {
        assert(true);
    }
    service.update_likes_service("Narnia",2023,"www.harry_potter.ro",22);
    try{
        service.update_trailer_service("Narnia",203,"www.harry_potter.ro","eu");
        assert(false);
    }catch(ExceptionRepo&)
    {
        assert(true);
    }
    service.update_trailer_service("Narnia",2023,"www.harry_potter.ro","eu");
}

void Test_Service::test_all() {
    test_add();
    test_delete();
    test_update();
}



