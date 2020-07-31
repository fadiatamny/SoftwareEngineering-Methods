#include "../Common/Graphics.hpp"
#include "../Controls/Panel.hpp"
#include "../Controls/TextBox.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"
#include "../Common/Border/BorderSingleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	BorderSingleLineStyle sb;

	Panel p(0, 0, &db, Color::Cyan, Color::Purple);
	TextBox tb(3, 3, 10, &db, Color::White, Color::White);

	p.addControl(&tb);
	Control::setFocus(p);
	EventEngine e;
	e.run(p);
}