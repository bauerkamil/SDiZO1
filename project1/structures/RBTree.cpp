#include "../headers/structures/RBTree.h"
#include <math.h>
#include <Windows.h>

template <typename T>
DataStructures::RBTree<T>::RBTree()
{
	// Initialize nodeNull
	this->nodeNull = new RBTNode<T>();
	this->nodeNull->color = Color::BLACK;
	this->nodeNull->parent = this->nodeNull;
	this->nodeNull->leftChild = this->nodeNull;
	this->nodeNull->rightChild = this->nodeNull;

	// Set root pointer to the nodeNull
	this->root = this->nodeNull;
}

template <typename T>
DataStructures::RBTree<T>::~RBTree()
{
	clear();

	if (root)
		delete this->root;
	if (nodeNull != nullptr)
		delete this->nodeNull;
}

template<typename T>
bool DataStructures::RBTree<T>::find(const T& element)
{
	RBTNode<T>* node = getNode(root, element);

	if (node != nodeNull)
		return true;
	else
		return false;
}

template<typename T>
DataStructures::RBTNode<T>* DataStructures::RBTree<T>::getNode(RBTNode<T>* node, const T& element)
{
	if (node == nodeNull || node->value == element)
		return node;

	if (element < node->value)
		return getNode(node->leftChild, element);
	return getNode(node->rightChild, element);
}

template<typename T>
void DataStructures::RBTree<T>::add(const T& element)
{
	DataStructures::RBTNode<T>* newNode = new DataStructures::RBTNode<T>(element, root, nodeNull, nodeNull, Color::RED);

	if (root == nodeNull)
	{
		this->root = newNode;
	}

	//add to tree
	while (true)
	{
		if (element < newNode->parent->value)
		{
			if (newNode->parent->leftChild == nodeNull)
			{
				newNode->parent->leftChild = newNode;
				break;
			}
			newNode->parent = newNode->parent->leftChild;
		}
		else
		{
			if (newNode->parent->rightChild == nodeNull)
			{
				newNode->parent->rightChild = newNode;
				break;
			}
			newNode->parent = newNode->parent->rightChild;
		}
	}

	insertFixup(newNode);
}

template<typename T>
void DataStructures::RBTree<T>::insertFixup(RBTNode<T>* insertedNode)
{
	DataStructures::RBTNode<T>* y;
	while (insertedNode != root && insertedNode->parent->color == Color::RED)
	{
		if (insertedNode->parent == insertedNode->parent->parent->leftChild) {
			y = insertedNode->parent->parent->rightChild;

			if (y->color == Color::RED) {
				insertedNode->parent->color = Color::BLACK;
				y->color = Color::BLACK;
				insertedNode->parent->parent->color = Color::RED;
				insertedNode = insertedNode->parent->parent;
				continue;
			}

			if (insertedNode == insertedNode->parent->rightChild)
			{
				insertedNode = insertedNode->parent;
				rotateLeft(insertedNode);
			}

			insertedNode->parent->color = Color::BLACK;
			insertedNode->parent->parent->color = Color::RED;
			rotateRight(insertedNode->parent->parent);
			break;
		}
		else
		{
			y = insertedNode->parent->parent->leftChild;

			if (y->color == Color::RED) {
				insertedNode->parent->color = Color::BLACK;
				y->color = Color::BLACK;
				insertedNode->parent->parent->color = Color::RED;
				insertedNode = insertedNode->parent->parent;
				continue;
			}

			if (insertedNode == insertedNode->parent->leftChild)
			{
				insertedNode = insertedNode->parent;
				rotateRight(insertedNode);
			}

			insertedNode->parent->color = Color::BLACK;
			insertedNode->parent->parent->color = Color::RED;
			rotateLeft(insertedNode->parent->parent);
			break;
		}
	}
	this->root->color = Color::BLACK;
}

template<typename T>
void DataStructures::RBTree<T>::addAll(size_t& numOfElements, T* staticArr)
{
	for (size_t i = 0; i < numOfElements; i++)
	{
		add(staticArr[i]);
	}
}

