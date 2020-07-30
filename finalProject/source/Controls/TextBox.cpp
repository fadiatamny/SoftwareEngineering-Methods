// #include "TextBox.hpp"

// TextBox::TextBox(short left, short top, short width, Border *border, Color textColor, Color backgroundColor) : Label("", left, top, width, textColor, backgroundColor, border)
// {
//     auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
//     currentCoord = {(short)(left + 1 + value.length()), (short)(top + 1)};
//     SetConsoleCursorPosition(handle, currentCoord);
// };

// void TextBox::setText(std::string text)
// {
//     if (text.length() <= this->width)
//         value = text;
// };

// void TextBox::keyDown(int keyCode, char character)
// {
//     int textWidth = this->value.length();
//     auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

//     if ((keyCode >= 0x30 && keyCode <= 0x7A) || keyCode == VK_SPACE)
//     {
//         if (textWidth >= this->width)
//             return;
//         auto offset = currentCoord.X - this->left;
//         std::string s;
//         s += character;
//         ++currentCoord.X;
//         value.insert(offset - 1, &character);
//     }
//     else if (keyCode == VK_LEFT || keyCode == VK_RIGHT)
//     {
//         auto offset = currentCoord.X - this->left;
//         if (offset - 1 > 0 && keyCode == VK_LEFT)
//         {
//             --currentCoord.X;
//             SetConsoleCursorPosition(handle, currentCoord);
//         }
//         else if (offset - 1 < textWidth && keyCode == VK_RIGHT)
//         {
//             ++currentCoord.X;
//             SetConsoleCursorPosition(handle, currentCoord);
//         }
//     }
//     else if (textWidth > 0 && (keyCode == VK_BACK || keyCode == VK_DELETE))
//     {
//         auto offset = currentCoord.X - this->left;
//         if (keyCode == VK_DELETE && offset - 1 < this->value.length())
//             this->value.erase(this->value.begin() + offset - 1);

//         else if (keyCode == VK_BACK && this->value.length() > 0)
//         {
//             if (offset - 1 > 0)
//             {
//                 this->value.erase(this->value.begin() + offset - 2);
//                 --currentCoord.X;
//             }
//         }
//     }
// };

// void TextBox::draw(Graphics &g, int x, int y, size_t z)
// {
//     Label::draw(g, x + 1, y + 1, z);
//     g.moveTo(currentCoord.X + 2, currentCoord.Y + 2);
//     g.setCursorVisibility(true);
// };