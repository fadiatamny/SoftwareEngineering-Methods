#pragma once
#include <vector>
#include "./CheckBox.hpp"
#include "./Panel.hpp"

class CheckList : public Panel {
     public:
        CheckList (short x,short y,short width, Border* border ,Color colorText, Color color,std::string text);
        ~CheckList();
};