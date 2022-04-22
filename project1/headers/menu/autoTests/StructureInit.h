#pragma once
#include<iostream>
#include <fstream>
#include<cstdlib>
#include<ctime>
#include <bits.h>
#include <string>
#include <stdexcept>
class StructureInit
{
public:
	int* generateRandArr(size_t size, int maxValue);
	//reads values from specified file
	//first value in file is quantity of values after the first one and this is repeated in created array
	int* readArrFromFile();
	void saveRandArrToFile(size_t size, int maxValue);
	const std::exception* fileEmpty = new std::exception("File empty");
	const std::exception* fileCorrupted = new std::exception("File corrupted");
	const std::exception* file404 = new std::exception("File not found");
private:
	std::string getFileName();
};
