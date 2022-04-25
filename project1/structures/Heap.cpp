#include "../headers/structures/Heap.h"
#include <math.h>

template <typename T>
DataStructures::Heap<T>::Heap() : root(nullptr), size(0) {}

template <typename T>
DataStructures::Heap<T>::~Heap()
{
	clear();
}

template<typename T>
T& DataStructures::Heap<T>::get(const size_t& index)
{
	// Check if index is correct
	if (index >= this->size || index < 0)
	{
		throw* this->invalid_index;
	}
	return this->root[index];
}

template<typename T>
size_t& DataStructures::Heap<T>::getIndex(const T& element)
{
	if (this->size == 0 || this->root == nullptr)
	{
		throw* this->out_of_bound;
	}

	for (size_t i = 0; i <= this->size - 1; i++)
	{
		if (this->root[i] == element)
		{
			return i;
		}
	}

	throw* this->out_of_bound;
}

template<typename T>
bool DataStructures::Heap<T>::find(const T& element)
{
	if (this->size == 0 || this->root == nullptr)
	{
		return false;
	}

	for (size_t i = 0; i <= this->size - 1; i++)
	{
		if (this->root[i] == element)
		{
			return true;
		}
	}

	return false;
}

template<typename T>
void DataStructures::Heap<T>::add(const T& element)
{
	T* newRoot = new T[this->size + 1];
	newRoot[this->size] = element;

	// copy data if exists
	if (this->root != nullptr)
	{
		for (size_t i = 0; i < this->size; i++)
		{
			newRoot[i] = this->root[i];
		}

		// delete old static array
		delete[] this->root;
	}

	this->size++;
	this->root = newRoot;

	buildHeap();
}

template<typename T>
void DataStructures::Heap<T>::addAll(size_t& numOfElements, T* staticArr)
{
	size_t newSize = this->size + numOfElements;
	T* newRoot = new T[newSize];

	// copy data if exists
	if (this->root != nullptr)
	{
		for (size_t i = 0; i < this->size; i++)
		{
			newRoot[i] = this->root[i];
		}

		// delete old static Heap
		delete[] this->root;
	}
	//copy data from given Heap
	for (size_t i = 0; i < numOfElements; i++)
	{
		newRoot[i + this->size] = staticArr[i];
	}
	this->size = newSize;
	this->root = newRoot;

	buildHeap();
}

template<typename T>
void DataStructures::Heap<T>::removeRoot()
{
	// Check if any data exists
	if (this->root == nullptr)
	{
		throw* this->head_null;
	}

	T* newRoot = nullptr;

	// Copy data if needed
	if (this->size > 1)
	{
		newRoot = new T[size - 1];
		this->root[0] = this->root[size - 1];
		for (size_t i = 0; i < this->size - 1; i++)
		{
			newRoot[i] = this->root[i];
		}
	}

	delete[] this->root;
	this->size--;
	this->root = newRoot;

	//no need to go up
	heapifyMax(0);
}

template<typename T>
void DataStructures::Heap<T>::clear()
{
	if (this->root != nullptr)
	{
		delete[] this->root;
	}
	this->root = nullptr;
	this->size = 0;
}

template<typename T>
void DataStructures::Heap<T>::print(std::ostream& out)
{
	if (this->size > 0 && this->root != nullptr)
	{
		size_t height = getHeight();
		size_t index = 0;
		for (size_t currLevel = 1; currLevel < height; currLevel++)
		{
			out << currLevel << ".";
			size_t numOfLevelElements = pow(2, currLevel - 1);

			size_t tmp = height - currLevel;
			size_t numOfSpace = pow(2, tmp) - 1;
			size_t numOfMinus = pow(2, tmp - 1) - 1;

			out << std::string(numOfMinus, ' ');
			for (size_t i = 0; i < numOfLevelElements; i++)
			{
				out << "/" << std::string(numOfMinus, '-') << this->root[index];
				out << std::string(numOfMinus, '-') << "\\" << std::string(numOfSpace, ' ');
				index++;
			}
			out << std::endl;
		}
		out << height << ".";
		while (index < this->size)
		{
			out << this->root[index] << " ";
			index++;
		}
		out << std::endl;

		return;
	}
	out << "Data structure is empty" << std::endl;
}

/*template<typename T>
void DataStructures::Heap<T>::printHelp(std::ostream& out, T& printElement)
{
	if (std::is_same<T, int>::value)
	{
		int print = dynamic_cast<int>(T);
		if (print >= 1000) {
			out << print;
			return;
		}
		if (print >= 100) {
			out << "-" << print << "-";
			return;
		}
		if (print >= 10) {
			out << "--" << print << "--";
			return;
		}

		out << "---" << print << "---";
	}
	else
		out << T;
}*/

template<typename T>
void DataStructures::Heap<T>::heapifyMax(size_t index)
{
	size_t largest;
	size_t left = getLeftChild(index);
	size_t right = getRightChild(index);

	//determine which is the biggest
	if (left<this->size && root[left]>root[index])
		largest = left;
	else
		largest = index;
	if (right<this->size && root[right]>root[largest])
		largest = right;

	if (largest != index)
	{
		swap(index, largest);
		heapifyMax(largest);
	}
}

template<typename T>
void DataStructures::Heap<T>::buildHeap()
{
	if (this->size > 1)
		for (size_t i = getParent(this->size - 1); i >= 0; i--)
		{
			heapifyMax(i);
			if (i == 0)
			{
				break;
			}
		}
}

template<typename T>
void DataStructures::Heap<T>::swap(size_t parentIndex, size_t childIndex)
{
	T value = this->root[parentIndex];
	this->root[parentIndex] = this->root[childIndex];
	this->root[childIndex] = value;
}

//indexing from 0 - different indexes than Cormen

template<typename T>
size_t DataStructures::Heap<T>::getLeftChild(size_t parentIndex)
{
	return (2 * parentIndex + 1);
}

template<typename T>
size_t DataStructures::Heap<T>::getRightChild(size_t parentIndex)
{
	return (2 * parentIndex + 2);
}

template<typename T>
size_t DataStructures::Heap<T>::getParent(size_t childIndex)
{
	return floor(childIndex / 2);
}

template<typename T>
size_t DataStructures::Heap<T>::getSize()
{
	return this->size;
}

template<typename T>
size_t DataStructures::Heap<T>::getHeight()
{
	if (this->size == 0)
		return 0;
	if (this->size == 1)
		return 1;

	return ceil(log2(this->size + 1));
}

// one data type necessary in this project
template class DataStructures::Heap<int>;