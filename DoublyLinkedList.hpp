#ifndef DOUBLY_LIST
#define DOUBLY_LIST
#include "DoubleNode.hpp"
#include <iostream>

template<class ItemType>
class DoublyLinkedList

{
public:
	//Default Constructor
	DoublyLinkedList();

	//Copy Constructor
	DoublyLinkedList(const DoublyLinkedList<ItemType>& list);

	//Destructor
	~DoublyLinkedList();

	bool insert(const ItemType& item, const int& position);
	//inserts item at position in caller list

	bool remove(const int& position);
	//removes the node at position

	int getSize() const;
	// returns the number of the nodes in the calling list

	DoubleNode<ItemType>* getHeadPtr() const;
	// returns a copy of the headPtr

	DoubleNode<ItemType>* getAtPos(const int& pos) const;
	// returns a pointer to the node located at pos

	bool isEmpty() const;
	// returns whether the calling list is empty

	void clear();
	// clears the list

	int getIndexOf(const ItemType& item) const;
	// returns the position of the given item in the list, -1 otherwise

	void display() const;
	// prints the contents of the calling list in order

	void displayBackwards() const;
	// prints the contents of the calling list in reverse order

	DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_list);
	// returns the interleaved list of the calling and parameter lists

protected:
	DoubleNode<ItemType>* head;
	DoubleNode<ItemType>* tail;
	int item_count;
};

#include "DoublyLinkedList.cpp" 
#endif