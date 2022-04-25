#include "../headers/menu/TreeTest.h"

TreeTest::TreeTest()
{
	std::cout << std::setfill('=') << std::setw(100) << "\n"
		<< std::setfill(' ') << std::setw(40) << "RED-BLACK TREE" << std::endl;
	while (!this->isFinished) {
		printOptions();
		chooseOption(getOption());
	}
}

TreeTest::~TreeTest()
{
	delete this->autoTest;
	delete this->testTree;
}

void TreeTest::printOptions()
{
	std::cout << std::setfill('=') << std::setw(100) << "\n"
		<< "Please choose one of following options : \n"
		<< "1. Find element\n"
		<< "2. Add element to the data structure\n"
		<< "3. Remove element\n"
		<< "4. Print data structure\n"
		<< "5. Clear data structure\n"
		<< "11. Automate functions\n"
		<< "0. Exit" << std::endl;
}

int TreeTest::getOption()
{
	int option;
	std::cin >> option;

	return option;
}

void TreeTest::chooseOption(int option)
{
	switch (option)
	{
	case 1:
	{
		find();
	}
	break;
	case 2:
	{
		add();
	}
	break;
	case 3:
	{
		remove();
	}
	break;
	case 4:
	{
		print();
	}
	break;
	case 5:
	{
		testTree->clear();
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

int TreeTest::getElement()
{
	int element;
	std::cout << "Please enter the element: ";
	std::cin >> element;
	return element;
}

void TreeTest::find()
{
	int element = getElement();
	if (this->testTree->find(element))
		std::cout << "Element found" << std::endl;
	else
		std::cout << "Element not found" << std::endl;
}

void TreeTest::add()
{
	int element = getElement();
	try
	{
		this->testTree->add(element);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully added. Structure after addition:" << std::endl;
	this->testTree->print(std::cout);
}

void TreeTest::remove()
{
	int element = getElement();
	try
	{
		this->testTree->remove(element);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Successfully removed. Structure after removal:" << std::endl;
	this->testTree->print(std::cout);
}

void TreeTest::print()
{
	this->testTree->print(std::cout);
}

void TreeTest::automate()
{
	this->autoTest->run();
}