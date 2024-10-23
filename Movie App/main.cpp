#include <QApplication>
#include <QPushButton>
#include "FileRepository.h"
#include "Repository.h"
#include "service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    FileRepo repo("../movies.txt");
    Repository user_repo;
    Service service(repo, user_repo);
    GUI gui{service, user_repo};
    //gui.setStyleSheet("QMainWindow {background: 'green';}");
    gui.show();
    return a.exec();
}
