#include "ToDoList.hpp"
#include "TaskHigh.hpp"

#include <iostream>
#include <string>

int main()
{
    ToDoList todolist;
    

    todolist.addTask();
    todolist.addTask();
    // todolist.addMediumImportantTask();
    // todolist.addHighImportantTask();
    std::cout << "Avant : \n";
    todolist.printAllTasks();
    // todolist.addLowImportantTask();
    todolist.choiceImportanceOfTask(2, E_Importance::HIGH);
    std::cout << "Après : \n";
    todolist.printAllTasks();

    todolist.choiceImportanceOfTask(2, E_Importance::LOW);
    std::cout << "encore apresè : \n";
    todolist.printAllTasks();

    return 0;
}