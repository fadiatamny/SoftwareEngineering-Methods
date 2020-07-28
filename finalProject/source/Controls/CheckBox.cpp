#include "CheckBox.hpp"

CheckBox::draw(Graphics &g,int x,int y,size_t z)[
    std::string select = "[x] ";
    std:: string notSelect = "[ ] ";
    if(selected)
        setValue(selected + value);
    else
        setValue(notSelect + vlaue);
    Label::draw(g,left,top,z);
]