#include "ToDoList.hpp"

#include <iostream>
#include <string>

int main()
{
    ToDoList todolist;

    todolist.addTask();
    todolist.addTask(E_Colors::RED);

    todolist.printAllTasks();

    return 0;
}