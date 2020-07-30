#include "../Common/Graphics.hpp"
#include "../Controls/Panel.hpp"
#include "../Controls/ComboBox.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"
#include "../Common/Border/BorderSingleLineStyle.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	BorderSingleLineStyle sb;

	Panel p(0, 0, &db, Color::Cyan, Color::Purple);
	ComboBox cb(3, 3, 10, &db, Color::Cyan, Color::White);
	cb.addingToList("Testing", &sb);
	cb.addingToList("A stupid", &sb);
	cb.addingToList("List.", &sb);

	p.addControl(&cb);
	Control &c = p;
	EventEngine e;
	e.run(c);
}