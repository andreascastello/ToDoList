#ifndef TASKLOW_H
#define TASKLOW_H

#include "Task.hpp"


class TaskLow : public Task
{
    private:

    public:
        TaskLow(std::string str, E_Colors color = E_Colors::NO_COLOR);
        //void changeTypeTask() override;
        ~TaskLow();
};

#endif