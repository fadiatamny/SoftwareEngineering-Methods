#pragma once
#include "../Graphics.hpp"
#include <iostream>

class Border
{
public:
    Border(char horizontal, char vertical, char cornerA, char cornerB, char cornerC, char cornerD) : cornerA(cornerA), cornerB(cornerB), cornerC(cornerC), cornerD(cornerD), horizontal(horizontal), vertical(vertical){};
    void draw(Graphics &g, short x, short y, short height, short width);

private:
    char cornerA, cornerB, cornerC, cornerD, horizontal, vertical;
};