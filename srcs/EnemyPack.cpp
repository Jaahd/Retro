#include "EnemyPack.hpp"

EnemyPack::EnemyPack(void) : _current(0x0), _count(0)
{
}

EnemyPack::EnemyPack(EnemyPack const &src)
{
	*this = src;
}

EnemyPack::~EnemyPack()
{
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
	_current[_count++] = m;
	return _count;
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
		else if (i == n)
			delta = 1;
	}
	if (_current)
		delete[] _current;
	_current = tmp;
	_current--;
	return _count;
}
