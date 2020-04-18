#pragma once

#include "includes.hpp"
#include "exception.hpp"

#define FOREGROUND_WHITE (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#define BACKGROUND_WHITE (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED)
#define BACKGROUND_BLACK (0)

class Component
{
public:
    Component(COORD coordinations, DWORD color, HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE), std::ostream &outStream = std::cout) : coordinations(coordinations), color(color), handle(handle), outStream(outStream) {}
    Component(Component &obj) : coordinations(obj.coordinations), color(obj.color), handle(obj.handle), outStream(obj.outStream) {}
    virtual ~Component(){};
    virtual void draw() throw(Exception) = 0;
    virtual void handleKeyStroke(KEY_EVENT_RECORD &e) throw(Exception){};

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

protected:
    DWORD color;
    COORD coordinations;
    HANDLE handle = NULL;
    std::ostream &outStream;
};