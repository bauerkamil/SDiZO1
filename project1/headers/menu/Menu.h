#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>

#include "ArrayTest.h"
#include "ListTest1.h"
#include "HeapTest.h"
#include "TreeTest.h"

class Menu
{
public:
	Menu();
	virtual ~Menu();

private:
	bool isFinished;
	void printMenu();
	int getChoice();
	void chooseOption(int choice);
	const int FILL_WIDTH = 100;
};

#endif 