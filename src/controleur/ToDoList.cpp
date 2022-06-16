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


void ToDoList::addTask(E_Colors color, E_Importance importance){
    std::cout << "Ecrire une tache : \n";
    std::string str;
    std::getline (std::cin, str);

    //make_unique permet de créer un unique ptr qui est ensuite pushback dans "_tasks"
    switch (importance)
    {
    // case E_Importance::HIGH     : _tasks.push_back(std::make_unique<TaskHigh>(str, color)); break;
    // case E_Importance::LOW      : _tasks.push_back(std::make_unique<TaskLow>(str, color));  break;
    // case E_Importance::MEDIUM   : _tasks.push_back(std::make_unique<TaskMedium>(str, color));  break;
    case E_Importance::NO_IMPORTANCE :
    default:
        _tasks.push_back(std::make_unique<Task>(str, color));
        break;
    }

    _compteur++;
    _tasks[_tasks.size()-1].get()->setId(_compteur);
}

// void ToDoList::addHighImportantTask ()
// {
//     addTask(E_Colors::RED, E_Importance::HIGH);
// }

// void ToDoList::addLowImportantTask ()
// {
//     addTask(E_Colors::BLUE, E_Importance::LOW);
// }

// void ToDoList::addMediumImportantTask ()
// {
//     addTask(E_Colors::GREEN, E_Importance::MEDIUM);
// }

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
                    delTask(idOfTask); //supprime la tache
                    _tasks.emplace(it, std::make_unique<TaskHigh>(idOfTask, txtOfOldTask, E_Colors::RED)); //la remplace avec une tache d'un certain types avec l'id précédent
                    break;
                case E_Importance::LOW:
                    delTask(idOfTask); //supprime la tache
                    _tasks.emplace(it, std::make_unique<TaskLow>(idOfTask, txtOfOldTask, E_Colors::BLUE));
                    break;
                // case E_Importance::MEDIUM           : addTask(E_Colors::GREEN   , E_Importance::MEDIUM  );break;
                // case E_Importance::NO_IMPORTANCE    :
                default:
                    //tasks.push_back(std::make_unique<Task>(str, color));
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
