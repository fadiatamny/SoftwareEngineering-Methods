#include "../Common/Graphics.hpp"
#include "../Controls/Panel.hpp"
#include "../Controls/Label.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	Panel p(0, 0, &db, Color::Cyan, Color::Purple);

	Label l1("Test", 3, 2, 1, Color::Black, Color::Blue, &db);
	Label l2("Test", 3, 35, 1, Color::Black, Color::Blue, &db);

	p.addControl(&l1);
	p.addControl(&l2);

	Control &c = p;
	EventEngine e;
	e.run(c);
}