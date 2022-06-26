#include "TaskHigh.hpp"
#include "TaskLow.hpp"
#include "TaskMedium.hpp"

#include "ToDoList.hpp"
#include <iostream>


ToDoList::ToDoList(/* args */)
{
    _compteur = 0;
}

ToDoList::~ToDoList()
{
}

void ToDoList::addTask(){
    std::cout << "Ecrire une tache : \n";
    std::string str;
    std::getline (std::cin, str);

    _tasks.push_back(std::make_unique<Task>(str));
    _compteur++;
    _tasks[_tasks.size()-1].get()->setId(_compteur);
}

void ToDoList::choiceImportanceOfTask(unsigned int id, E_Importance importance){
    for (auto it = _tasks.begin(); it != _tasks.end(); ++it)
    {
        unsigned int idOfTask = it->get()->getId(); //stock l'ancien ID

        if (idOfTask == id)
        {
            std::string txtOfOldTask = it->get()->getTextOfTask(); //récupère l'ancien txt
            switch (importance)
            {
                case E_Importance::HIGH:
                //A faire : verifier l'importance (choix)
                    delTask(idOfTask); //supprime la tache
                    _tasks.emplace(it, std::make_unique<TaskHigh>(idOfTask, txtOfOldTask, E_Colors::RED)); //la remplace avec une tache d'un certain types avec l'id précédent
                    break;

                case E_Importance::LOW:
                    delTask(idOfTask);
                    _tasks.emplace(it, std::make_unique<TaskLow>(idOfTask, txtOfOldTask, E_Colors::BLUE));
                    break;

                case E_Importance::MEDIUM           :
                    delTask(idOfTask);
                    _tasks.emplace(it, std::make_unique<TaskMedium>(idOfTask, txtOfOldTask, E_Colors::GREEN));
                    break;

                case E_Importance::NO_IMPORTANCE    :
                    delTask(idOfTask);
                    _tasks.emplace(it, std::make_unique<Task>(idOfTask, txtOfOldTask));
                    break;
                default:
                    std::cout << "tata";
                    break;
            }
        }
    }
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
