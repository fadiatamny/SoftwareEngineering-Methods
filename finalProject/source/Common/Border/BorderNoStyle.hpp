#pragma once

#include "./Border.hpp"

class BorderNoStyle : public Border
{
public:
    BorderNoStyle() : Border(0x20, 0x20, 0x20, 0x20, 0x20, 0x20){};
};
