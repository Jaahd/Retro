#include "Environment.hpp"

Environment::Environment(void)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	timeout(50);
	// nodelay(stdscr, 1);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, _h, _w);
	start_color();
	_player.setY(_h - 2);
	_active = true;
	return;
}

Environment::~Environment(void)
{

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
	{
		getmaxyx(stdscr, _h, _w);
		_player.setY(_h - 2);
	}
	_player.event(key, _w);
}
void Environment::printAll(void) const
{
	clear();
	_player.print();
	refresh();
	return;
}
void Environment::print(int x, int y) const
{

	attron(COLOR_PAIR(1));
	mvaddch(y, x, 97);
	attroff(COLOR_PAIR(1));

	refresh();

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
