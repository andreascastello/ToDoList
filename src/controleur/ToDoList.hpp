//si TODOLIST_H n'existe pas alors on le crée
#ifndef TODOLIST_H
#define TODOLIST_H

#include "Task.hpp"
#include <vector>

class ToDoList
{
    private:
        std::vector<Task> _tasks;
        unsigned int _compteur;
    public:
        ToDoList(/* args */);
        ~ToDoList();

        //ajoute une tache
        void addTask (E_Colors color = E_Colors::NO_COLOR);

        //supprime une tache
        void delTask (unsigned int id);

        //lit une tache
        std::vector<Task> readTask () const;
        void printAllTasks();
};

#endif