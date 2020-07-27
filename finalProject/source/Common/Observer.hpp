#pragma once
#include <string>

class Observer
{
public:
    Observer() {};
    ~Observer() {};
    virtual void notify(std::string text){}
};