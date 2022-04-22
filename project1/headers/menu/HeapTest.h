#pragma once
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "../structures/Heap.h"
#include "autoTests/AutoHeapTest.h"
class HeapTest
{
public:
	HeapTest();
	~HeapTest();
private:
	DataStructures::Heap<int>* testHeap = new DataStructures::Heap<int>();
	AutoHeapTest* autoTest = new AutoHeapTest(testHeap);
	bool isFinished = false;
	void printOptions();
	int getOption();
	void chooseOption(int option);
	int getIndex();
	int getElement();
	void get();
	void findIndex();
	void add();
	void removeRoot();
	void getSize();
	void print();
	void automate();
};
