#include "../headers/menu/HeapTest.h"

HeapTest::HeapTest()
{
	std::cout << std::setfill('=') << std::setw(100) << "\n"
		<< std::setfill(' ') << std::setw(40) << "HEAP MAX" << std::endl;
	while (!this->isFinished) {
		printOptions();
		chooseOption(getOption());
	}
}

HeapTest::~HeapTest()
{
	delete this->autoTest;
	delete this->testHeap;
}

void HeapTest::printOptions()
{
	std::cout << std::setfill('=') << std::setw(100) << "\n"
		<< "Please choose one of following options : \n"
		<< "1. Get element at index\n"
		<< "2. Get index of element\n"
		<< "3. Add element to the data structure\n"
		<< "4. Remove element at the beginning of the heap\n"
		<< "5. Get size of data structure\n"
		<< "6. Print data structure\n"
		<< "11. Automate functions\n"
		<< "0. Exit" << std::endl;
}

int HeapTest::getOption()
{
	int option;
	std::cin >> option;

	return option;
}

void HeapTest::chooseOption(int option)
{
	switch (option)
	{
	case 1:
	{
		get();
	}
	break;
	case 2:
	{
		findIndex();
	}
	break;
	case 3:
	{
		add();
	}
	break;
	case 4:
	{
		removeRoot();
	}
	break;
	case 5:
	{
		getSize();
	}
	break;
	case 6:
	{
		print();
	}
	break;
	case 11:
	{
		automate();
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

int HeapTest::getIndex()
{
	int index;
	std::cout << "Please enter index: ";
	std::cin >> index;
	return index;
}

int HeapTest::getElement()
{
	int element;
	std::cout << "Please enter the element: ";
	std::cin >> element;
	return element;
}

void HeapTest::get()
{
	int index = getIndex();
	try
	{
		int element = this->testHeap->get(index);
		std::cout << "Element at index: " << index << " is: " << element << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void HeapTest::findIndex()
{
	int element = getElement();
	try
	{
		int index = this->testHeap->getIndex(element);
		std::cout << "Index of element: " << element << " is: " << index << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void HeapTest::add()
{
	int element = getElement();
	try
	{
		this->testHeap->add(element);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully added" << std::endl;
}

void HeapTest::removeRoot()
{
	try
	{
		this->testHeap->removeRoot();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully removed" << std::endl;
}

void HeapTest::getSize()
{
	int size = this->testHeap->getSize();
	std::cout << "Size: " << size << std::endl;
}

void HeapTest::print()
{
	this->testHeap->print(std::cout);
}

void HeapTest::automate()
{
	this->autoTest->run();
}