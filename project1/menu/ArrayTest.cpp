#include "../headers/menu/ArrayTest.h"

ArrayTest::ArrayTest()
{
	std::cout << std::setfill('=') << std::setw(30) << "\n"
		<< std::setfill(' ') << std::setw(40) << "DYNAMIC ARRAY" << std::endl;
	while (!this->isFinished) {
		printOptions();
		chooseOption(getOption());
	}
}

ArrayTest::~ArrayTest()
{
	delete this->autoTest;
	delete this->testArray;
}

void ArrayTest::printOptions()
{
	std::cout << std::setfill('=') << std::setw(100) << "\n"
		<< "Please choose one of following options : \n"
		<< "1. Get element at index\n"
		<< "2. Get index of element\n"
		<< "3. Add element at the end of data structure\n"
		<< "4. Add element at specified index in list or array\n"
		<< "5. Add element at the beginning of list or array\n"
		<< "6. Remove element at the end of data structure\n"
		<< "7. Remove element at specified index in list or array\n"
		<< "8. Remove element at the beginning of list or array\n"
		<< "9. Get size of data structure\n"
		<< "10. Print data structure\n"
		<< "11. Automate functions\n"
		<< "0. Exit" << std::endl;
}

int ArrayTest::getOption()
{
	int option;
	std::cin >> option;

	return option;
}

void ArrayTest::chooseOption(int option)
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
		addEnd();
	}
	break;
	case 4:
	{
		add();
	}
	break;
	case 5:
	{
		addFront();
	}
	break;
	case 6:
	{
		removeEnd();
	}
	break;
	case 7:
	{
		remove();
	}
	break;
	case 8:
	{
		removeFront();
	}
	break;
	case 9:
	{
		getSize();
	}
	break;
	case 10:
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

int ArrayTest::getIndex()
{
	int index;
	std::cout << "Please enter index: ";
	std::cin >> index;
	return index;
}

int ArrayTest::getElement()
{
	int element;
	std::cout << "Please enter the element: ";
	std::cin >> element;
	return element;
}

void ArrayTest::get()
{
	int index = getIndex();
	try
	{
		int element = this->testArray->get(index);
		std::cout << "Element at index: " << index << " is: " << element << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ArrayTest::findIndex()
{
	int element = getElement();
	try
	{
		int index = this->testArray->getIndex(element);
		std::cout << "Index of element: " << element << " is: " << index << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ArrayTest::add()
{
	int index = getIndex();
	int element = getElement();
	try
	{
		this->testArray->add(index, element);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully added" << std::endl;
}

void ArrayTest::addEnd()
{
	int element = getElement();
	this->testArray->add(element);

	std::cout << "Successfully added" << std::endl;
}

void ArrayTest::addFront()
{
	int element = getElement();
	this->testArray->addFront(element);

	std::cout << "Successfully added" << std::endl;
}

void ArrayTest::remove()
{
	int index = getIndex();
	try
	{
		this->testArray->remove(index);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully removed" << std::endl;
}

void ArrayTest::removeFront()
{
	try
	{
		this->testArray->removeFront();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully removed" << std::endl;
}

void ArrayTest::removeEnd()
{
	try
	{
		this->testArray->removeEnd();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully removed" << std::endl;
}

void ArrayTest::getSize()
{
	int size = this->testArray->getSize();
	std::cout << "Size: " << size << std::endl;
}

void ArrayTest::print()
{
	this->testArray->print(std::cout);
}

void ArrayTest::automate()
{
	this->autoTest->run();
}