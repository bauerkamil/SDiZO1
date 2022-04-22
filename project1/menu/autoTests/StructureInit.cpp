#include "../../headers/menu/autoTests/StructureInit.h"

int* StructureInit::generateRandArr(size_t size, int maxValue)
{
	int* randArr = new int[size];
	std::srand(std::time(0));
	for (size_t i = 0; i < size; i++)
	{
		randArr[i] = rand() % maxValue;
	}
	return randArr;
}

int* StructureInit::readArrFromFile()
{
	std::string fileName = getFileName();
	size_t size;

	std::ifstream file;
	file.open(fileName, std::ios::in);
	if (file.is_open())
	{
		file >> size;
		if (file.fail()) {
			throw* fileEmpty;
		}
		int* randArr = new int[size + 1];
		randArr[0] = size;
		for (size_t i = 1; i < size + 1; i++)
		{
			int val;
			file >> val;

			if (file.fail())
			{
				throw* fileCorrupted;
			}
			randArr[i] = val;
		}

		return randArr;
	}
	throw* file404;
	return nullptr;
}

void StructureInit::saveRandArrToFile(size_t size, int maxValue)
{
	int* randArr = generateRandArr(size, maxValue);

	std::ofstream outFile;

	std::string fileName = "output/";
	fileName.append(std::to_string(size));
	fileName.append("_rand.txt");

	outFile.open(fileName, std::ios::out);

	outFile << size << std::endl;
	for (size_t i = 0; i <= size; i++) {
		outFile << randArr[i] << std::endl;
	}

	outFile.close();
	delete[] randArr;
}

std::string StructureInit::getFileName()
{
	std::string fileName;
	std::cout << "Enter filename (with path from working directory): " << std::endl;
	std::cin >> fileName;
	return fileName;
}