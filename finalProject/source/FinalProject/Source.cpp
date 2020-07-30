#include "../Common/Graphics.hpp"
#include "../Controls/Panel.hpp"
#include "../Controls/CheckBox.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"
#include "../Common/Border/BorderSingleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	BorderSingleLineStyle sb;

	Panel p(0, 0, &db, Color::Cyan, Color::Purple);
	CheckBox cb(3, 1, 10, &db, Color::Cyan, Color::White, "Test", nullptr);
	p.addControl(&cb);
	Control::setFocus(p);
	EventEngine e;
	e.run(p);
}