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
	getmaxyx(stdscr, this->_h, this->_w);
	//start_color();
	this->_player.setY(this->_h - 2);
	this->_active = true;
	return;
}

Environment::~Environment(void)
{

	endwin();
	std::cout << this->_h << " height and " << this->_w << " width\n";
	return;
}

Environment::Environment(Environment const &src)
{
	*this = src;
	return;
}

unsigned int Environment::getW(void) const
{
	return this->_w;
}

unsigned int Environment::getH(void) const
{
	return this->_h;
}

bool Environment::isActive(void) const
{
	return (this->_active);
}

void Environment::handleKey(int key, int elapsed_time)
{
	if (key == ERR)
		refresh();
	if (key == 27)
		this->_active = false;
	else if (key == 410)
	{
		getmaxyx(stdscr, this->_h, this->_w);
		this->_player.setY(this->_h - 2);
	}
	this->_player.event(key, this->_w);
}
void Environment::printAll(int elapsed_time) const
{
	clear();
	this->_player.print('A', elapsed_time);
	for (int i = 0; i < this->_missiles.getCount(); i++)
    	this->_missiles.getOne(i)->print('.', elapsed_time);

	refresh();
	return;
}
void Environment::print(int x, int y, int toDisplay) const
{

	attron(COLOR_PAIR(1));
	mvaddch(y, x, toDisplay);
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
	this->_h = rhs.getH();
	this->_w = rhs.getW();
	this->_active = rhs.isActive();
	return *this;
}
