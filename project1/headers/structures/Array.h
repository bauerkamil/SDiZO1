#pragma once
#include <iostream>
#include <stdexcept>

namespace DataStructures
{
	template<typename T>

	//dynamic array implementation
	class Array
	{
	public:
		// invalid index exception
		const std::invalid_argument* invalid_index = new std::invalid_argument("Invalid index");
		// structure pointer is null
		const std::out_of_range* head_null = new std::out_of_range("Structure pointer is null");
		// Element not found
		const std::exception* out_of_bound = new std::exception("Out of bound");
		// class constructor
		Array();
		// class destructor
		~Array();
		// returns obj at index
		// throws invalid argument exception
		virtual T& get(const size_t& index);
		//seraches for element
		virtual bool find(const T& element);
		// checks if element exists in array
		virtual size_t& getIndex(const T& element);
		// adds element to end
		virtual void add(const T& element);
		// adds element at index
		// throws invalid argument exception
		virtual void add(const size_t& index, const T& element);
		// adds element at the front of array
		virtual void addFront(const T& element);
		// adds elements from static array
		virtual void addAll(size_t& numOfElements, T* staticArr);
		// removes obj at index
		// throws invalid argument exception
		virtual void remove(const size_t& index);
		// removes obj at the front of the array
		virtual void removeFront();
		// removes obj at the end of the array
		virtual void removeEnd();
		//clears array
		virtual void clear();
		// returns the size of array
		virtual size_t getSize();
		// prints the array in console
		virtual void print(std::ostream& out);
	private:
		// pointer to beggining of array
		T* head;
		//quantity of elements inside array
		size_t size;
	};
}
