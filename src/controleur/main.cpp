#include "ToDoList.hpp"

#include <iostream>
#include <string>


int main()
{
    ToDoList todolist;

    todolist.addTask();
    todolist.addHighImportantTask();
    todolist.addLowImportantTask();

    todolist.printAllTasks();


    return 0;
}