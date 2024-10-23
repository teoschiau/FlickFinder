//
// Created by Teodora Schiau on 28.04.2024.
//

#include "WriteFile.h"

HTML::HTML() {
    this->filename = "../movies.html";
}

CSV::CSV() {
    this->filename = "../movies.csv";
}

void HTML::WriteData() {
    ofstream g(this->filename);
    g << "<!DOCTYPE html>\n"
         "<html>\n"
         "<head>\n"
         "<title>Movie Watch List </title>\n"
         "<style>\n"
         "table {"
         "width: 100%;"
         "margin: 20px auto;"
         "border-collapse: collapse;"
         "font-family: Arial, sans-serif;"
         "}"
         "th {"
         "background-color: #4CAF50;"
         "color: white;"
         "padding: 10px;"
         "font-size: 18px;"
         "}"

         "td {"
         "text-align: center;"
            "padding: 8px;"
            "border-bottom: 1px solid #ddd; "
            "}"
            "</style>\n"
         "</head>\n"
         "<body>\n"
         "<table border=\"1\">\n"
         "    <tr> <!-- tr = table row; 1 row for each entity -->\n"
         "        <td><strong>Title</strong></td>\n"
         "        <td><strong>Launch year</strong></td>\n"
         "        <td><strong>Genre</strong></td>\n"
         "        <td><strong>Number of likes</strong></td>\n"
         "        <td><strong>Trailer link</strong></td>\n"
         "    </tr>";

    for(auto CurrentElement: this->elements)
    {
        g << "<tr>\n";
        g << "<td>" << CurrentElement.getTitle() << "</td>\n";
        g << "<td>" << CurrentElement.getYear() << "</td>\n";
        g << "<td>" << CurrentElement.getGenre() << "</td>\n";
        g << "<td>" << CurrentElement.getLikes() << "</td>\n";
        g << "<td>" << CurrentElement.getTrailer() << "</td>\n";
    }
    g << "</table>\n"
         "</body>\n"
         "</html>";

}

void CSV::WriteData() {
    ofstream g(this->filename);
    for(auto CurrentElement: this->elements)
        g << CurrentElement.getTitle()<<","<<CurrentElement.getYear()<<","<<CurrentElement.getGenre()<<","<<CurrentElement.getLikes()<<","<<CurrentElement.getTrailer()<<"\n";
    g.close();
    this->elements.clear();
}

void HTML::openFile() {
    string command = "open " + filename;
    system(command.c_str());
}

void CSV::openFile() {
    system("open \"../movies.csv\"");
}

void HTML::setData(vector<Movie> elements) {
    this->elements = move(elements);
}

void CSV::setData(vector<Movie> elements) {
    this->elements = move(elements);
}
