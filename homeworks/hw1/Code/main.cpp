#include "includes.hpp"

#include "label.hpp"
#include "textBox.hpp"
#include "checkBox.hpp"

void resetDefaults(WORD attr);

int main(int argc, char *argv[])
{
    INPUT_RECORD record;
    DWORD count;
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO info;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info) == FALSE)
        throw new Exception("couldnt fetch data");

    std::vector<std::string> options;
    options.push_back("LOOK");
    options.push_back("I");
    options.push_back("AM");
    options.push_back("A");
    options.push_back("CHECK");
    options.push_back("BOX");

    auto list = std::vector<std::shared_ptr<Component>>();
    list.push_back(std::shared_ptr<Label>(new Label("Some label", 0, 0, FOREGROUND_GREEN | BACKGROUND_BLACK | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY)));
    list.push_back(std::shared_ptr<TextBox>(new TextBox(10, 100, {0, 1}, FOREGROUND_WHITE | BACKGROUND_RED | BACKGROUND_INTENSITY)));
    list.push_back(std::shared_ptr<CheckBox>(new CheckBox(options, {0, 15}, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY)));

    system("cls");

    int index = 0;

    while (index < list.size())
    {
        list[index]->draw();
        while (1)
        {
            ReadConsoleInput(h, &record, 1, &count);
            if (record.EventType == KEY_EVENT)
            {
                if (record.Event.KeyEvent.bKeyDown)
                {
                    if (record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
                        break;

                    list[index]->handleKeyStroke(record.Event.KeyEvent);
                }
            }
        }
        ++index;
    }

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 25});

    std::cout << "\n";
    for (auto elem : std::static_pointer_cast<CheckBox>(list[2])->getSelected())
        std::cout << elem << "\n";

    resetDefaults(info.wAttributes);
    return 0;
}

void resetDefaults(WORD attr)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, TRUE};
    SetConsoleCursorInfo(hStdout, &cursor);
    SetConsoleTextAttribute(hStdout, attr);
}