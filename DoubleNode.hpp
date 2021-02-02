#ifndef DOUBLE_NODE
#define DOUBLE_NODE

template<class ItemType>
class DoubleNode
{
public:
	// Setter Functions
	void setItem(const ItemType& anItem);
	void setPrevious(DoubleNode<ItemType>* previousNodePtr);
	void setNext(DoubleNode<ItemType>* nextNodePtr);

	// Getter Functions
	ItemType getItem() const;
	DoubleNode<ItemType>* getNext() const;
	DoubleNode<ItemType>* getPrevious() const;

	DoubleNode();
	DoubleNode(const ItemType& an_item);

private:
	ItemType item_;
	DoubleNode<ItemType>* next_;
	DoubleNode<ItemType>* prev_;
};
#include "DoubleNode.cpp"
#endif