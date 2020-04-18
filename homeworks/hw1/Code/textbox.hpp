#pragma once

#include "includes.hpp"
#include "component.hpp"

class TextBox : public Component
{
public:
    TextBox() : Component({0, 0}, FOREGROUND_WHITE | BACKGROUND_BLACK), width(0), height(0) {}
    TextBox(int height, int width, SHORT x, SHORT y, DWORD color) : Component({x, y}, color), width(width), height(height), currPos({x,y}) {}
    TextBox(int height, int width, COORD pos, DWORD color) : Component(pos, color), width(width), height(height), currPos(pos) {}
    TextBox(int height, int width, SHORT x, SHORT y, DWORD color, HANDLE handle) : Component({x, y}, color, handle), width(width), height(height), currPos({x,y}) {}
    TextBox(int height, int width, COORD pos, DWORD color, HANDLE handle) : Component(pos, color, handle), width(width), height(height), currPos(pos) {}
    ~TextBox() {}

    void draw() throw(Exception) override;
    void handleKeyStroke(KEY_EVENT_RECORD &e) throw(Exception) override;
    inline void moveLeft()
    {
        if (1 - this->currPos.X > 0)
        {
            --this->currPos.X;
            SetConsoleCursorPosition(this->handle, this->currPos);
        }
    };
    inline void moveRight()
    {
        if (1 + this->currPos.X < width)
        {
            ++this->currPos.X;
            SetConsoleCursorPosition(this->handle, this->currPos);
        }
    };

private:
    COORD currPos;
    unsigned int width;
    unsigned int height;
};