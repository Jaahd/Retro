#include "Display.hpp"

Display::Display(void)
{
	return;
}

Display::Display(Display const &src)
{
	*this = src;
	return;
}

Display::~Display()
{
	std::cout << "Display destroy\n";
	return;
}

void Display::print(int x, int y, int color, int toDisplay) const
{
	init_pair(1, color, color);
	attron(COLOR_PAIR(1));
	mvaddch(y, x, toDisplay);
	attroff(COLOR_PAIR(1));
	return;
}
// Display &Display::operator=(Display const &rhs)
// {

// 	return *this;
// }
