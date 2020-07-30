#include "../Common/Graphics.hpp"
#include "../Controls/Panel.hpp"
#include "../Controls/RadioBox.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"
#include "../Common/Border/BorderSingleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	BorderSingleLineStyle sb;

	Panel p(0, 0, &db, Color::Cyan, Color::Purple);
	RadioBox rb("radiooooo",3, 3, 10, &db, Color::White, Color::White);
	rb.addItemToList("Testing", &sb);
	rb.addItemToList("A stupid", &sb);
	rb.addItemToList("List.", &sb);

	p.addControl(&rb);
	Control::setFocus(p);
	EventEngine e;
	e.run(p);
}