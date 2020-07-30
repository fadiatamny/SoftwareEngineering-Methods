#include "../Common/Graphics.hpp"
#include "../Controls/Button.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	Button b("test", 0, 15, 10, Color::Blue, Color::Blue, &db, nullptr);
	Control &bc = b;
	EventEngine e;
	e.run(bc);
}