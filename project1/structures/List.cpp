#include "../headers/structures/List.h"

template <typename T>
DataStructures::List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DataStructures::List<T>::~List()
{
	clear();
}

template<typename T>
T& DataStructures::List<T>::get(const size_t& index)
{
	// Check if index is correct
	if (index >= this->size || index < 0)
	{
		throw* this->invalid_index;
	}
	ListNode<T>* node = this->head;
	for (size_t i = 0; i < index; i++)
	{
		ListNode<T>* next = node->nextNode;
		node = next;
	}
	return node->value;
}

template<typename T>
size_t& DataStructures::List<T>::getIndex(const T& element)
{
	if (this->size == 0 || this->head == nullptr)
	{
		throw* this->out_of_bound;
	}

	ListNode<T>* node = this->head;
	for (size_t i = 0; i <= this->size; i++)
	{
		ListNode<T>* next = node->nextNode;

		if (node->value == element)
		{
			return i;
		}
		node = next;

		if (node == nullptr) {
			break;
		}
	}

	throw* this->out_of_bound;
}

template<typename T>
void DataStructures::List<T>::addEnd(const T& element)
{
	ListNode<T>* node = new ListNode<T>(element, this->tail, nullptr);

	if (this->tail) {
		this->tail->nextNode = node;
	}
	else {
		// If there is no tail, head is nullptr too
		this->head = node;
	}

	this->tail = node;
	this->size++;
}

template<typename T>
void DataStructures::List<T>::add(const size_t& index, const T& element)
{
	// check if you can add element at such index
	if (index >= this->size || index < 0)
	{
		throw* this->invalid_index;
	}

	// Add first node
	if (index == 0)
	{
		addFront(element);
		return;
	}

	// Add last node
	if (index == this->size)
	{
		addEnd(element);
		return;
	}

	//double linked list - if the index is in the first half - start from head
	if (index <= size / 2) {
		ListNode<T>* prevNode = this->head;
		for (size_t i = 0; i < index; i++)
		{
			ListNode<T>* next = prevNode->nextNode;
			prevNode = next;
		}
		ListNode<T>* node = new ListNode<T>(element, prevNode, prevNode->nextNode);
		prevNode->nextNode = node;
	}
	//else start from tail
	else {
		ListNode<T>* nextNode = this->tail;
		for (size_t i = this->size - 1; i > index; i--)
		{
			ListNode<T>* next = nextNode->prevNode;
			nextNode = next;
		}
		ListNode<T>* node = new ListNode<T>(element, nextNode->prevNode, nextNode);
		nextNode->prevNode = node;
	}

	this->size++;
}

template<typename T>
void DataStructures::List<T>::addFront(const T& element)
{
	ListNode<T>* node = new ListNode<T>(element, nullptr, this->head);

	if (this->head) {
		this->head->prevNode = node;
	}
	else {
		// If there is no head, tail is nullptr too
		this->tail = node;
	}

	this->head = node;
	this->size++;
}

template<typename T>
void DataStructures::List<T>::addAll(size_t& numOfElements, T* staticArr)
{
	for (size_t i = 0; i < numOfElements; i++)
	{
		addEnd(staticArr[i]);
	}
}

template<typename T>
void DataStructures::List<T>::removeFront()
{
	// Check if any data exists
	if (this->head == nullptr)
	{
		throw* this->head_null;
	}
	// Check if head is the only element
	if (this->head->nextNode == nullptr)
	{
		delete this->head;
		this->head = this->tail = nullptr;
		this->size--;
		return;
	}

	ListNode<T>* tmp = this->head->nextNode;
	tmp->prevNode = nullptr;
	delete this->head;
	this->head = tmp;

	this->size--;
}

template<typename T>
void DataStructures::List<T>::removeEnd()
{
	// Check if any data exists
	if (this->head == nullptr)
	{
		throw* this->head_null;
	}
	// Check if head is the only element (then tail is the same one)
	if (this->head->nextNode == nullptr)
	{
		delete this->head;
		this->head = this->tail = nullptr;
		this->size--;
		return;
	}

	ListNode<T>* tmp = this->tail->prevNode;
	tmp->nextNode = nullptr;
	delete this->tail;
	this->tail = tmp;

	this->size--;
}

template<typename T>
void DataStructures::List<T>::remove(const size_t& index)
{
	/// check if you can add element at such index
	if (index >= this->size || index < 0)
	{
		throw* this->invalid_index;
	}

	// Add first node
	if (index == 0)
	{
		removeFront();
		return;
	}

	// Add last node
	if (index == this->size)
	{
		removeEnd();
		return;
	}

	//double linked list - if the index is in the first half - start from head
	if (index <= size / 2) {
		ListNode<T>* tmp = this->head;
		for (size_t i = 0; i < index; i++)
		{
			tmp = tmp->nextNode;
		}

		if (tmp->nextNode)
			tmp->nextNode->prevNode = tmp->prevNode;
		if (tmp->prevNode)
			tmp->prevNode->nextNode = tmp->nextNode;

		delete tmp;
	}
	//else start from tail
	else {
		ListNode<T>* tmp = this->tail;
		for (size_t i = this->size - 1; i > index; i--)
		{
			tmp = tmp->prevNode;
		}
		if (tmp->nextNode)
			tmp->nextNode->prevNode = tmp->prevNode;
		if (tmp->prevNode)
			tmp->prevNode->nextNode = tmp->nextNode;

		delete tmp;
	}

	this->size--;
}

template<typename T>
void DataStructures::List<T>::clear()
{
	// delete every element of List if exists
	ListNode<T>* node = this->head;

	while (node) {
		ListNode<T>* next = node->nextNode;

		delete node;
		node = next;
	}

	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template<typename T>
void DataStructures::List<T>::print(std::ostream& out)
{
	if (this->size > 0 && this->head != nullptr)
	{
		ListNode<T>* node = this->head;
		out << "[NULL <- ";
		while (node)
		{
			if (node->nextNode)
				out << node->value << " <-> ";
			else
				out << node->value;
			node = node->nextNode;
		}
		out << " -> NULL]" << std::endl;
		return;
	}
	out << "Data structure is empty" << std::endl;
}

template<typename T>
size_t DataStructures::List<T>::getSize()
{
	return this->size;
}

// one data type necessary in this project
template class DataStructures::List<int>;