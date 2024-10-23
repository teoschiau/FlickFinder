//
// Created by Teodora Schiau on 29.05.2024.
//

#ifndef OOP_A8_9_916_SCHIAU_TEODORA_ACTION_H
#define OOP_A8_9_916_SCHIAU_TEODORA_ACTION_H
#include "Repository.h"

class Action{
public:
    virtual void executeUndo() =0;
    virtual void executeRedo() =0;
};

class AddAction:public Action{
private:
    Repository& repo;
    Movie addedMovie;

public:
    AddAction(Repository& repo, Movie addedMovie);
    void executeUndo() override;
    void executeRedo() override;
};

class DeleteAction:public Action{
private:
    Repository& repo;
    Movie deletedMovie;

public:
    DeleteAction(Repository& repo, Movie deletedMovie);
    void executeUndo() override;
    void executeRedo() override;
};
class UpdateGenderAction:public Action{
private:
    Repository& repo;
    Movie oldupdatedMovie;
    Movie newupdatedMovie;

public:
    UpdateGenderAction(Repository& repo, Movie oldupdatedMovie, Movie newupdatedMovie);
    void executeUndo() override;
    void executeRedo() override;
};

class UpdatedLikesAction:public Action{
private:
    Repository& repo;
    Movie oldupdatedMovie;
    Movie newupdatedMovie;

public:
    UpdatedLikesAction(Repository& repo, Movie oldupdatedMovie, Movie newupdatedMovie);
    void executeUndo() override;
    void executeRedo() override;
};
class AddActionUser:public Action{
private:
    Repository& repo;
    Movie addedMovie;

public:
    AddActionUser(Repository& repo, Movie addedMovie);
    void executeUndo() override;
    void executeRedo() override;
};

class DeleteActionUser:public Action{
private:
    Repository& repo;
    Movie deletedMovie;

public:
    DeleteActionUser(Repository& repo, Movie deletedMovie);
    void executeUndo() override;
    void executeRedo() override;
};

#endif //OOP_A8_9_916_SCHIAU_TEODORA_ACTION_H
