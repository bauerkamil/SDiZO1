#pragma once
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "../structures/Array.h"
#include "autoTests/AutoArrTest.h"
class ArrayTest
{
public:
	ArrayTest();
	~ArrayTest();
private:
	DataStructures::Array<int>* testArray = new DataStructures::Array<int>();
	AutoArrTest* autoTest = new AutoArrTest(testArray);
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
