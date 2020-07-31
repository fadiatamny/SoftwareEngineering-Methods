#include "../Common/Graphics.hpp"
#include "../Controls/Panel.hpp"
#include "../Controls/MessageBoxPopup.hpp"
#include "../Controls/Button.hpp"
#include "../Common/EventEngine.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"
#include "../Common/Border/BorderSingleLineStyle.hpp"

int main(int argc, char **argv)
{
    BorderDoubleLineStyle db;
    BorderSingleLineStyle sb;

    Panel p(0, 0, &db, Color::Cyan, Color::Purple);
    MessageBoxPopup mbp(3, 10, 10, &db, Color::White, Color::White, "TextBox Wooo", nullptr);
    Button b("testmeee", 0, 5, 10, Color::Blue, Color::Blue, &db, &mbp);
    mbp.setShowButton(&b);
    p.addControl(&b);
    p.addControl(&mbp);
    Control::setFocus(p);
    EventEngine e;
    e.run(p);
}