#include "../headers/structures/Array.h"

template <typename T>
DataStructures::Array<T>::Array() : head(nullptr), size(0) {}

template <typename T>
DataStructures::Array<T>::~Array()
{
	clear();
}

template<typename T>
T& DataStructures::Array<T>::get(const size_t& index)
{
	// Check if index is correct
	if (index >= this->size || index < 0)
	{
		throw* this->invalid_index;
	}
	return this->head[index];
}

template<typename T>
size_t& DataStructures::Array<T>::getIndex(const T& element)
{
	if (this->size == 0 || this->head == nullptr)
	{
		throw* this->out_of_bound;
	}

	for (size_t i = 0; i < this->size - 1; i++)
	{
		if (this->head[i] == element)
		{
			return i;
		}
	}

	throw* this->out_of_bound;
}

template<typename T>
void DataStructures::Array<T>::add(const T& element)
{
	T* newHead = new T[this->size + 1];
	newHead[this->size] = element;

	// copy data if exists
	if (this->head != nullptr)
	{
		for (size_t i = 0; i < this->size; i++)
		{
			newHead[i] = this->head[i];
		}

		// delete old static array
		delete[] this->head;
	}

	this->size++;
	this->head = newHead;
}

template<typename T>
void DataStructures::Array<T>::add(const size_t& index, const T& element)
{
	// check if you can add element at such index
	if (index > this->size || index < 0)
	{
		throw* this->invalid_index;
	}

	T* newHead = new T[this->size + 1];
	newHead[index] = element;

	// copy elements before index
	for (size_t i = 0; i < index; i++)
	{
		newHead[i] = this->head[i];
	}

	// copy elements after index
	for (size_t i = index + 1; i <= this->size; i++)
	{
		newHead[i] = this->head[i - 1];
	}

	delete[] this->head;
	this->size++;
	this->head = newHead;
}

template<typename T>
void DataStructures::Array<T>::addFront(const T& element)
{
	T* newHead = new T[this->size + 1];
	newHead[0] = element;

	// Copy data if exists
	if (this->head != nullptr)
	{
		for (size_t i = 0; i < this->size; i++)
		{
			newHead[i + 1] = this->head[i];
		}

		// Delete old dynamic array
		delete[] this->head;
	}

	this->size++;
	this->head = newHead;
}

template<typename T>
void DataStructures::Array<T>::addAll(size_t& numOfElements, T* staticArr)
{
	size_t newSize = this->size + numOfElements;
	T* newHead = new T[newSize];

	// copy data if exists
	if (this->head != nullptr)
	{
		for (size_t i = 0; i < this->size; i++)
		{
			newHead[i] = this->head[i];
		}

		// delete old static array
		delete[] this->head;
	}
	//copy data from given array
	for (size_t i = 0; i < numOfElements; i++)
	{
		newHead[i + this->size] = staticArr[i];
	}
	this->size = newSize;
	this->head = newHead;
}

template<typename T>
void DataStructures::Array<T>::removeFront()
{
	// Check if any data exists
	if (this->head == nullptr)
	{
		throw* this->head_null;
	}

	T* newHead = nullptr;

	// Copy data if needed
	if (this->size > 1)
	{
		newHead = new T[size - 1];
		for (size_t i = 1; i < this->size - 1; i++)
		{
			newHead[i - 1] = this->head[i];
		}
	}

	delete[] this->head;
	this->size--;
	this->head = newHead;
}

template<typename T>
void DataStructures::Array<T>::removeEnd()
{
	// Check if any data exists
	if (this->head == nullptr)
	{
		throw* this->head_null;
	}

	T* newHead = nullptr;

	// Copy data if needed
	if (this->size > 1)
	{
		newHead = new T[size];
		for (size_t i = 0; i < this->size; i++)
		{
			newHead[i] = this->head[i];
		}
	}

	delete[] this->head;
	this->size--;
	this->head = newHead;
}

template<typename T>
void DataStructures::Array<T>::remove(const size_t& index)
{
	// Check if any data exists
	if (this->head == nullptr)
	{
		throw* this->head_null;
	}
	// Check if index is correct
	if (index >= this->size)
	{
		throw* this->invalid_index;
	}

	T* newHead = nullptr;

	// Copy data if needed
	if (this->size > 1)
	{
		newHead = new T[size - 1];

		// Copy data before index
		for (size_t i = 0; i < index; i++)
		{
			newHead[i] = this->head[i];
		}

		// Copy data after index
		for (size_t i = index + 1; i < size; i++)
		{
			newHead[i - 1] = this->head[i];
		}
	}

	delete[] this->head;
	this->size--;
	this->head = newHead;
}

template<typename T>
void DataStructures::Array<T>::clear()
{
	if (this->head != nullptr)
	{
		delete[] this->head;
	}
	this->head = nullptr;
	this->size = 0;
}

template<typename T>
void DataStructures::Array<T>::print(std::ostream& out)
{
	if (this->size > 0 && this->head != nullptr)
	{
		out << "[";
		for (size_t i = 0; i < this->size - 1; i++)
		{
			out << "(" << i << ") " << this->head[i] << ", ";
		}
		out << "(" << this->size - 1 << ") " << this->head[this->size - 1] << "]" << std::endl;
		return;
	}
	out << "Data structure is empty" << std::endl;
}

template<typename T>
size_t DataStructures::Array<T>::getSize()
{
	return this->size;
}

// one data type necessary in this project
template class DataStructures::Array<int>;