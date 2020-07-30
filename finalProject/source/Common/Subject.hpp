#pragma once
#include <vector>
#include "Observer.hpp"
#include <string>


class Subject
{
public:
    void addObserver(Observer *ob)
    {
        observers.push_back(ob);
    }

    void performAction(std::string action)
    {
        for (auto ob : this->observers)
            ob->notify(action);
    }

private:
    std::vector<Observer *> observers;
};