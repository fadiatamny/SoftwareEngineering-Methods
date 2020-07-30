#include "../Common/Graphics.hpp"
#include "../Controls/Panel.hpp"
#include "../Controls/CheckList.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"
#include "../Common/Border/BorderSingleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	BorderSingleLineStyle sb;

	Panel p(0, 0, &db, Color::Cyan, Color::Purple);
	CheckList cl(3, 3, 10, &db, Color::Cyan, Color::White, "testing");
	cl.addItemToList("Testing", &sb);
	cl.addItemToList("A stupid", &sb);
	cl.addItemToList("List.", &sb);

	p.addControl(&cl);
	Control &c = p;
	EventEngine e;
	e.run(c);
}