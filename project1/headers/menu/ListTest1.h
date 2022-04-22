#pragma once
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "../structures/List.h"
#include "autoTests/AutoListTest.h"
class ListTest1
{
public:
	ListTest1();
	~ListTest1();
private:
	DataStructures::List<int>* testList = new DataStructures::List<int>();
	AutoListTest* autoTest = new AutoListTest(testList);
	bool isFinished = false;
	void printOptions();
	int getOption();
	void chooseOption(int option);
	int getIndex();
	int getElement();
	void get();
	void findIndex();
	void add();
	void addEnd();
	void addFront();
	void remove();
	void removeFront();
	void removeEnd();
	void getSize();
	void print();
	void automate();
};
