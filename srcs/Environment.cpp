#include "Environment.hpp"

Environment::Environment(void)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	timeout(1000);
	// nodelay(stdscr, 1);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, _h, _w);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	// _win = subwin(stdscr, _h, _w, 0, 0);
	// start_color();
	// init_pair(1, COLOR_WHITE, COLOR_WHITE);
	// wbkgd(stdscr, COLOR_PAIR(1));
	// box(stdscr, 0, 0); /* 0, 0 gives default characters
	// 				 * for the vertical and horizontal
	// 				 * lines			*/

	refresh(); /* Show that box 		*/
	// init_pair(1, COLOR_WHITE, COLOR_BLACK);
	// wbkgd(stdscr, COLOR_PAIR(1));
	_active = true;
	return;
}

Environment::~Environment(void)
{
	// wborder(_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	// wrefresh(_win);
	// delwin(_win);
	endwin();
	std::cout << _h << " height and " << _w << " width\n";
	return;
}

Environment::Environment(Environment const &src)
{
	*this = src;
	return;
}

unsigned int Environment::getW(void) const
{
	return _w;
}

unsigned int Environment::getH(void) const
{
	return _h;
}

bool Environment::isActive(void) const
{
	return (_active);
}

void Environment::handleKey(int key)
{
	if (key == ERR)
		refresh();
	if (key == 27)
		_active = false;
	else if (key == 410)
		getmaxyx(stdscr, _h, _w);
	_player.event(key, _w);
}
void Environment::printAll(void) const
{

	// wclear(_win);
	clear();
	this->print(_player.getX(), _h - 2);
	return;
}
void Environment::print(int x, int y) const
{

	attron(COLOR_PAIR(1));
	mvaddch(y, x, 97);
	attroff(COLOR_PAIR(1));
	// wmove(_win, y, x);
	refresh();

	// if (local_win)
	// {
	// 	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	// 	wrefresh(local_win);
	// 	delwin(local_win);
	// }
	// char cBlock = (char)0x2588;
	// addch(cBlock);
	// local_win = subwin(stdscr, 2, 4, y, x);
	// init_pair(2, COLOR_WHITE, COLOR_WHITE);
	// wbkgd(local_win, COLOR_PAIR(2));
	// box(local_win, 0, 0); /* 0, 0 gives default characters
	// 				 * for the vertical and horizontal
	// 				 * lines			*/
	// wrefresh(local_win);  /* Show that box 		*/
	return;
}

// void Environment::checkCollisions(EnemyPack &enemies, MissilePack &missiles, PlayerShip &player);
// {
// 	for (int i = 0; i < enemies.getCount(); i++)
// 	{
// 		enemies.getOne().checkHit(missiles, player);
// 	}
// }

Environment &Environment::operator=(Environment const &rhs)
{
	//add equality
	_h = rhs.getH();
	_w = rhs.getW();
	_active = rhs.isActive();
	return *this;
}
