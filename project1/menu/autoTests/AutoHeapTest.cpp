#include "../../headers/menu/autoTests/AutoHeapTest.h"

AutoHeapTest::AutoHeapTest(DataStructures::Heap<int>* testHeap2)
{
	this->testHeap = testHeap2;
}

AutoHeapTest::~AutoHeapTest()
{
	delete this->timer;
	delete this->init;
}

void AutoHeapTest::run()
{
	this->isFinished = false;
	while (!this->isFinished) {
		printOptions();
		chooseOption(getOption());
	}
}

void AutoHeapTest::printOptions()
{
	std::cout << std::setfill('=') << std::setw(75) << "\n"
		<< "Please choose one of following options : \n"
		<< "1. Auto testing (destroys current data)\n"
		<< "12. Fill from file\n"
		<< "13. Fill with random numbers\n"
		<< "14. Create file with random numbers\n"
		<< "0. Go back" << std::endl;
}

int AutoHeapTest::getOption()
{
	int option;
	std::cin >> option;

	return option;
}

void AutoHeapTest::chooseOption(int option)
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

size_t AutoHeapTest::getSize()
{
	size_t size;
	std::cout << "Please enter size: ";
	std::cin >> size;
	return size;
}

int AutoHeapTest::getMaxValue()
{
	int maxSize;
	std::cout << "Please enter the max value: ";
	std::cin >> maxSize;
	return maxSize;
}

void AutoHeapTest::autoTest()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	for (int i = 0; i < this->iterationsNumber; i++) {
		this->testHeap->clear();
		fillRand(size, maxValue);
		try
		{
			get(size);
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
	this->testHeap->clear();
}

void AutoHeapTest::get(size_t size)
{
	this->timer->start();
	int element = this->testHeap->get(size - 1);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",getByIndex," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoHeapTest::find(size_t size)
{
	this->timer->start();
	int index = this->testHeap->find(searchValue);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",getIndex," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoHeapTest::add(size_t size)
{
	std::srand(std::time(0));
	int element = rand() % 10;

	this->timer->start();
	this->testHeap->add(element);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",add," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoHeapTest::remove(size_t size)
{
	this->timer->start();
	this->testHeap->removeRoot();
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",removeRoot," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoHeapTest::fillFromFile()
{
	try
	{
		int* array = this->init->readArrFromFile();
		size_t sizeArr = (size_t)array[0];
		this->testHeap->addAll(sizeArr, &array[1]);
		delete[] array;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void AutoHeapTest::fillRand()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	fillRand(size, maxValue);
}

void AutoHeapTest::fillRand(size_t size, int maxValue)
{
	int* heapArr = this->init->generateRandArr(size, maxValue);
	this->testHeap->addAll(size, heapArr);
	delete[] heapArr;
}

void AutoHeapTest::createRandFile()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	this->init->saveRandArrToFile(size, maxValue);
}