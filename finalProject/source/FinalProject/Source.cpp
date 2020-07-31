#include "ContorlsLibrary.hpp"
int main(int argc, char **argv)
{
	BorderDoubleLineStyle db;
	BorderSingleLineStyle sb;

	Panel p(0, 0, &db, Color::Black, Color::White);

	Label l("Test Label.", 20, 0, 22, Color::Black, Color::Red, &sb);
	p.addControl(&l);

	CheckList cl(1, 5, 15, &db, Color::Black, Color::Red, Color::Blue, "Checklist");
	cl.addItemToList("testing", &sb);
	cl.addItemToList("my", &sb);
	cl.addItemToList("list", &sb);
	cl.addItemToList("checklist", &sb);
	p.addControl(&cl);

	ComboBox cb(30, 5, 15, &db, Color::Black, Color::Orange, Color::Blue);
	cb.addingToList("This", &sb);
	cb.addingToList("is", &sb);
	cb.addingToList("a", &sb);
	cb.addingToList("Combo", &sb);
	p.addControl(&cb);

	MessageBoxPopup msb(20, 30, 20, &db, Color::Black, Color::Orange, "the meaning of life ");
	Button b("Show MessageBox", 1, 30, 15, Color::Black, Color::Cyan, &db, &msb, 1);
	msb.setActionButton(&b);
	p.addControl(&b);
	p.addControl(&msb);

	NumericBox nm(1, 40, 10, 0, &sb, Color::Black, Color::Cyan);
	p.addControl(&nm);

	RadioBox rb("Radio GaGa", 40, 50, 25, &db, Color::Black, Color::Purple, Color::Green);
	rb.addItemToList("ALL WE NEED IS", &sb);
	rb.addItemToList("NO STUPID CMD PROGRAMS", &sb);
	p.addControl(&rb);

	TextBox tb(1, 50, 10, &db, Color::Red, Color::White);
	p.addControl(&tb);

	EventEngine e;
	e.run(p);
}