template<typename T>
void DataStructures::RBTree<T>::remove(const T& element)
{
	RBTNode<T>* nodeToRemove = getNode(root, element);
	RBTNode<T>* y;
	RBTNode<T>* z = nodeToRemove;

	if (nodeToRemove == nodeNull)
		throw* this->out_of_bound;

	if (nodeToRemove->leftChild == nodeNull || nodeToRemove->rightChild == nodeNull)
		y = nodeToRemove;
	else
		y = getSuccessor(nodeToRemove);

	if (y->leftChild != nodeNull)
		nodeToRemove = y->leftChild;
	else
		nodeToRemove = y->rightChild;

	nodeToRemove->parent = y->parent;

	if (y->parent == nodeNull)
		this->root = nodeToRemove;
	else
		if (y = y->parent->leftChild)
			y->parent->leftChild = nodeToRemove;
		else
			y->parent->rightChild = nodeToRemove;

	if (y != nodeToRemove)
		nodeToRemove->value = y->value;

	if (y->color == Color::BLACK)
		deleteFixup(nodeToRemove);

	delete z;
}

template<typename T>
void DataStructures::RBTree<T>::deleteFixup(RBTNode<T>* removedNode)
{
	RBTNode<T>* w;

	while (removedNode != root && removedNode->color == Color::BLACK)
	{
		if (removedNode == removedNode->parent->leftChild)
		{
			w = removedNode->parent->rightChild;

			//case 1
			if (w->color == Color::RED)
			{
				removedNode->parent->color = Color::BLACK;
				rotateLeft(removedNode->parent);
				w = removedNode->parent->rightChild;
			}
			//case 2
			if (w->leftChild->color == Color::BLACK && w->rightChild->color == Color::BLACK)
			{
				w->color = Color::RED;
				removedNode = removedNode->parent;
			}
			else
			{
				//case 3
				if (w->rightChild->color == Color::BLACK)
				{
					w->leftChild->color = Color::BLACK;
					w->color = Color::RED;
					rotateRight(w);
					w = removedNode->parent->rightChild;
				}
				//case 4
				w->color = w->parent->color;
				removedNode->parent->color = Color::BLACK;
				w->rightChild->color = Color::BLACK;
				rotateLeft(removedNode->parent);
				removedNode = this->root;
			}
		}
		else
		{
			w = removedNode->parent->leftChild;

			//case 1
			if (w->color == Color::RED)
			{
				removedNode->parent->color = Color::BLACK;
				rotateRight(removedNode->parent);
				w = removedNode->parent->leftChild;
			}
			//case 2
			if (w->leftChild->color == Color::BLACK && w->rightChild->color == Color::BLACK)
			{
				w->color = Color::RED;
				removedNode = removedNode->parent;
			}
			else
			{
				//case 3
				if (w->leftChild->color == Color::BLACK)
				{
					w->rightChild->color = Color::BLACK;
					w->color = Color::RED;
					rotateLeft(w);
					w = removedNode->parent->leftChild;
				}
				//case 4
				w->color = w->parent->color;
				removedNode->parent->color = Color::BLACK;
				w->leftChild->color = Color::BLACK;
				rotateRight(removedNode->parent);
				removedNode = this->root;
			}
		}
	}
	removedNode->color = Color::BLACK;
}

template<typename T>
void DataStructures::RBTree<T>::clear()
{
	clear(this->root);

	// Initialize
	this->nodeNull = new RBTNode<T>();
	this->nodeNull->color = Color::BLACK;
	this->nodeNull->parent = this->nodeNull;
	this->nodeNull->leftChild = this->nodeNull;
	this->nodeNull->rightChild = this->nodeNull;

	this->root = nodeNull;
}

template<typename T>
void DataStructures::RBTree<T>::clear(RBTNode<T>* node)
{
	if (node != nodeNull)
	{
		if (node)
		{
			clear(node->leftChild);
			clear(node->rightChild);

			//node->leftChild->parent = nodeNull;
			//node->rightChild->parent = nodeNull;
			delete node;
		}
	}
}

template<typename T>
void DataStructures::RBTree<T>::print(std::ostream& out)
{
	if (this->root != nodeNull)
	{
		size_t height = getDepth(root) + 1;

		size_t size = pow(2, height) - 1;
		RBTNode<T>** nodes = new RBTNode<T>*[size];

		for (size_t i = 0; i < size; i++)
		{
			nodes[i] = nullptr;
		}

		nodesToArray(nodes, root, 0);

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
				printHelp(out, nodes[index], numOfSpace, numOfMinus, true);
				index++;
			}
			out << std::endl;
		}
		out << height << ".";
		while (index < size)
		{
			printHelp(out, nodes[index], 0, 0, false);
			index++;
		}
		out << std::endl;
		delete[] nodes;
		return;
	}
	out << "Data structure is empty" << std::endl;
}

