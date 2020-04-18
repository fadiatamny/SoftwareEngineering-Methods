#pragma once

#include "includes.hpp"
#include "component.hpp"

class Label : public Component
{
public:
    Label() : value(""), Component({0, 0}, FOREGROUND_WHITE | BACKGROUND_BLACK) {}
    Label(const Label &obj) : value(obj.value), Component(obj.coordinations, obj.color, obj.handle) {}
    Label(const std::string &value, SHORT x, SHORT y, DWORD color) : value(value), Component({x, y}, color) {}
    Label(const std::string &value, COORD coordinations, DWORD color) : value(value), Component(coordinations, color) {}
    Label(const std::string &value, SHORT x, SHORT y, DWORD color, HANDLE handle) : value(value), Component({x, y}, color, handle) {}
    Label(const std::string &value, COORD coordinations, DWORD color, HANDLE handle) : value(value), Component(coordinations, color, handle) {}
    virtual ~Label() {}

    void setValue(std::string value) { this->value = value; }
    const std::string getValue() const { return this->value; }

    virtual void draw() throw(Exception) override;

protected:
    std::string value;
};