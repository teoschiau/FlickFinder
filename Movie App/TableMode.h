//
// Created by Teodora Schiau on 29.05.2024.
//

#ifndef OOP_A8_9_916_SCHIAU_TEODORA_TABLEMODE_H
#define OOP_A8_9_916_SCHIAU_TEODORA_TABLEMODE_H
#include <QAbstractTableModel>
#include "Repository.h"
#include <QStyledItemDelegate>


class TableMode:public QAbstractTableModel, public QStyledItemDelegate{
private:
    Repository& repo;

public:
    TableMode(Repository& repo, QObject* parent = NULL);
    ~TableMode() = default;

    int rowCount(const QModelIndex &parent = QModelIndex{})const override;
    int columnCount(const QModelIndex &parent = QModelIndex{})const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex & index) const override;
    void updateInternalData();

};
#endif //OOP_A8_9_916_SCHIAU_TEODORA_TABLEMODE_H
