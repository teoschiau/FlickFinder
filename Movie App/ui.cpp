//
// Created by Teodora Schiau on 25.03.2024.
//

#include "ui.h"
#include "validator.h"
#include <iostream>
#include "exceptions.h"

UI::UI(Service& ui, Validator &validator):ui{ui}, validator{validator}{}
void UI::print_menu() {
    cout<<"Press 1 to display all movies!\n";
    cout<<"Press 2 to add a movie!\n";
    cout<<"Press 3 to delete a movie!\n";
    cout<<"Press 4 to update a movie!\n";
    cout<<"Press 5 to exit!\n";
}
void UI::print_menu_user() {
    cout<<"Press 1 to display all movies in the watch list!\n";
    cout<<"Press 2 to add a movie in the watch list!\n";
    cout<<"Press 3 to delete a movie from the watch list!\n";
    cout<<"Press 4 to open the application!\n";
    cout<<"Press 5 to exit!\n";
}
void UI::print_update() {
    cout<<"Press 1 to update the title!\n";
    cout<<"Press 2 to update the genre!\n";
    cout<<"Press 3 to update the year!\n";
    cout<<"Press 4 to update the number of likes!\n";
    cout<<"Press 5 to update the trailer!\n";
    cout<<"Press 6 to exit!\n";
}
void UI::add_admin() {
    string title,genre,syear,slike,trailer;
    int year, likes;
    cout<<"Please enter the title of the movie:\n";
    cin>>title;
    cout<<"Please enter the genre of the movie:\n";
    cin>>genre;
    cout<<"Please enter the year of the movie:\n";
    cin>>syear;
    cout<<"Please enter how many likes the movie has:\n";
    cin>>slike;
    cout<<"Please enter the link to the trailer of the movie:\n";
    cin>>trailer;
    try{
        year = this->validator.validate_year(syear);
        likes = this->validator.validate_likes(slike);
        this->validator.validate_title(title);
        this->validator.validate_genre(genre);
        this->validator.validate_trailer(trailer);
        try{
            this->ui.add_element_service(title, genre, year, likes, trailer);
            cout << "The product was added successfully!\n";
        }catch(ExceptionRepo& ex){
            cout<<ex.what();
        }
    }catch(ExceptionsValidator& ex)
    {
        cout<<ex.what();
    }

}
void UI::display_movies() {
    int i;
    for(i=0;i<this->ui.GetSize();i++)
    {
        cout<<i+1<<". title: " <<this->ui.GetRepo()[i].getTitle()
        <<" genre: "<<this->ui.GetRepo()[i].getGenre()
        <<" year: "<<this->ui.GetRepo()[i].getYear()
        <<" number of likes: "<<this->ui.GetRepo()[i].getLikes()
        <<" link trailer: "<<this->ui.GetRepo()[i].getTrailer()<<"\n";
    }
    cout<<"\n";
}
void UI::delete_admin() {
    string title,syear,trailer;
    int year, likes;
    cout<<"Please enter the title of the movie:\n";
    cin>>title;
    cout<<"Please enter the year of the movie:\n";
    cin>>syear;
    cout<<"Please enter the link to the trailer of the movie:\n";
    cin>>trailer;
    try{
        year = this->validator.validate_year(syear);
        this->validator.validate_title(title);
        this->validator.validate_trailer(trailer);
        try{
            this->ui.delete_element_service(title,year,trailer);
            cout<<"Operation done successfully!\n";
        }catch(ExceptionRepo& ex){
            cout<<ex.what();
        }
    }catch(ExceptionsValidator& ex){
        cout<<ex.what();
    }
}
void UI::update_movie() {
    string title, syear, trailer, command, new_title, new_genre, new_trailer;
    int year, likes, runnings = 0, new_year, new_likes;
    cout << "Please enter the title of the movie:\n";
    cin >> title;
    cout << "Please enter the year of the movie:\n";
    cin >> syear;
    cout << "Please enter the link to the trailer of the movie:\n";
    cin >> trailer;
    try {
        year = this->validator.validate_year(syear);
        this->validator.validate_title(title);
        this->validator.validate_trailer(trailer);
        while (runnings == 0) {
            print_update();
            cin >> command;
            if (command == "1") {
                cout << "Please enter the title of the movie:\n";
                cin >> new_title;
                try {
                    this->ui.update_title_service(title, year, trailer, new_title);
                    cout << "Operation done successfully!\n";
                } catch (ExceptionRepo &ex) {
                    cout << ex.what();
                }
            } else if (command == "2") {
                cout << "Please enter the genre of the movie:\n";
                cin >> new_genre;
                try {
                    this->ui.update_genre_service(title, year, trailer, new_genre);
                    cout << "Operation done successfully!\n";
                } catch (ExceptionRepo &ex) {
                    cout << ex.what();
                }

            } else if (command == "3") {
                cout << "Please enter the year of the movie:\n";
                cin >> new_year;
                try {
                    this->ui.update_year_service(title, year, trailer, new_year);
                    cout << "Operation done successfully!\n";
                } catch (ExceptionRepo &ex) {
                    cout << ex.what();
                }
            } else if (command == "4") {
                cout << "Please enter the number of likes of the movie:\n";
                cin >> new_likes;
                try {
                    this->ui.update_likes_service(title, year, trailer, new_likes);
                    cout << "Operation done successfully!\n";

                } catch (ExceptionRepo &ex) {
                    cout << ex.what();
                }

            } else if (command == "5") {
                cout << "Please enter the trailer of the movie:\n";
                cin >> new_trailer;
                try {
                    this->ui.update_trailer_service(title, year, trailer, new_trailer);
                    cout << "Operation done successfully!\n";
                } catch (ExceptionRepo &ex) {
                    cout << ex.what();
                }
            } else if (command == "6")
                runnings = 1;
            else
                cout << "Invalid command!Try again!\n";
        }
    } catch (ExceptionsValidator &ex) {
        cout << ex.what();
    }
}
void UI::add_user() {
    int i;
    string genre, choose;
    cout<<"Please type a genre!\n";
    cin>>genre;
    try{
        this->validator.validate_genre(genre);
    }catch(ExceptionsValidator& ex){
        cout<<ex.what();
    }
    for(i=0;i<this->ui.GetSize();i++)
    {
        if(this->ui.GetRepo()[i].getGenre()==genre) {
            cout << i + 1 << ". title: " << this->ui.GetRepo()[i].getTitle()
                 << " genre: " << this->ui.GetRepo()[i].getGenre()
                 << " year: " << this->ui.GetRepo()[i].getYear()
                 << " number of likes: " << this->ui.GetRepo()[i].getLikes()
                 << " link trailer: " << this->ui.GetRepo()[i].getTrailer() << "\n";
        }
    }
    for(i=0;i<this->ui.GetSize();i++)
    {
        if(this->ui.GetRepo()[i].getGenre()==genre)
        {
            cout<<"Would you like to add this movie in your watch list or play the next one?(add/next)\n";
            cout<<i+1<<". title: " <<this->ui.GetRepo()[i].getTitle()
             <<" genre: "<<this->ui.GetRepo()[i].getGenre()
             <<" year: "<<this->ui.GetRepo()[i].getYear()
             <<" number of likes: "<<this->ui.GetRepo()[i].getLikes()
             <<" link trailer: "<<this->ui.GetRepo()[i].getTrailer()<<"\n";

            //ShellExecute(NULL, "open", (*this->ui->GetRepo())[i].getTrailer().c_str(), NULL, NULL, SW_SHOWNORMAL);
            int c=0;
            cin>>choose;
            if(choose == "add")
            {
                this->ui.add_element_user_service(this->ui.GetRepo()[i].getTitle(),this->ui.GetRepo()[i].getGenre(),
                                                   this->ui.GetRepo()[i].getYear(),this->ui.GetRepo()[i].getLikes(),this->ui.GetRepo()[i].getTrailer());
                this->ui.delete_element_service(this->ui.GetRepo()[i].getTitle(),this->ui.GetRepo()[i].getYear(),this->ui.GetRepo()[i].getTrailer());
            }else if(choose == "next")
                c++;
            else
            {
                cout<<"Invalid command!I will show you the next trailer!\n";
            }
        }
        if(i==this->ui.GetSize()-1){
            cout<<"You arrived at the end!\n";
            break;
        }

    }
}
void UI::display_movies_user() {
    int i;
    for(i=0;i<this->ui.GetUserSize();i++)
    {
        cout<<i+1<<". title: " <<this->ui.GetUserRepo()[i].getTitle()
            <<" genre: "<<this->ui.GetUserRepo()[i].getGenre()
            <<" year: "<<this->ui.GetUserRepo()[i].getYear()
            <<" number of likes: "<<this->ui.GetUserRepo()[i].getLikes()
            <<" link trailer: "<<this->ui.GetUserRepo()[i].getTrailer()<<"\n";
    }
    cout<<"\n";
    this->wf->setData(this->ui.GetUserRepo());
    this->wf->WriteData();
}
void UI::delete_user() {
    string title,syear,trailer, opt;
    int year, i;
    cout<<"Please enter the title of the movie:\n";
    cin>>title;
    cout<<"Please enter the year of the movie:\n";
    cin>>syear;
    cout<<"Please enter the link to the trailer of the movie:\n";
    cin>>trailer;
    try{
        year = this->validator.validate_year(syear);
        this->validator.validate_trailer(trailer);
        this->validator.validate_title(title);
        try{
            this->ui.delete_element_user_service(title, year, trailer);
        }catch(ExceptionRepo& ex){
            cout<<ex.what();
        }

        cout<<"Did you like the film? Yes/No\n";
        cin>>opt;
        if(opt == "Yes")
        {
            for(i=0;i<this->ui.GetSize();i++) {
                if (this->ui.GetRepo()[i].getTitle() == title && this->ui.GetRepo()[i].getYear() == year && this->ui.GetRepo()[i].getTrailer() == trailer)
                    this->ui.GetRepo()[i].setLikes(this->ui.GetRepo()[i].getLikes()+1);
                this->ui.add_element_service(title,this->ui.GetRepo()[i].getGenre(),year,this->ui.GetRepo()[i].getLikes(),trailer);
            }
            cout<<"Operation done successfully!\n\n";
        }else if(opt == "No")
            cout<<"Operation done successfully!\n\n";
        else
            cout<<"Invalid command!\n";
    }catch(ExceptionsValidator& ex){
        cout<<ex.what();
    }

}
void UI::open() {
    this->wf->setData(this->ui.GetUserRepo());
    this->wf->WriteData();
    this->wf->openFile();
}
void UI::start(){
    int running, choose, running1, running2;
    string option, option1,filetype;
    running = 0;
    running1 =0;
    running2 =0;
    cout<<"Type 1 for HTML file or type 2 for CSV file: \n";
    cin>>filetype;
    if(filetype=="1")
    {
        this->wf = new HTML();
    }else if(filetype == "2")
    {
        this->wf= new CSV();
    }else
        cout<<"Invalid input!\n";
    cout<<"Welcome to the cinema!\n";
    cout<<"Which mode would you like to acces?\n";
    while(running2 == 0)
    {
        cout<<"1.Admin mode\n";
        cout<<"2.User mode\n";
        cout<<"3.Exit the program!\n";
        cin>>choose;
        if(choose==1)
        {
            while (running==0)
            {
                print_menu();
                cin>>option;
                if(option=="1")
                    display_movies();
                else if(option == "2")
                    add_admin();
                else if(option == "3")
                    delete_admin();
                else if(option == "4")
                    update_movie();
                else if(option == "5")
                    running=1;
                else
                    cout<<"Invalid command! Try again!\n";
            }
        }else if(choose == 2)
        {
            while( running1 == 0)
            {
                print_menu_user();
                cin>>option;
                if(option=="1")
                    display_movies_user();
                else if(option == "2")
                    add_user();
                else if(option == "3")
                    delete_user();
                else if(option == "4")
                    open();
                else if(option == "5")
                    running1=1;
                else
                    cout<<"Invalid command! Try again!\n";
            }
        }else if(choose == 3)
            break;
        else
            cout<<"Invalid command! Try again!\n";
    }


}

