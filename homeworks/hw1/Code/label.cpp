#include "label.hpp"

void Label::draw() throw(Exception)
{
    if(this->handle == NULL || this->handle == INVALID_HANDLE_VALUE) throw Exception("Handle ERROR: no correct handle");

    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (GetConsoleScreenBufferInfo(this->handle, &info) == FALSE)
        throw new Exception("couldnt fetch data");
    
    SetConsoleTextAttribute(this->handle, this->color);
    SetConsoleCursorPosition(this->handle, this->coordinations);
    SetConsoleCursorInfo(this->handle, &cursor);
    this->outStream << this->value;
    SetConsoleTextAttribute(this->handle, info.wAttributes);
}