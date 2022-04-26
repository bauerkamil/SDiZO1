#include "../../headers/menu/autoTests/AutoArrTest.h"

AutoArrTest::AutoArrTest(DataStructures::Array<int>* testArray2)
{
	this->testArray = testArray2;
}

AutoArrTest::~AutoArrTest()
{
	delete this->timer;
	delete this->init;
}

void AutoArrTest::run()
{
	this->isFinished = false;
	while (!this->isFinished) {
		printOptions();
		chooseOption(getOption());
	}
}

void AutoArrTest::printOptions()
{
	std::cout << std::setfill('=') << std::setw(75) << "\n"
		<< "Please choose one of following options : \n"
		<< "1. Auto testing (destroys current data)\n"
		<< "12. Fill from file\n"
		<< "13. Fill with random numbers\n"
		<< "14. Create file with random numbers\n"
		<< "0. Go back" << std::endl;
}

int AutoArrTest::getOption()
{
	int option;
	std::cin >> option;

	return option;
}

void AutoArrTest::chooseOption(int option)
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

size_t AutoArrTest::getSize()
{
	size_t size;
	std::cout << "Please enter size: ";
	std::cin >> size;
	return size;
}

int AutoArrTest::getMaxValue()
{
	int maxSize;
	std::cout << "Please enter the max value: ";
	std::cin >> maxSize;
	return maxSize;
}

void AutoArrTest::autoTest()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	for (int i = 0; i < this->iterationsNumber; i++) {
		this->testArray->clear();
		fillRand(size, maxValue);
		try
		{
			get(size);
			addEnd(size);
			find(size);
			removeEnd(size);
			add(size);
			remove(size);
			addFront(size);
			removeFront(size);
		}
		catch (std::exception& e)
		{
			this->timer->stop();
			std::cout << e.what() << std::endl;
			break;
		}
	}
	this->testArray->clear();
}

void AutoArrTest::get(size_t size)
{
	this->timer->start();
	int element = this->testArray->get(size - 1);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",getByIndex," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoArrTest::find(size_t size)
{
	this->timer->start();
	int index = this->testArray->find(searchValue);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",getIndex," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoArrTest::add(size_t size)
{
	std::srand(std::time(0));
	int element = rand() % 10;
	size_t index = rand() % size;

	this->timer->start();
	this->testArray->add(index, element);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",addAtIndex," << this->timer->result() << "," << index << std::endl;
	this->resultFile.close();
}

void AutoArrTest::addEnd(size_t size)
{
	this->timer->start();
	this->testArray->add(searchValue);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",addEnd," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoArrTest::addFront(size_t size)
{
	this->timer->start();
	this->testArray->addFront(searchValue);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",addFront," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoArrTest::remove(size_t size)
{
	std::srand(std::time(0));
	size_t index = rand() % size;

	this->timer->start();
	this->testArray->remove(index);
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",removeAtIndex," << this->timer->result() << "," << index << std::endl;
	this->resultFile.close();
}

void AutoArrTest::removeFront(size_t size)
{
	this->timer->start();
	this->testArray->removeFront();
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",removeFront," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoArrTest::removeEnd(size_t size)
{
	this->timer->start();
	this->testArray->removeEnd();
	this->timer->stop();

	this->resultFile.open(fileName, std::ios::app);
	this->resultFile << size << ",removeEnd," << this->timer->result() << std::endl;
	this->resultFile.close();
}

void AutoArrTest::fillFromFile()
{
	try
	{
		int* array = this->init->readArrFromFile();
		size_t sizeArr = (size_t)array[0];
		this->testArray->addAll(sizeArr, &array[1]);
		delete[] array;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void AutoArrTest::fillRand()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	fillRand(size, maxValue);
}

void AutoArrTest::fillRand(size_t size, int maxValue)
{
	int* array = this->init->generateRandArr(size, maxValue);
	this->testArray->addAll(size, array);
	delete[] array;
}

void AutoArrTest::createRandFile()
{
	size_t size = getSize();
	int maxValue = getMaxValue();
	this->init->saveRandArrToFile(size, maxValue);
}