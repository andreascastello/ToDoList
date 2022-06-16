#ifndef TASKLOW_H
#define TASKLOW_H

#include "Task.hpp"


class TaskLow : public Task
{
    private:

    public:
        TaskLow(unsigned int id, std::string str, E_Colors color = E_Colors::NO_COLOR);
        ~TaskLow();
};

#endif