#pragma once
#include <iostream>
#include <iomanip>
#include<cstdlib>
#include<ctime>
#include <stdexcept>
#include "../../structures/List.h"
#include "../../other/Timer.h"
#include "StructureInit.h"
class AutoListTest
{
public:
	AutoListTest(DataStructures::List<int>* testList);
	~AutoListTest();
	void run();
private:
	DataStructures::List<int>* testList;
	StructureInit* init = new StructureInit;
	Timer* timer = new Timer;
	std::ofstream resultFile;
	std::string fileName = "output/listResults.csv";
	bool isFinished = false;
	const int iterationsNumber = 1;
	const int searchValue = -1;
	void printOptions();
	int getOption();
	void chooseOption(int option);
	size_t getSize();
	int getMaxValue();
	void autoTest();
	void get(size_t size);
	void findIndex(size_t size);
	void add(size_t size);
	void addEnd(size_t size);
	void addFront(size_t size);
	void remove(size_t size);
	void removeFront(size_t size);
	void removeEnd(size_t size);
	void fillFromFile();
	void fillRand();
	void fillRand(size_t size, int maxValue);
	void createRandFile();
};
