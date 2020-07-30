#pragma once

#include "./Panel.hpp"
#include "./Label.hpp"
#include "./Button.hpp"
#include "../Common/Border/Border.hpp"

class MessageBox : public Panel
{
private:
    Label message;
    Button okButton;
    Button cancel;
    string returnValue;
    Button *showButton;
    bool show;

public:
    string getMessage();
    void setMessage(string message);
    string getReturnValue() { return returnValue; };
    void setShowButton(Button *button);
    void notify(string text);

    virtual void draw(Graphics &g, int x, int y, size_t z);
    MessageBox(short left, short top, short width, BorderDrawer *buttonBorder, BorderDrawer *border, Color textColor, Color backgroundColor, string message, string ok, string cancel, Button *showButton);
    ~MessageBox() {}
};