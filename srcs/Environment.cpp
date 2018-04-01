#include "Environment.hpp"

Environment::Environment(void)
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    timeout(0);
     nodelay(stdscr, 1);
    noecho();
    curs_set(0);
    getmaxyx(stdscr, this->_h, this->_w);
    //start_color();
    this->_player.setY(this->_h - 5);
    this->_active = true;
    return;
}

Environment::~Environment(void)
{

    endwin();
    //std::cout << this->_h << " height and " << this->_w << " width\n";
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

void Environment::handleKey(int key)
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
    flushinp();
}
void Environment::printAll()
{
    this->_enemies.event(this->_w);
    clear();
    this->checkCollisions();
    //box(stdscr, 0, 0);
    // this->checkCollisions();
    this->_player.print('A');
    this->_player.getMissiles().printAll();
    this->_enemies.printAll();
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
void Environment::removeObjects()
{
    int nbMissiles = this->_player.getMissiles().getCount();
    for (int i = 0; i < nbMissiles; i++)
    {
        Missile *currMissile = this->_player.getMissiles().getOne(i);
        if (currMissile->getY() < 0)
        {
            nbMissiles = this->_player.getMissiles().deleteOne(i);
            return;
        }
    }

}

void Environment::checkCollisions(void)
{
    //mvprintw(5, 2, "check coll");
    MissilePack &missiles = _player.getMissiles();
    int nbEnemies = this->_enemies.getCount();
  //  mvprintw(6, 2, "ng Enemies {%d}", nbEnemies);
	for (int i = 0; i < nbEnemies; i++)
	{
		if (this->_enemies.getOne(i)->checkHit(missiles, _player))
        {
            this->_enemies.deleteOne(i);
            return ;
        }
	}
}
PlayerShip &Environment::getPlayer(void)
{
    return this->_player;
}

Environment &Environment::operator=(Environment const &rhs)
{
    //add equality
    this->_h = rhs.getH();
    this->_w = rhs.getW();
    this->_active = rhs.isActive();
    return *this;
}
