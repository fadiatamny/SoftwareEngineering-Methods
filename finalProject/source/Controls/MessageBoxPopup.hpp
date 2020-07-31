#pragma once

#include "./Panel.hpp"
#include "./Label.hpp"
#include "./Button.hpp"
#include "../Common/Border/Border.hpp"

class MessageBoxPopup : public Panel
{
public:
    MessageBoxPopup(short x, short y, short width, Border *border, Color color, Color backgroundColor, std::string message, Button *actionBtn) : Panel(x + 5, y + 5, border, color, backgroundColor),
                                                                                                                                                 messageText(Label(message, (width - message.size()) / 2, 0, message.size(), color, backgroundColor, border)),
                                                                                                                                                 okBtn(Button("Accept", 0, 4, 6, Color::White, Color::Green, border, this, 1)),
                                                                                                                                                 cancelBtn(Button("Cancel", width - 6 - 2, 4, 5, Color::White, Color::Red, border, this, 1)),
                                                                                                                                                 actionBtn(actionBtn),
                                                                                                                                                 performed("")
    {
        this->addControl(&this->messageText);
        this->addControl(&this->okBtn);
        this->addControl(&this->cancelBtn);
    }
    ~MessageBoxPopup() {}

    std::string getMessage() const { return this->messageText.getValue(); }
    void setMessage(std::string message) { this->messageText.setValue(message); };
    std::string getPerformed() { return performed; };
    void setShowButton(Button *button) { this->actionBtn = button; };

    void draw(Graphics &g, int x, int y, size_t z);
    void notify(std::string text);
    bool canGetFocus() { return true; };

private:
    Label messageText;
    Button okBtn;
    Button cancelBtn;
    std::string performed;
    Button *actionBtn;

    void toggle();
};