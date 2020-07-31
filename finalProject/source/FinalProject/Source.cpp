#include "ContorlsLibrary.hpp"

int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	BorderSingleLineStyle sb;

	Panel p(0, 0, &db, Color::Black, Color::White);

	Label l("Test Label.", 20, 0, 22, Color::Black, Color::Red, &sb);
	p.addControl(&l);

	CheckList cl(1, 4, 15, &db, Color::Black, Color::Red, Color::Blue, "Checklist");
	cl.addItemToList("testing", &sb);
	cl.addItemToList("my", &sb);
	cl.addItemToList("list", &sb);
	cl.addItemToList("checklist", &sb);
	p.addControl(&cl);

	ComboBox cb(50, 5, 15, &db, Color::Black, Color::Orange, Color::Blue);
	cb.addingToList("This", &sb);
	cb.addingToList("is", &sb);
	cb.addingToList("a", &sb);
	cb.addingToList("Combo", &sb);
	p.addControl(&cb);

	MessageBoxPopup msb();
	// NumericBox nm();
	// RadioBox rb();
	// TextBox tb();
	EventEngine e;
	e.run(p);
}