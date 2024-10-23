//
// Created by Teodora Schiau on 29.05.2024.
//

#include "TableMode.h"
#include <QPixmap>
#include <QPainter>

TableMode::TableMode(Repository &repo, QObject *parent):repo{repo},QAbstractTableModel{parent} {
}
int TableMode::rowCount(const QModelIndex &parent) const {
    return this->repo.GetSizeUser();
}

int TableMode::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant TableMode::data(const QModelIndex &index, int role) const{
    int row = index.row();
    int column = index.column();

    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        vector<Movie> movies = this->repo.GetDynArrUser();
        Movie m = movies[row];
        switch (column) {
            case 0:
                return QString::fromStdString(m.getTitle());
            case 1:
                return QString::fromStdString(m.getGenre());
            case 2:
                return QString::fromStdString(to_string(m.getYear()));
            case 3:
                return QString::fromStdString(to_string(m.getLikes()));
            case 4:
                return QString::fromStdString(m.getTrailer());
            case 5:
                break;
        }
    }
    return QVariant{};
}
QVariant TableMode::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole){
        if(orientation == Qt::Horizontal)
        {
            switch(section){
                case 0:
                    return QString{"Title"};
                case 1:
                    return QString{"Genre"};
                case 2:
                    return QString{"Year"};
                case 3:
                    return QString{"Number of likes"};
                case 4:
                    return QString{"Trailer"};
                default:
                    break;
            }
        }
    }
    return QVariant{};
}

Qt::ItemFlags TableMode::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void TableMode::updateInternalData() {
    endResetModel();
}