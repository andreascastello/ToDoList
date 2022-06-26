#include "ToDoList.hpp"
#include "TaskHigh.hpp"

#include <iostream>
#include <string>

int main()
{
    ToDoList todolist;
    
    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "On ajoute 2 taches : \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";

    todolist.addTask();
    todolist.addTask();
    todolist.printAllTasks();

    std::cout << "---------------------------------------------------------------------------------------------------\n";
    std::cout << "On modifie l'importance des 2 taches : \n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";

    todolist.choiceImportanceOfTask(1, E_Importance::HIGH);
    todolist.choiceImportanceOfTask(2, E_Importance::LOW);
    todolist.printAllTasks();

    return 0;
}