#include "Task.hpp"
#include "magic_enum.hpp"

#include <iostream>

Task::Task(std::string str, E_Colors color)
:_textOfTask(str), _color(color)
{
    _id = 0;
}

Task::~Task()
{
}

unsigned int Task::getId() const{
    return _id;
}

void Task::setId(unsigned int id){
    _id = id;
}

std::string Task::getTextOfTask() const{
    return _textOfTask;
}

std::string Task::getColor() const{
    // auto color_name = magic_enum::enum_name(_color);
    // return color_name;
    switch (_color)
    {
        case E_Colors::BLUE : return "Blue";
        case E_Colors::RED : return "Red";
        case E_Colors::GREEN : return "Green";
        
        default: return "no colors";
    }
}