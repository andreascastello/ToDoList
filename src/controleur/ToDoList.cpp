#include "ToDoList.hpp"
#include <iostream>
ToDoList::ToDoList(/* args */)
{
    _compteur = 0;
}

ToDoList::~ToDoList()
{
}

void ToDoList::addTask(E_Colors color){
    std::cout << "Ecrire une tache : \n";
    std::string str;
    std::getline (std::cin, str);

    Task task(str, color);
    _tasks.push_back(task);

    _compteur++;
    _tasks[_tasks.size()-1].setId(_compteur);
}

void ToDoList::delTask(unsigned int id){
    for (auto it = _tasks.begin(); it != _tasks.end(); ++it)
    {
        if (it->getId() == id)
        {
            _tasks.erase(it);
            return;
        }   
    }
}

/**
 * Il renvoie le vecteur des tâches.
 * 
 * @return Un vecteur d'objets Task.
 */
std::vector<Task> ToDoList::readTask() const{

    return _tasks;
}

void ToDoList::printAllTasks(){
    std::cout << "\n";
    for (auto task : _tasks){
        std::cout << "(" << task.getColor() << ") Tache " << task.getId() << " : " << task.getTextOfTask() << "\n";
    }
}