#include "Border.hpp"

void Border::draw(Graphics &g, short x, short y, short height, short width)
{
    std::string borderLine(width, horizontal);
    std::string innerPadding(width, ' ');
    g.moveTo(x, y);
    std::cout << this->cornerA << borderLine << this->cornerB;
    for (int i = 1; i < height - 1; ++i)
    {
        g.moveTo(x, y + i);
        std::cout << this->vertical << innerPadding << this->vertical;
    }
    g.moveTo(x, y + height - 1);
    std::cout << this->cornerC << borderLine << this->cornerD;
}