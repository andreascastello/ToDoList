#ifndef TASKMEDIUM_H
#define TASKMEDIUM_H

#include "Task.hpp"


class TaskMedium : public Task
{
    private:

    public:
        TaskMedium(std::string str, E_Colors color = E_Colors::NO_COLOR);
        ~TaskMedium();
};

#endif