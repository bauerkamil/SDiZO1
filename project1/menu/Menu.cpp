#include "../headers/menu/Menu.h"
using namespace std;

bool isFinished;

Menu::Menu() {
	isFinished = false;
	while (!isFinished) {
		printMenu();
		chooseOption(getChoice());
	}
}

Menu::~Menu()
{
}

void Menu::printMenu()
{
	std::cout << setfill('=') << setw(FILL_WIDTH) << "\n";
	cout << setfill(' ') << setw((int)FILL_WIDTH / 2 - 2) << "MENU\n";
	cout << setfill('=') << setw(FILL_WIDTH) << "\n"
		<< "Please choose one of following options : \n"
		<< "1. List implementation\n"
		<< "2. Array implementation\n"
		<< "3. Heap implementation\n"
		<< "4. Red-black tree implementation\n"
		<< "0. Exit" << endl;
}

int Menu::getChoice()
{
	int choice;
	cin >> choice;
	return choice;
}

void Menu::chooseOption(int choice)
{
	switch (choice)
	{
	case 1:
	{
		ListTest1* testList = new ListTest1();
		delete testList;
	}
	break;
	case 2:
	{
		ArrayTest* testArr = new ArrayTest();
		delete testArr;
	}
	break;
	case 3:
	{
		HeapTest* testHeap = new HeapTest();
		delete testHeap;
	}
	break;
	case 4:
	{
		TreeTest* testTree = new TreeTest();
		delete testTree;
	}
	break;
	case 0:
	{
		isFinished = true;
	}
	break;
	default:
		cout << "\nPlease try again" << endl;
	}
}