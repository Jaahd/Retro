#include <iostream>
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
	//std::cout << "Display destroy\n";
	return;
}

void Display::print(int x, int y, int color, std::string toDisplay) const
{
	init_pair(1, color, 0);
	attron(COLOR_PAIR(1));
	mvprintw(y, x, toDisplay.c_str());
	attroff(COLOR_PAIR(1));
	return;
}

// Display &Display::operator=(Display const &rhs)
// {

// 	return *this;
// }
