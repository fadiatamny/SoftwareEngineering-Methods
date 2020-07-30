// #include "MessageBox.hpp"
// #include <iostream>

// MessageBoxPreview::MessageBoxPreview(short left, short top, short width, Border *buttonBorder, Border *border, Color textColor, Color backgroundColor, std::string message, std::string ok, std::string cancel, Button *showButton) : Panel(left + 5, top + 5, border, textColor, backgroundColor),
//                                                                                                                                                                                                                                message(Label(message, (width - message.size()) / 2, 0, message.size(), textColor, backgroundColor, buttonBorder)),
//                                                                                                                                                                                                                                okButton(Button(ok, 0, 4, ok.size(), Color::White, Color::Green, buttonBorder, this)),
//                                                                                                                                                                                                                                cancel(Button(cancel, width - cancel.size() - 2, 4, 5, Color::White, Color::Red, buttonBorder, this)),
//                                                                                                                                                                                                                                showButton(showButton),
//                                                                                                                                                                                                                                returnValue(""),
//                                                                                                                                                                                                                                show(true)
// {
//     this->addControl(&this->message);
//     this->addControl(&this->okButton);
//     this->addControl(&this->cancel);
// }

// std::string MessageBoxPreview::getMessage()
// {
//     return message.getValue();
// }

// void MessageBoxPreview::setMessage(std::string message)
// {
//     this->message.setValue(message);
// }

// void MessageBoxPreview::setShowButton(Button *button)
// {
//     this->showButton = button;
// }

// void MessageBoxPreview::draw(Graphics &g, int x, int y, size_t z)
// {
//     int relativeX, relativeY;

//     if (z == 0 && this->show == true)
//     {
//         Panel::draw(g, x, y, z);
//         relativeX = message.getLeft();
//         relativeY = message.getTop();

//         if (message.isShown())
//             message.draw(g, x + relativeX + 1, y + relativeY + 1, z);
//         relativeX = okButton.getLeft();
//         relativeY = okButton.getTop();
//         if (okButton.isShown())
//             okButton.draw(g, x + relativeX + 1, y + relativeY + 1, z);
//         relativeX = cancel.getLeft();
//         relativeY = cancel.getTop();
//         if (cancel.isShown())
//             cancel.draw(g, x + relativeX + 1, y + relativeY + 1, z);
//     }
// }

// void MessageBoxPreview::notify(std::string text)
// {
//     if (text == "OK")
//     {
//         cancel.setShown(false);
//         cancel.setActive(false);
//         returnValue = text;
//     }

//     if (text == "CANCEL")
//     {
//         this->setShown(false);
//         cancel.setShown(false);
//         cancel.setActive(false);
//         okButton.setShown(false);
//         okButton.setActive(false);
//         message.setShown(false);
//         returnValue = text;
//     }

//     returnValue = "";
// }