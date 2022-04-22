#pragma once
#include <iostream>
#include <iomanip>
#include<cstdlib>
#include<ctime>
#include <stdexcept>
#include "../../structures/RBTree.h"
#include "../../other/Timer.h"
#include "StructureInit.h"
class AutoTreeTest
{
public:
	AutoTreeTest(DataStructures::RBTree<int>* testTree);
	~AutoTreeTest();
	void run();
private:
	DataStructures::RBTree<int>* testTree;
	StructureInit* init = new StructureInit;
	Timer* timer = new Timer;
	std::ofstream resultFile;
	std::string fileName = "output/treeResults.csv";
	bool isFinished = false;
	const int iterationsNumber = 500;
	const int searchValue = 1;
	void printOptions();
	int getOption();
	void chooseOption(int option);
	size_t getSize();
	int getMaxValue();
	void autoTest();
	void find(size_t size);
	void add(size_t size);
	void remove(size_t size);
	void fillFromFile();
	void fillRand();
	void fillRand(size_t size, int maxValue);
	void createRandFile();
};
