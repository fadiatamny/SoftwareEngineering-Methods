#pragma once

#include "includes.hpp"

#define FOREGROUND_WHITE (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#define BACKGROUND_WHITE (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED)
#define BACKGROUND_BLACK (0)

class Label
{
public:
    Label() : value(""), color(FOREGROUND_WHITE | BACKGROUND_BLACK)
    {
        coordinations.X = 0;
        coordinations.Y = 0;
    }
    Label(const Label &obj) : value(obj.value), color(obj.color), coordinations(obj.coordinations), handle(obj.handle) {}
    Label(const std::string &value, SHORT x, SHORT y, DWORD color, HANDLE handle) : value(value), color(color), handle(handle)
    {
        coordinations.X = x;
        coordinations.Y = y;
    }
    Label(const std::string &value, COORD coordinations, DWORD color, HANDLE handle) : value(value), coordinations(coordinations), color(color), handle(handle) {}
    ~Label() {}

    void setValue(std::string value) { this->value = value; }
    const std::string getValue() const { return this->value; }
    void setCoordinations(SHORT x, SHORT y)
    {
        this->coordinations.X = x;
        this->coordinations.Y = y;
    }
    void setCoordinations(COORD coordinations) { this->coordinations = coordinations; }
    const COORD getCoordinations() const { return this->coordinations; }
    void setColor(DWORD foreground, DWORD background = 0) { this->color = foreground | background; }
    void setColor(DWORD color) { this->color = color; }
    const DWORD getColor() const { return this->color; }

    void draw() throw(Exception);

private:
    std::string value;
    DWORD color;
    COORD coordinations;
    HANDLE handle;
};