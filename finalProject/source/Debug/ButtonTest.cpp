#include "../Common/Graphics.hpp"
#include "../Controls/Button.hpp"
#include "../Controls/Panel.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	Panel p(0, 0, &db, Color::Cyan, Color::Purple);

	Button b("test", 0, 15, 10, Color::Blue, Color::Blue, &db, nullptr);
	p.addControl(&b);
	Control &c = p;
	EventEngine e;
	e.run(c);
}