#pragma once
#include "Graphics.hpp"
#include <vector>
#include "Observer.hpp"
#include "./Border/Border.hpp"

class Control : public Observer
{
public:
	Control(short left, short top, short width, short height, Border *border, Color text, Color backgroundColor) : left(left), top(top), width(width), height(height), border(border), color(color), backgroundColor(backgroundColor), shown(true){};
	static Control *getFocus() { return focus; };
	static void setFocus(Control &control)
	{
		if (control.canGetFocus())
			focus = &control;
	};

	virtual void draw(Graphics &g, int x, int y, size_t z);
	virtual void keyDown(int keyCode, char charecter){};
	virtual bool canGetFocus() { return false; };
	~Control(){};

	bool isShown() const { return this->shown; };
	short getWidth() const { return this->width; };
	short getHeight() const { return this->height; };
	short getLeft() const { return this->left; };
	short getTop() const { return this->top; };
	void setLeft(const short val) { this->left = val; };
	void setTop(const short val) { this->top = val; };
	void setHeight(const short val) { this->height = val; };
	void setWidth(const short val) { this->width = val; };
	Color getColor() const { return this->color; };
	Color getBackgroundColor() const { return this->backgroundColor; };
	Border *getBorder() const { return this->border; };
	void setColor(const Color val) { this->color = val; }
	void setBackgroundColor(const Color val) { this->backgroundColor = val; };
	void setBorder(Border *val) { this->border = val; };
	void setShown(const bool val) { this->shown = val; };
	virtual int getFocusIndex() { return -1; };

	virtual void getAllControls(std::vector<Control *> *controls){};

protected:
	short left;
	short top;
	short width;
	short height;
	Border *border;
	Color color;
	Color backgroundColor;
	bool shown;

private:
	static Control *focus;
};
