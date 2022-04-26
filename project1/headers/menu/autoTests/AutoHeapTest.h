#pragma once
#include <iostream>
#include <iomanip>
#include<cstdlib>
#include<ctime>
#include <stdexcept>
#include "../../structures/Heap.h"
#include "../../other/Timer.h"
#include "StructureInit.h"
class AutoHeapTest
{
public:
	AutoHeapTest(DataStructures::Heap<int>* testHeap);
	~AutoHeapTest();
	void run();
private:
	DataStructures::Heap<int>* testHeap;
	StructureInit* init = new StructureInit;
	Timer* timer = new Timer;
	std::ofstream resultFile;
	std::string fileName = "output/heapResults.csv";
	bool isFinished = false;
	const int iterationsNumber = 1000;
	const int searchValue = -1;
	void printOptions();
	int getOption();
	void chooseOption(int option);
	size_t getSize();
	int getMaxValue();
	void autoTest();
	void get(size_t size);
	void find(size_t size);
	void add(size_t size);
	void remove(size_t size);
	void fillFromFile();
	void fillRand();
	void fillRand(size_t size, int maxValue);
	void createRandFile();
};
