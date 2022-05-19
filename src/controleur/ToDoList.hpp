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
        void addTask (E_Colors color = E_Colors::NO_COLOR, E_Importance importance = E_Importance::NO_IMPORTANCE);
        void addHighImportantTask ();
        void addLowImportantTask ();
        //supprime une tache
        void delTask (unsigned int id);

        //li une tache
        std::vector<std::unique_ptr<Task>> const& readTask () const;
        void printAllTasks();
};

#endif