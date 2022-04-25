#include "../headers/menu/ListTest1.h"

ListTest1::ListTest1()
{
	std::cout << std::setfill('=') << std::setw(100) << "\n"
		<< std::setfill(' ') << std::setw(40) << "DOUBLE LINKED LIST" << std::endl;
	while (!this->isFinished) {
		printOptions();
		chooseOption(getOption());
	}
}

ListTest1::~ListTest1()
{
	delete this->autoTest;
	delete this->testList;
}

void ListTest1::printOptions()
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

int ListTest1::getOption()
{
	int option;
	std::cin >> option;

	return option;
}

void ListTest1::chooseOption(int option)
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

int ListTest1::getIndex()
{
	int index;
	std::cout << "Please enter index: ";
	std::cin >> index;
	return index;
}

int ListTest1::getElement()
{
	int element;
	std::cout << "Please enter the element: ";
	std::cin >> element;
	return element;
}

void ListTest1::get()
{
	int index = getIndex();
	try
	{
		int element = this->testList->get(index);
		std::cout << "Element at index: " << index << " is: " << element << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ListTest1::findIndex()
{
	int element = getElement();
	try
	{
		int index = this->testList->getIndex(element);
		std::cout << "Index of element: " << element << " is: " << index << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void ListTest1::add()
{
	int index = getIndex();
	int element = getElement();
	try
	{
		this->testList->add(index, element);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully added. Structure after addition:" << std::endl;
	this->testList->print(std::cout);
}

void ListTest1::addEnd()
{
	int element = getElement();
	this->testList->addEnd(element);

	std::cout << "Successfully added. Structure after addition:" << std::endl;
	this->testList->print(std::cout);
}

void ListTest1::addFront()
{
	int element = getElement();
	this->testList->addFront(element);

	std::cout << "Successfully added. Structure after addition:" << std::endl;
	this->testList->print(std::cout);
}

void ListTest1::remove()
{
	int index = getIndex();
	try
	{
		this->testList->remove(index);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully removed. Structure after removal:" << std::endl;
	this->testList->print(std::cout);
}

void ListTest1::removeFront()
{
	try
	{
		this->testList->removeFront();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully removed. Structure after removal:" << std::endl;
	this->testList->print(std::cout);
}

void ListTest1::removeEnd()
{
	try
	{
		this->testList->removeEnd();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully removed. Structure after removal:" << std::endl;
	this->testList->print(std::cout);
}

void ListTest1::getSize()
{
	int size = this->testList->getSize();
	std::cout << "Size: " << size << std::endl;
}

void ListTest1::print()
{
	this->testList->print(std::cout);
}

void ListTest1::automate()
{
	this->autoTest->run();
}