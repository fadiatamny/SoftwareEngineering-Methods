#pragma once
#include <iostream>
#include "./Button.hpp"
#include "./Border/Border.hpp"
#include <string>

class ChackBox :public Button {
    public:
        ChackBox(short x,short y ,short width,Border *border,Color colorText,Color color,std::string title,Observer *ob):
        Button(title,x,y,width,colorText,color,border,ob)
        {
            selected =false;
            value = title;
        };

        void select() {selected =! selected;};

        void draw(Graphics &g,int x,int y,size_t z);
        bool getSelected(return selected);

    private:
        bool selected;
        std::string value;
}