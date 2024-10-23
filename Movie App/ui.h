//
// Created by Teodora Schiau on 25.03.2024.
//

#ifndef OOP_A4_5_916_SCHIAU_TEODORA_UI_H
#define OOP_A4_5_916_SCHIAU_TEODORA_UI_H

#include "service.h"
#include "validator.h"
#include "WriteFile.h"

class UI{
private:
    Service& ui;
    Validator& validator;
    WriteFile* wf;
public:

    UI(Service& ui, Validator& validator);
    void start();
    void open();
    void delete_admin();
    void add_admin();
    void print_menu();
    void print_menu_user();
    void display_movies();
    void update_movie();
    void print_update();
    void add_user();
    void delete_user();
    void display_movies_user();
};
#endif //OOP_A4_5_916_SCHIAU_TEODORA_UI_H
