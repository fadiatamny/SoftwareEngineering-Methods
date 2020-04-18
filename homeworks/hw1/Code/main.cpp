#include "includes.hpp"

#include "label.hpp"
#include "textBox.hpp"

void resetDefaults(void);

int main(int argc, char *argv[])
{
    INPUT_RECORD record;
    DWORD count;
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

    auto list = std::vector<std::shared_ptr<Component>>();
    list.push_back(std::shared_ptr<Label>(new Label("Some label", 0, 0, FOREGROUND_WHITE | BACKGROUND_BLACK)));
    list.push_back(std::shared_ptr<TextBox>(new TextBox(10, 100, {0, 1}, FOREGROUND_WHITE | BACKGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY)));

    system("cls");

    for (auto elem : list)
        elem->draw();

    while (1)
    {
        ReadConsoleInput(h, &record, 1, &count);
        if (record.EventType == KEY_EVENT)
        {
            if (record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
                break;

            for (auto elem : list)
                elem->handleKeyStroke(record.Event.KeyEvent);
        }
    }

    resetDefaults();
    return 0;
}

void resetDefaults(void)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, TRUE};
    SetConsoleCursorInfo(hStdout, &cursor);
    system("cls");
}