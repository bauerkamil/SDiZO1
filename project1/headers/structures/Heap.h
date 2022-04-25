#pragma once
#include <iostream>
#include <stdexcept>

namespace DataStructures
{
	template<typename T>

	//dynamic Heap implementation
	class Heap
	{
	public:
		// invalid index exception
		const std::invalid_argument* invalid_index = new std::invalid_argument("Invalid index");
		// structure pointer is null
		const std::out_of_range* head_null = new std::out_of_range("Structure pointer is null");
		// Element not found
		const std::exception* out_of_bound = new std::exception("Element not found");
		// class constructor
		Heap();
		// class destructor
		~Heap();
		// returns obj at index
		// throws invalid argument exception
		virtual T& get(const size_t& index);
		// checks if element exists in Heap
		virtual bool find(const T& element);
		// if element exists in Heap returns its index
		virtual size_t& getIndex(const T& element);
		// adds element to end
		virtual void add(const T& element);
		// adds elements from static Heap
		virtual void addAll(size_t& numOfElements, T* staticArr);
		// removes first obj of the Heap
		virtual void removeRoot();
		//clears Heap
		virtual void clear();
		// returns the size of Heap
		virtual size_t getSize();
		// returns the size of Heap
		virtual size_t getHeight();
		// prints the Heap in console
		virtual void print(std::ostream& out);

	private:
		// pointer to beggining of array containing heap
		T* root;
		//quantity of elements inside Heap
		size_t size;
		//get smaller element down
		void heapifyMax(size_t index);
		//heapify array bottom-up
		void buildHeap();
		//swaps parent and child
		void swap(size_t parentIndex, size_t childIndex);
		//returns index of left child
		//might return index that isnt in heap
		size_t getLeftChild(size_t parentIndex);
		//returns index of right child
		//might return index that isnt in heap
		size_t getRightChild(size_t parentIndex);
		//returns index of parent
		size_t getParent(size_t childIndex);
	};
}
