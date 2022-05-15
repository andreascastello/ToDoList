//si TASK_H n'existe pas alors on le crée
#ifndef TASK_H
#define TASK_H

#include "E_Colors.hpp"
#include <string>

class Task
{
    private:
        std::string _textOfTask;
        unsigned int _id;
        E_Colors _color;
    public:
        Task(std::string str, E_Colors color = E_Colors::NO_COLOR);
        ~Task();

        unsigned int getId() const;
        std::string getColor() const;
        std::string getTextOfTask() const;
        void setId(unsigned int id);
};

#endif