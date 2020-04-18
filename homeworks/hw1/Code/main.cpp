#include "includes.hpp"

#include "label.hpp"

void resetDefaults(void);

int main(int argc, char *argv[])
{
    system("cls");
    Label l("Some label", 0, 0, FOREGROUND_WHITE | BACKGROUND_BLACK, GetStdHandle(STD_OUTPUT_HANDLE));
    try
    {
        l.draw();
    }
    catch (Exception &e)
    {
        std::cerr << e.what() << "\n";
    }

    resetDefaults();
    return 0;
}

void resetDefaults(void)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, TRUE};
    SetConsoleCursorInfo(hStdout, &cursor);
}