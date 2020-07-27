#include "../Common/Graphics.hpp"
#include "../Controls/Label.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	Label l("Test", 0, 15, 10, Color::Black, Color::Blue, &db);
	Control &l2 = l;
	EventEngine e;
	e.run(l);
}