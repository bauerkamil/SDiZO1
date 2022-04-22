#pragma once
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "../structures/RBTree.h"
#include "autoTests/AutoTreeTest.h"
class TreeTest
{
public:
	TreeTest();
	~TreeTest();
private:
	DataStructures::RBTree<int>* testTree = new DataStructures::RBTree<int>();
	AutoTreeTest* autoTest = new AutoTreeTest(testTree);
	bool isFinished = false;
	void printOptions();
	int getOption();
	void chooseOption(int option);
	int getElement();
	void find();
	void add();
	void remove();
	void print();
	void automate();
};
