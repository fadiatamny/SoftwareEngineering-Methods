#include "label.hpp"

void Label::draw() throw(Exception)
{
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (GetConsoleScreenBufferInfo(this->handle, &info) == FALSE)
        throw new Exception("couldnt fetch data");
    
    SetConsoleTextAttribute(this->handle, this->color);
    SetConsoleCursorPosition(this->handle, this->coordinations);
    SetConsoleCursorInfo(this->handle, &cursor);
    std::cout << this->value;
    SetConsoleTextAttribute(this->handle, info.wAttributes);
}