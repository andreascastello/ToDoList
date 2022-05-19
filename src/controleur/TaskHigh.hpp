#ifndef TASKHIGH_H
#define TASKHIGH_H

#include "Task.hpp"


class TaskHigh : public Task
{
    private:

    public:
        TaskHigh(std::string str, E_Colors color = E_Colors::NO_COLOR);
        //void changeTypeTask() override;
        ~TaskHigh();
};

#endif