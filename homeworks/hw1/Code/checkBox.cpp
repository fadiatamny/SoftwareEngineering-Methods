#include "checkBox.hpp"

void CheckBox::draw() throw(Exception)
{
    SetConsoleCursorPosition(this->handle, this->coordinations);
    SetConsoleTextAttribute(this->handle, this->color);

    CONSOLE_SCREEN_BUFFER_INFO info;
    if (GetConsoleScreenBufferInfo(this->handle, &info) == FALSE)
        throw new Exception("couldnt fetch data");

    for (auto i = 0; i < this->list.size(); ++i)
    {
        this->outStream << "[" << (this->list[i]->isTicked() ? (char)0xFE : ' ') << "] - " << this->list[i]->getValue();
        ++this->currPos.Y;
        SetConsoleCursorPosition(this->handle, this->currPos);
    }

    this->currPos = this->coordinations;
    ++this->currPos.X;

    SetConsoleCursorPosition(this->handle, this->currPos);
    SetConsoleTextAttribute(this->handle, info.wAttributes);
}

void CheckBox::handleKeyStroke(KEY_EVENT_RECORD &e) throw(Exception)
{
    if (this->handle == NULL || this->handle == INVALID_HANDLE_VALUE)
        throw Exception("Handle ERROR: no correct handle");

    if (!e.bKeyDown)
        return;

    switch (e.wVirtualKeyCode)
    {
    case VK_UP:
        this->moveUp();
        break;
    case VK_DOWN:
        this->moveDown();
        break;
    case VK_SPACE:
        this->select();
        this->currPos = this->coordinations;
        this->draw();
        this->currPos.Y += index;
        SetConsoleCursorPosition(this->handle, this->currPos);
        break;
    }
}