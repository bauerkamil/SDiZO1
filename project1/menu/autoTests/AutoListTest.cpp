#include "../../headers/menu/autoTests/AutoListTest.h"

AutoListTest::AutoListTest(DataStructures::List<int>* testList2)
{
	this->testList = testList2;
}

AutoListTest::~AutoListTest()
{
	delete this->timer;
	delete this->init;
}

void AutoListTest::run()
{
	this->isFinished = false;
	while (!this->isFinished) {
		printOptions();
		chooseOption(getOption());
	}
}

void AutoListTest::printOptions()
{
	std::cout << std::setfill('=') << std::setw(75) << "\n"
		<< "Please choose one of following options : \n"
		<< "1. Auto testing (destroys current data)\n"
		<< "12. Fill from file\n"
		<< "13. Fill with random numbers\n"
		<< "14. Create file with random numbers\n"
		<< "0. Go back" << std::endl;
}

int AutoListTest::getOption()
{
	int option;
	std::cin >> option;

	return option;
}

void AutoListTest::chooseOption(int option)
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

size_t AutoListTest::getSize()
{
	size_t size;
	std::cout << "Please enter size: ";
	std::cin >> size;
	return size;
}

int AutoListTest::getMaxValue()
{
	int maxSize;
	std::cout << "Please enter the max value: ";
	std::cin >> maxSize;
	return maxSize;
}

void AutoListTest::autoTest()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	for (int i = 0; i < this->iterationsNumber; i++) {
		this->testList->clear();
		fillRand(size, maxValue);
		try
		{
			get(size);
			addEnd(size);
			Sleep(5);
			removeEnd(size);
			Sleep(5);
			add(size);
			Sleep(5);
			findIndex(size);
			Sleep(5);
			remove(size);
			Sleep(5);
			addFront(size);
			Sleep(5);
			removeFront(size);
		}
		catch (std::exception& e)
		{
			this->timer->stop();
			std::cout << e.what() << std::endl;
			break;
		}
	}
	this->testList->clear();
}

void AutoListTest::get(size_t size)
{
	this->timer->start();
	int element = this->testList->get(size / 2 - 1);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",getByIndex," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoListTest::findIndex(size_t size)
{
	this->timer->start();
	try
	{
		int index = this->testList->getIndex(searchValue);
	}
	catch (const std::exception&)
	{
	}

	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",getIndex," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoListTest::add(size_t size)
{
	std::srand(std::time(0));
	int element = rand() % 10;
	size_t index = size / 2 - 1;

	this->timer->start();
	this->testList->add(index, element);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",addAtIndex," << this->timer->result() << "," << index << std::endl;
	this->resultFile.close();
}

void AutoListTest::addEnd(size_t size)
{
	this->timer->start();
	this->testList->addEnd(searchValue);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",addEnd," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoListTest::addFront(size_t size)
{
	this->timer->start();
	this->testList->addFront(searchValue);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",addFront," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoListTest::remove(size_t size)
{
	std::srand(std::time(0));
	size_t index = size / 2 - 1;

	this->timer->start();
	this->testList->remove(index);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",removeAtIndex," << this->timer->result() << "," << index << std::endl;
	this->resultFile.close();
}

void AutoListTest::removeFront(size_t size)
{
	this->timer->start();
	this->testList->removeFront();
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",removeFront," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoListTest::removeEnd(size_t size)
{
	this->timer->start();
	this->testList->removeEnd();
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",removeEnd," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoListTest::fillFromFile()
{
	try
	{
		int* array = this->init->readArrFromFile();
		size_t sizeArr = (size_t)array[0];
		this->testList->addAll(sizeArr, &array[1]);
		delete[] array;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void AutoListTest::fillRand()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	fillRand(size, maxValue);
}

void AutoListTest::fillRand(size_t size, int maxValue)
{
	int* listArr = this->init->generateRandArr(size, maxValue);
	this->testList->addAll(size, listArr);
	delete[] listArr;
}

void AutoListTest::createRandFile()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	this->init->saveRandArrToFile(size, maxValue);
}