template<typename T>
DataStructures::RBTNode<T>* DataStructures::RBTree<T>::getSuccessor(RBTNode<T>* node)
{
	if (node->rightChild != nodeNull)
	{
		return getMinumum(node->rightChild);
	}

	RBTNode<T>* next = node->parent;
	while (next != nodeNull && node == next->rightChild)
	{
		node = next;
		next = next->parent;
	}
	return next;
}

template<typename T>
DataStructures::RBTNode<T>* DataStructures::RBTree<T>::getMinumum(RBTNode<T>* node)
{
	while (node->leftChild != nodeNull)
	{
		node = node->leftChild;
	}
	return node;
}

template<typename T>
int DataStructures::RBTree<T>::getDepth(RBTNode<T>* node)
{
	if (node == nodeNull)
		return -1; //below the tree

	//recursive method to visit every descendant
	int max = max(getDepth(node->leftChild), getDepth(node->rightChild)) + 1;
	return max;
}

template<typename T>
void DataStructures::RBTree<T>::rotateLeft(RBTNode<T>* node)
{
	RBTNode<T>* y = node->rightChild;

	//change left subtree to right
	node->rightChild = y->leftChild;

	if (y->leftChild != nodeNull)
	{
		y->leftChild->parent = node;
	}

	//add x parent as node parent
	y->parent = node->parent;

	if (node->parent == nodeNull) {
		this->root = y;
	}
	else if (node == node->parent->leftChild) {
		node->parent->leftChild = y;
	}
	else {
		node->parent->rightChild = y;
	}
	//add node as left y son
	y->leftChild = node;
	node->parent = y;
}

template<typename T>
void DataStructures::RBTree<T>::rotateRight(RBTNode<T>* node)
{
	RBTNode<T>* y = node->leftChild;

	node->leftChild = y->rightChild;

	if (y->rightChild != nodeNull)
	{
		y->rightChild->parent = node;
	}

	y->parent = node->parent;

	if (node->parent == nodeNull) {
		this->root = y;
	}
	else if (node == node->parent->rightChild) {
		node->parent->rightChild = y;
	}
	else {
		node->parent->leftChild = y;
	}
	y->rightChild = node;
	node->parent = y;
}

template<typename T>
void DataStructures::RBTree<T>::nodesToArray(RBTNode<T>** array, RBTNode<T>* node, size_t index)
{
	// Place node in array
	array[index] = node;

	// Check if exists left child
	if (node->leftChild != this->nodeNull)
	{
		nodesToArray(array, node->leftChild, 2 * index + 1);
	}

	// Check if exists right child
	if (node->rightChild != this->nodeNull)
	{
		nodesToArray(array, node->rightChild, 2 * index + 2);
	}
}

template<typename T>
void DataStructures::RBTree<T>::printHelp(std::ostream& out, RBTNode<T>* node, size_t numOfSpaces, size_t numOfMinus, bool surroundSlash)
{
	// Get handler for console manipulation
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (node == nullptr) {
		if (surroundSlash)
			out << std::string(2 * numOfMinus + numOfSpaces + 3, ' ');
		else
			out << "  ";
		return;
	}
	if (node == nodeNull) {
		out << std::string(numOfMinus + 1, ' ') << "N" << std::string(numOfMinus + numOfSpaces + 1, ' ');
		return;
	}

	int color = node->color == DataStructures::Color::RED ? 12 : 8;
	if (surroundSlash)
	{
		if (node->leftChild != nodeNull)
			out << "/" << std::string(numOfMinus, '-');
		else
			out << std::string(numOfMinus + 1, ' ');
		//set console color
		SetConsoleTextAttribute(hConsole, color);
		out << node->value;
		// Set back default console color
		SetConsoleTextAttribute(hConsole, 7);

		if (node->rightChild != nodeNull)
			out << std::string(numOfMinus, '-') << "\\";
		else
			out << std::string(numOfMinus + 1, ' ');

		out << std::string(numOfSpaces, ' ');
		return;
	}
	else
	{
		//set console color
		SetConsoleTextAttribute(hConsole, color);

		out << node->value;

		// Set back default console color
		SetConsoleTextAttribute(hConsole, 7);
		out << " ";
		return;
	}
}

// one data type necessary in this project
template class DataStructures::RBTree<int>;