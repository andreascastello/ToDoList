#include "TaskHigh.hpp"
#include "TaskLow.hpp"

#include "ToDoList.hpp"
#include <iostream>

ToDoList::ToDoList(/* args */)
{
    _compteur = 0;
}

ToDoList::~ToDoList()
{
}


void ToDoList::addTask(E_Colors color, E_Importance importance){
    std::cout << "Ecrire une tache : \n";
    std::string str;
    std::getline (std::cin, str);

    //make_unique permet de créer un unique ptr qui est ensuite pushback dans "_tasks"
    switch (importance)
    {
    case E_Importance::HIGH :   _tasks.push_back(std::make_unique<TaskHigh>(str, color));   break;
    case E_Importance::LOW :   _tasks.push_back(std::make_unique<TaskLow>(str, color));  break;
    case E_Importance::NO_IMPORTANCE :
    default:
        _tasks.push_back(std::make_unique<Task>(str, color));
        break;
    }

    _compteur++;
    _tasks[_tasks.size()-1].get()->setId(_compteur);
}

void ToDoList::addHighImportantTask ()
{
    addTask(E_Colors::RED, E_Importance::HIGH);
}

void ToDoList::addLowImportantTask ()
{
    addTask(E_Colors::BLUE, E_Importance::LOW);
}

void ToDoList::delTask(unsigned int id){
    for (auto it = _tasks.begin(); it != _tasks.end(); ++it)
    {
        if (it->get()->getId() == id)
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
std::vector<std::unique_ptr<Task>> const& ToDoList::readTask() const{

    return _tasks;
}

void ToDoList::printAllTasks(){
    std::cout << "\n";
    for (auto& task : _tasks){
        std::cout << "(" << task.get()->getColor()
        << ") Tache " << task.get()->getId() 
        << " : " << task.get()->getTextOfTask() << "\n";
    }
}
