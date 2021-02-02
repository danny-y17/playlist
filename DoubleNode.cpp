
#include "DoubleNode.hpp"
// Setter Functions
template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& anItem) {
	item_ = anItem;
}

template<class ItemType>
void DoubleNode<ItemType>::setPrevious(DoubleNode<ItemType>* previousNodePtr) {
	prev_ = previousNodePtr;
}

template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* nextNodePtr) {
	next_ = nextNodePtr;
}

// Getter Functions
template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const {
	return item_;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const {
	return next_;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrevious() const {
	return prev_;
}

//constructors
template<class ItemType>
DoubleNode<ItemType>::DoubleNode() : next_(nullptr), prev_(nullptr)
{
}

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& an_item) : item_(an_item)
{
}

