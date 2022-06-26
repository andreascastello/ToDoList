//si TODOLIST_H n'existe pas alors on le crée
#ifndef TODOLIST_H
#define TODOLIST_H

#include "E_Importance.hpp"
#include "Task.hpp"
#include <vector>
#include <memory>

class ToDoList
{
    private:
        std::vector<std::unique_ptr<Task>> _tasks;
        unsigned int _compteur;

    public:
        ToDoList(/* args */);
        ~ToDoList();

        //ajoute une tache
        void addTask ();

        //supprime une tache
        void delTask (unsigned int id);

        //lis une tache
        std::vector<std::unique_ptr<Task>> const& readTask () const;
        void printAllTasks();

        //choisir l'importance de la tache
        void choiceImportanceOfTask(unsigned int id, E_Importance importance);
};

#endif