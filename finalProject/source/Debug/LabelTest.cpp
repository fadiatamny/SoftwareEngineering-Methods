#include "../Common/Graphics.hpp"
#include "../Controls/Panel.hpp"
#include "../Controls/Label.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	Panel p(0, 0, &db, Color::Cyan, Color::Purple);
	Label l("Test", 0, 15, 10, Color::Black, Color::Blue, &db);
	p.addControl(&l);
	EventEngine e;
	e.run(p);
}