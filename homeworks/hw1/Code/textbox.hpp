#pragma once

#include "includes.hpp"
#include "component.hpp"

class TextBox : public Component
{
public:
    TextBox() : Component({0, 0}, FOREGROUND_WHITE | BACKGROUND_BLACK), width(0), height(0) {}
    TextBox(int height, int width, SHORT x, SHORT y, DWORD color) : Component({x, y}, color), width(width), height(height), currPos({x, y}) {}
    TextBox(int height, int width, COORD pos, DWORD color) : Component(pos, color), width(width), height(height), currPos(pos) {}
    TextBox(int height, int width, SHORT x, SHORT y, DWORD color, HANDLE handle) : Component({x, y}, color, handle), width(width), height(height), currPos({x, y}) {}
    TextBox(int height, int width, COORD pos, DWORD color, HANDLE handle) : Component(pos, color, handle), width(width), height(height), currPos(pos) {}
    ~TextBox() {}

    void draw() throw(Exception) override;
    void handleKeyStroke(KEY_EVENT_RECORD &e) throw(Exception) override;
    inline void moveLeft()
    {
        if (this->currPos.X - 2 <= this->coordinations.X)
        {
            if (this->currPos.Y - 1 > this->coordinations.Y)
            {
                --this->currPos.Y;
                this->currPos.X = this->width;
            }
        }
        if (this->currPos.X - 2 > this->coordinations.X)
        {
            --this->currPos.X;
            SetConsoleCursorPosition(this->handle, this->currPos);
        }
    };
    inline void moveRight()
    {
        if (this->currPos.X < width)
        {
            ++this->currPos.X;
            if (this->currPos.X >= width)
            {
                if (this->currPos.Y < this->height)
                {
                    ++this->currPos.Y;
                    this->currPos.X = this->coordinations.X + 2;
                }
                else
                {
                    --this->currPos.X;
                }
            }
        }
        SetConsoleCursorPosition(this->handle, this->currPos);
    };
    inline void moveUp()
    {
        if (this->currPos.Y - 1 > this->coordinations.Y)
        {
            --this->currPos.Y;
            SetConsoleCursorPosition(this->handle, this->currPos);
        }
    }
    inline void moveDown()
    {
        if (this->currPos.Y < height)
        {
            ++this->currPos.Y;
        }
        SetConsoleCursorPosition(this->handle, this->currPos);
    }

private:
    COORD currPos;
    unsigned int width;
    unsigned int height;
};