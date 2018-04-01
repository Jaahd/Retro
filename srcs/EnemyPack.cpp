#include <ctime>
#include <sstream>
#include "EnemyPack.hpp"

EnemyPack::EnemyPack(void) : _current(0x0), _count(0)
{
    srand(time(NULL));
}

EnemyPack::EnemyPack(EnemyPack const &src)
{
	*this = src;
}

EnemyPack::~EnemyPack()
{
	if (!_current)
		return;
	for (int i = 0; i < _count; i++)
	{
		delete _current[i];
	}
	delete[] _current;
}

Enemy **EnemyPack::getValue(void) const
{
	return this->_current;
}

EnemyPack &EnemyPack::operator=(EnemyPack const &rhs)
{

	this->_current = rhs.getValue();
    this->_count = rhs.getCount();
	return *this;
}

int EnemyPack::getCount(void) const
{
	return this->_count;
}

Enemy *EnemyPack::getOne(int n) const
{
	if (n < 0 || n > _count)
		return NULL;
	return _current[n];
}
void EnemyPack::randomChump(int width)
{
    int pop = rand() % 4;
	std::string *tab= new std::string[4];
	tab[0] = "V";
	tab[1] = "\\/";
	tab[2] = "\\V/";
	tab[3] = "'\\/'";
	tab[4] = "\\=V=/";
    if (pop == 1)
    {
    	int size = (rand() % 5 )+ 1;
    	int x = rand() % (width - size - 2) + 2;
        Enemy *enemy = new Enemy(x, 0, size, 1, size, tab[size - 1]);
        this->push(enemy);
    }
}

void EnemyPack::event(int width, int height)
{
	for (int i = 0; i < _count; i++)
	{
		if(_current[i]->getY() +  _current[i]->getSpeed() >= height - 1)
		{
			this->deleteOne(i);
			break;
		}
	}
    this->randomChump(width);

}
void EnemyPack::printAll(void)
{
    //mvprintw(2, 2, "enemies %d", this->_count);
    for (int i = 0; i < this->_count; i++)
        this->_current[i]->print();
}

int EnemyPack::push(Enemy *m)
{
	Enemy **tmp;
	if (!m)
		return _count;
	tmp = new Enemy *[_count + 1];
	for (int i = 0; i < _count; i++)
	{
		tmp[i] = _current[i];
	}
	if (_current)
		delete[] _current;
	_current = tmp;
	_current[_count] = m;
	_count++;
	return _count;
}

Enemy *EnemyPack::getOne(int n) const
{
	if (n < 0 || n > _count)
		return NULL;
	return _current[n];
}

int EnemyPack::deleteOne(int n)
{
	Enemy **tmp;
	int delta = 0;

	if (n < 0)
		return _count;
	tmp = new Enemy *[_count - 1];
	for (int i = 0; i < _count; i++)
	{
		if (i != n)
			tmp[i - delta] = _current[i];
		else
		{
			delete _current[i];
			delta = 1;
		}
	}
	if (_current)
		delete[] _current;
	_current = tmp;
	_count--;
	return _count;
}

void EnemyPack::event(int width, int height)
{
	for (int i = 0; i < _count; i++)
	{
		if(_current[i]->getY() > height)
			this->deleteOne(i);
	}
    this->randomChump(width);

}
void EnemyPack::printAll(void)
{
    for (int i = 0; i < this->_count; i++)
        this->_current[i]->print();
}

void EnemyPack::randomChump(int width)
{
    int x = rand() % (width - 1);
    int pop = rand() % 40;
	std::string *tab= new std::string[4];
	tab[0] = "V";
	tab[1] = "\\/";
	tab[2] = "\\V/";
	tab[3] = "'\\/'";
	tab[4] = "\\=V=/";
    if (pop == 1)
    {
        int size = (rand() % 5 )+ 1;
        Enemy *enemy = new Enemy(x, 0, size, 1, size, tab[size - 1]);
        this->push(enemy);
    }
}


EnemyPack &EnemyPack::operator=(EnemyPack const &rhs)
{

	this->_current = rhs.getCurrent();
    this->_count = rhs.getCount();
	return *this;
}

Enemy **EnemyPack::getCurrent(void) const
{
	return this->_current;
}

int EnemyPack::getCount(void) const
{
	return this->_count;
}
