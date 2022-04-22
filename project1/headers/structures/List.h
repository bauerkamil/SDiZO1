#pragma once
#include <iostream>
#include <stdexcept>

namespace DataStructures
{
	template<typename T>

	//dynamic List implementation
	class List
	{
	public:
		template<typename T>
		struct ListNode
		{
			T value;
			ListNode* prevNode;
			ListNode* nextNode;
			ListNode(T value, ListNode* previous, ListNode* next)
				: value(value), prevNode(previous), nextNode(next) {}
		};
		// invalid index exception
		const std::invalid_argument* invalid_index = new std::invalid_argument("Invalid index");
		// structure pointer is null
		const std::out_of_range* head_null = new std::out_of_range("Structure pointer is null");
		// Element not found
		const std::exception* out_of_bound = new std::exception("Out of bound");
		// class constructor
		List();
		// class destructor
		~List();
		// returns obj at index
		// throws invalid argument exception
		virtual T& get(const size_t& index);
		// checks if element exists in List
		virtual size_t& getIndex(const T& element);
		// adds element to end
		virtual void addEnd(const T& element);
		// adds element at index
		// throws invalid argument exception
		virtual void add(const size_t& index, const T& element);
		// adds element at the front of List
		virtual void addFront(const T& element);
		// adds elements from static List
		virtual void addAll(size_t& numOfElements, T* staticArr);
		// removes obj at index
		// throws invalid argument exception
		virtual void remove(const size_t& index);
		// removes obj at the front of the List
		virtual void removeFront();
		// removes obj at the end of the List
		virtual void removeEnd();
		//clears List
		virtual void clear();
		// returns the size of List
		virtual size_t getSize();
		// prints the List in console
		virtual void print(std::ostream& out);

	private:
		// pointer to beggining of List
		ListNode<T>* head;
		// pointer to the last element of List
		ListNode<T>* tail;
		//quantity of elements inside List
		size_t size;
	};
}
