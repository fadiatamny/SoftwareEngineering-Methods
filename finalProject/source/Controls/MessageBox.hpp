#pragma once

#include "./Panel.hpp"
#include "./Label.hpp"
#include "./Button.hpp"
#include "../Common/Border/Border.hpp"

class MessageBox : public Panel
{
public:
    MessageBox(short left, short top, short width, Border *buttonBorder, Border *border, Color textColor, Color backgroundColor, std::string message, std::string ok, std::string cancel, Button *showButton);
    ~MessageBox() {}

    void draw(Graphics &g, int x, int y, size_t z);
    std::string getMessage();
    void setMessage(std::string message);
    std::string getReturnValue() { return returnValue; };
    void setShowButton(Button *button);
    void notify(std::string text);
    bool canGetFocus() { return true; };

private:
    Label message;
    Button okButton;
    Button cancel;
    std::string returnValue;
    Button *showButton;
    bool show;
};