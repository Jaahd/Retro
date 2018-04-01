#include <unistd.h>
#include "Environment.hpp"

Environment::Environment(void)
{
    initscr();
    cbreak();

    keypad(stdscr, TRUE);
    //timeout(0);
    nodelay(stdscr, 1);
    noecho();
    curs_set(0);
    getmaxyx(stdscr, this->_h, this->_w);
    if (_w > 80)
    {
        _w = 80;
        resizeterm(_h, _w);
    }
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
    flushinp();

    if (key == 27)
        this->_active = false;
    else if (key == 410)
    {
        getmaxyx(stdscr, this->_h, this->_w);
        this->_player.setY(this->_h - 2);
    }

    this->_player.event(key, this->_w);
}
void Environment::printAll()
{
    if (this->_player.getPv() == 0)
    {
        clear();

        mvprintw(20, 10, "  __ _  __ _ _ __ ___   ___    _____   _____ _ __");
        mvprintw(21, 10, " / _` |/ _` | '_ ` _ \\ / _ \\  / _ \\ \\ / / _ \\ '__|");
        mvprintw(22, 10, "| (_| | (_| | | | | | |  __/ | (_) \\ V /  __/ |");
        mvprintw(23, 10, " \\__, |\\__,_|_| |_| |_|\\___|  \\___/ \\_/ \\___|_|");
        mvprintw(24, 10, " __/ |");
        mvprintw(25, 10, "|___/");

        refresh();
        sleep(5);
        _active = false;
    }
    this->_enemies.event(this->_w, this->_h);
    this->checkCollisions();
    clear();
    box(stdscr, 0, 0);
    mvprintw(0, 1, "Score: %d", _player.getScore());
    mvprintw(1, 1, "HP: %d", _player.getPv());
    this->_player.print("/=A=\\");
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
        if (currMissile->getY() - currMissile->getSpeed() <= 0)
        {
            nbMissiles = this->_player.getMissiles().deleteOne(i);
            return;
        }
    }
}

int Environment::checkCollisions(void)
{
    MissilePack &missiles = _player.getMissiles();
    int nbEnemies = this->_enemies.getCount();
    for (int i = 0; i < nbEnemies; i++)
    {
        int hit = this->_enemies.getOne(i)->checkHit(missiles, _player);
        if (hit)
        {
            this->_enemies.getOne(i)->setPv(this->_enemies.getOne(i)->getPv() - 1);
            if (this->_enemies.getOne(i)->getPv() == 0 || hit == 3)
                this->_enemies.deleteOne(i);
            return 1;
        }
    }
    return 0;
}
PlayerShip Environment::getPlayer(void) const
{
    return this->_player;
}

Environment &Environment::operator=(Environment const &rhs)
{
    this->_h = rhs.getH();
    this->_w = rhs.getW();
    this->_active = rhs.isActive();
    this->_player = rhs.getPlayer();
    return *this;
}
