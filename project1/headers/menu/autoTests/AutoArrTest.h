#pragma once
#include <iostream>
#include <iomanip>
#include<cstdlib>
#include<ctime>
#include <stdexcept>
#include "../../structures/Array.h"
#include "../../other/Timer.h"
#include "StructureInit.h"
class AutoArrTest
{
public:
	AutoArrTest(DataStructures::Array<int>* testArray);
	~AutoArrTest();
	void run();
private:
	DataStructures::Array<int>* testArray;
	StructureInit* init = new StructureInit;
	Timer* timer = new Timer;
	std::ofstream resultFile;
	std::string fileName = "output/arrResults.csv";
	bool isFinished = false;
	const int iterationsNumber = 100;
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
