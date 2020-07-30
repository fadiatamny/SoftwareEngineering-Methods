#include "MessageBox.hpp"
#include <iostream>

using namespace std;
MessageBox::MessageBox(short left, short top, short width, Border *buttonBorder, Border *border, Color textColor, Color backgroundColor, string message, string ok, string cancel, Button *showButton) : Panel(left + 5, top + 5, border, textColor, backgroundColor),
                                                                                                                                                                                                         message(Label(message, (width - message.size()) / 2, 0, message.size(), textColor, backgroundColor, buttonBorder)),
                                                                                                                                                                                                         okButton(Button(ok, 0, 4, ok.size(), Color::White, Color::Green, buttonBorder, this)),
                                                                                                                                                                                                         cancel(Button(cancel, width - cancel.size() - 2, 4, 5, Color::White, Color::Red, buttonBorder, this)),
                                                                                                                                                                                                         showButton(showButton)
{
    Panel::addControl(&this->message);
    Panel::addControl(&this->okButton);
    Panel::addControl(&this->cancel);
    returnValue = "";
    show = true;
}

string MessageBox::getMessage()
{
    return message.getValue();
}

void MessageBox::setMessage(string message)
{
    this->message.setValue(message);
}

void MessageBox::setShowButton(Button *button)
{
    this->showButton = button;
}

void MessageBox::draw(Graphics &g, int x, int y, size_t z)
{
    int relativeX, relativeY;

    if (z == 0 && this->show == true)
    {
        Panel::draw(g, x, y, z);
        relativeX = message.getLeft();
        relativeY = message.getTop();

        if (message.getShow())
            message.draw(g, x + relativeX + 1, y + relativeY + 1, z);
        relativeX = okButton.getLeft();
        relativeY = okButton.getTop();
        if (okButton.getShow())
            okButton.draw(g, x + relativeX + 1, y + relativeY + 1, z);
        relativeX = cancel.getLeft();
        relativeY = cancel.getTop();
        if (cancel.getShow())
            cancel.draw(g, x + relativeX + 1, y + relativeY + 1, z);
    }
}

void MessageBox::notify(string text)
{
    if (text == "OK")
    {
        cancel.setShow(false);
        cancel.setCanClick(false);
        returnValue = text;
    }

    if (text == "CANCEL")
    {
        this->setShow(false);
        cancel.setShow(false);
        cancel.setCanClick(false);
        okButton.setShow(false);
        okButton.setCanClick(false);
        message.setShow(false);
        returnValue = text;
    }

    returnValue = "";
}