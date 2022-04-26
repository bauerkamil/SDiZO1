#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "../../headers/menu/autoTests/AutoTreeTest.h"

AutoTreeTest::AutoTreeTest(DataStructures::RBTree<int>* testTree2)
{
	this->testTree = testTree2;
}

AutoTreeTest::~AutoTreeTest()
{
	delete this->timer;
	delete this->init;
}

void AutoTreeTest::run()
{
	this->isFinished = false;
	while (!this->isFinished) {
		printOptions();
		chooseOption(getOption());
	}
}

void AutoTreeTest::printOptions()
{
	std::cout << std::setfill('=') << std::setw(75) << "\n"
		<< "Please choose one of following options : \n"
		<< "1. Auto testing (destroys current data)\n"
		<< "12. Fill from file\n"
		<< "13. Fill with random numbers\n"
		<< "14. Create file with random numbers\n"
		<< "0. Go back" << std::endl;
}

int AutoTreeTest::getOption()
{
	int option;
	std::cin >> option;

	return option;
}

void AutoTreeTest::chooseOption(int option)
{
	switch (option)
	{
	case 1:
	{
		autoTest();
	}
	break;
	case 12:
	{
		fillFromFile();
	}
	break;
	case 13:
	{
		fillRand();
	}
	break;
	case 14:
	{
		createRandFile();
	}
	break;
	case 0:
	{
		this->isFinished = true;
	}
	break;
	default:
		std::cout << "\nPlease try again" << std::endl;
	}
}

size_t AutoTreeTest::getSize()
{
	size_t size;
	std::cout << "Please enter size: ";
	std::cin >> size;
	return size;
}

int AutoTreeTest::getMaxValue()
{
	int maxSize;
	std::cout << "Please enter the max value: ";
	std::cin >> maxSize;
	return maxSize;
}

void AutoTreeTest::autoTest()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	for (int i = 0; i < this->iterationsNumber; i++) {
		this->testTree->clear();
		fillRand(size, maxValue);
		try
		{
			add(size);
			find(size);
			remove(size);
		}
		catch (std::exception& e)
		{
			this->timer->stop();
			std::cout << e.what() << std::endl;
			break;
		}
	}
	this->testTree->clear();
}

void AutoTreeTest::find(size_t size)
{
	this->timer->start();
	int index = this->testTree->find(searchValue);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",find," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoTreeTest::add(size_t size)
{
	this->timer->start();
	this->testTree->add(searchValue);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",add," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoTreeTest::remove(size_t size)
{
	this->timer->start();
	try
	{
		this->testTree->remove(searchValue);
	}
	catch (const std::exception&)
	{
	}
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",remove," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoTreeTest::fillFromFile()
{
	try
	{
		int* array = this->init->readArrFromFile();
		size_t sizeArr = (size_t)array[0];
		this->testTree->addAll(sizeArr, &array[1]);
		delete[] array;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void AutoTreeTest::fillRand()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	fillRand(size, maxValue);
}

void AutoTreeTest::fillRand(size_t size, int maxValue)
{
	int* treeArr = this->init->generateRandArr(size, maxValue);
	this->testTree->addAll(size, treeArr);
	delete[] treeArr;
}

void AutoTreeTest::createRandFile()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	this->init->saveRandArrToFile(size, maxValue);
}