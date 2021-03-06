#include "textBox.hpp"

void TextBox::draw() throw(Exception)
{
    SetConsoleCursorPosition(this->handle, this->coordinations);
    SetConsoleTextAttribute(this->handle, this->color);

    CONSOLE_SCREEN_BUFFER_INFO info;
    if (GetConsoleScreenBufferInfo(this->handle, &info) == FALSE)
        throw new Exception("couldnt fetch data");

    if (this->handle == NULL || this->handle == INVALID_HANDLE_VALUE)
        throw Exception("Handle ERROR: no correct handle");

    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(this->handle, &cursor);
    if (!cursor.bVisible)
    {
        cursor.bVisible = TRUE;
        SetConsoleCursorInfo(this->handle, &cursor);
    }

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

    this->currPos.X += 2;
    ++this->currPos.Y;
    SetConsoleCursorPosition(this->handle, this->currPos);
    SetConsoleTextAttribute(this->handle, info.wAttributes);
}

void TextBox::handleKeyStroke(KEY_EVENT_RECORD &e) throw(Exception)
{
    if (this->handle == NULL || this->handle == INVALID_HANDLE_VALUE)
        throw Exception("Handle ERROR: no correct handle");

    if (!e.bKeyDown)
        return;

    switch (e.wVirtualKeyCode)
    {
    case VK_LEFT:
        this->moveLeft();
        break;
    case VK_RIGHT:
        this->moveRight();
        break;
    case VK_UP:
        this->moveUp();
        break;
    case VK_DOWN:
        this->moveDown();
        break;
    default:
        this->outStream << e.uChar.AsciiChar;
        this->moveRight();
    }
}