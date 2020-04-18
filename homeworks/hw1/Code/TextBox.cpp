#include "textBox.hpp"

void TextBox::draw() throw(Exception)
{
    if (this->handle == NULL || this->handle == INVALID_HANDLE_VALUE)
        throw Exception("Handle ERROR: no correct handle");

    CONSOLE_CURSOR_INFO cursor = {1, TRUE};
    SetConsoleCursorInfo(this->handle, &cursor);

    SetConsoleCursorPosition(this->handle, this->currPos);
    this->outStream << (char)0xC9;
    ++this->currPos.X;
    SetConsoleCursorPosition(this->handle, this->currPos);
    for (auto i = 0; i < this->width; ++i)
    {
        this->outStream << (char)0xCD;
        ++this->currPos.X;
        SetConsoleCursorPosition(this->handle, this->currPos);
    }

    this->outStream << (char)0xBB;
    ++this->currPos.Y;
    SetConsoleCursorPosition(this->handle, this->currPos);
    for (auto i = 0; i < this->height; ++i)
    {
        this->outStream << (char)0xBA;
        ++this->currPos.Y;
        SetConsoleCursorPosition(this->handle, this->currPos);
    }

    this->outStream << (char)0xBC;
    --this->currPos.X;
    SetConsoleCursorPosition(this->handle, this->currPos);
    for (auto i = 0; i < this->width; ++i)
    {
        this->outStream << (char)0xCD;
        --this->currPos.X;
        SetConsoleCursorPosition(this->handle, this->currPos);
    }

    this->outStream << (char)0xC8;
    --this->currPos.Y;
    SetConsoleCursorPosition(this->handle, this->currPos);
    for (auto i = 0; i < this->height; ++i)
    {
        this->outStream << (char)0xBA;
        --this->currPos.Y;
        SetConsoleCursorPosition(this->handle, this->currPos);
    }

    ++this->currPos.X;
    ++this->currPos.Y;
    SetConsoleCursorPosition(this->handle, this->currPos);
}

void TextBox::handleKeyStroke(KEY_EVENT_RECORD &e) throw(Exception)
{
    if (this->handle == NULL || this->handle == INVALID_HANDLE_VALUE)
        throw Exception("Handle ERROR: no correct handle");

    if(!e.bKeyDown) return;

    switch(e.wVirtualKeyCode)
    {
        case VK_LEFT:
            this->moveLeft();
        case VK_RIGHT:
            this->moveRight();
    }
}