#pragma once
#include <iostream>
#include <stdexcept>

namespace DataStructures
{
	enum class Color
	{
		RED,
		BLACK
	};

	template<typename T>
	struct RBTNode
	{
		T value;
		RBTNode* parent;
		RBTNode* leftChild;
		RBTNode* rightChild;
		Color color;

		RBTNode(T value, RBTNode* parent, RBTNode* leftChild, RBTNode* rightChild, Color color)
			: value(value), parent(parent), leftChild(leftChild), rightChild(rightChild), color(color) {}

		RBTNode() : value(-1), parent(nullptr), leftChild(nullptr), rightChild(nullptr), color(Color::RED) {};
		~RBTNode() {}
	};

	template<typename T>
	//dynamic RBTree implementation
	class RBTree
	{
	public:

		// invalid index exception
		const std::invalid_argument* invalid_index = new std::invalid_argument("Invalid index");
		// structure pointer is null
		const std::out_of_range* head_null = new std::out_of_range("Structure pointer is null");
		// element not found
		const std::exception* out_of_bound = new std::exception("Element not found");
		// class constructor
		RBTree();
		// class destructor
		~RBTree();
		// checks if element exists in RBTree
		virtual bool find(const T& element);
		// adds element to end
		virtual void add(const T& element);
		// adds elements from static RBTree
		virtual void addAll(size_t& numOfElements, T* staticArr);
		// removes first obj of the RBTree
		virtual void remove(const T& element);
		//clears RBTree
		virtual void clear();
		// prints the RBTree in console
		virtual void print(std::ostream& out);

	private:
		// pointer to beggining of RBTree
		DataStructures::RBTNode<T>* root;
		//one node that serves the purpose of treating null as node
		DataStructures::RBTNode<T>* nodeNull;
		//returns successor of given node
		DataStructures::RBTNode<T>* getSuccessor(RBTNode<T>* node);
		//returns node with smallest value
		DataStructures::RBTNode<T>* getMinumum(RBTNode<T>* node);
		//returns node with smallest value
		//to search whole tree give root as node
		DataStructures::RBTNode<T>* getNode(RBTNode<T>* node, const T& element);
		//calculate height of tree
		int getDepth(RBTNode<T>* node);
		//balances the tree after remove
		void deleteFixup(RBTNode<T>* node);
		//balances the tree after add
		void insertFixup(RBTNode<T>* node);
		//clears RBTree
		virtual void clear(RBTNode<T>* node);
		//rotates the tree left
		void rotateLeft(RBTNode<T>* node);
		//rotates the tree right
		void rotateRight(RBTNode<T>* node);

		//places nodes inside array (indexing like heap)
		void nodesToArray(RBTNode<T>** array, RBTNode<T>* node, size_t index);
		void printHelp(std::ostream& out, RBTNode<T>* node, size_t numOfSpaces, size_t numOfMinus, bool surroundSlash);
	};
}
