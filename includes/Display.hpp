#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <iostream>
#include <ncurses.h>
#include <iostream>

class Display
{
  public:
	Display(void);
	Display(Display const &src);
	~Display(void);
	void print(int x, int y, int color,std::string toDisplay) const;


	//Display &operator=(Display const &rhs);
    private:
};

#endif
