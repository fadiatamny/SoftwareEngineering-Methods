#include "../Common/Graphics.hpp"
#include "../Controls/Panel.hpp"
#include "../Controls/CheckList.hpp"
#include "../Controls/CheckBox.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"
#include "../Common/Border/BorderSingleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	BorderSingleLineStyle sb;

	Panel p(0, 0, &db, Color::White, Color::Red);
	CheckList cl(3, 3, 10, &db, Color::White, Color::White, "CheckList");
	cl.addItemToList("test", &sb);
	cl.addItemToList("test2", &sb);
	p.addControl(&cl);
	Control::setFocus(p);
	EventEngine e;
	e.run(p);
}