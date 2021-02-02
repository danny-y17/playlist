#include "DoublyLinkedList.hpp"

//Default Constructor
template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() :head(nullptr),tail(nullptr),item_count(0)
{
}

template<typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& a_bag)
{
	item_count = a_bag.item_count;
	DoubleNode<ItemType>* orig_chain_ptr = a_bag.head;//Points to nodes in original chain
	if (orig_chain_ptr == nullptr)
		head = nullptr; // Original bag is empty
	else
	{
		// Copy first node
		head = new DoubleNode<ItemType>();
		head->setItem(orig_chain_ptr->getItem());
		// Copy remaining nodes
		DoubleNode<ItemType>* new_chain_ptr = head;//Points to last node in new chain
		orig_chain_ptr = orig_chain_ptr->getNext();//Advance original-chain pointer
		while (orig_chain_ptr != nullptr)
		{ // Get next item from original chain
			ItemType next_item = orig_chain_ptr->getItem();
			// Create a new node containing the next item
			DoubleNode<ItemType>* new_node_ptr = new DoubleNode<ItemType>(next_item);
			// Link new node to end of new chain
			new_chain_ptr->setNext(new_node_ptr);
			// Advance pointer to new last node
			new_chain_ptr = new_chain_ptr->getNext();
			// Advance original-chain pointer
			orig_chain_ptr = orig_chain_ptr->getNext();
		} // end while
		new_chain_ptr->setNext(nullptr); // Flag end of chain
	} // end if
} // end copy constructor
//Copy Constructor
/*template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& list)
{
	item_count = list.item_count;
	DoubleNode<ItemType>* original_chain_ptr = list.head;

	if (original_chain_ptr == nullptr)
		head = nullptr;
	else {
		//COPY FIRST NODE
		head = new DoubleNode<ItemType>();
		head->setItem(original_chain_ptr->getItem());
		//COPY REMAINING NODES
		DoubleNode<ItemType>* new_chain_ptr = head;
		while (original_chain_ptr != nullptr) {
			original_chain_ptr = original_chain_ptr->getNext();
			ItemType nextItem = original_chain_ptr->getItem();
			DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>(nextItem);
			new_chain_ptr->setNext(newNodePtr);
			new_chain_ptr = new_chain_ptr->getNext();
		}
		new_chain_ptr->setNext(nullptr); //flag end of new chain
	}
}*/

//Destructor
template <class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList() 
{
	clear();
}


template <class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position)
{
	DoubleNode<ItemType>* new_node_ptr = new DoubleNode<ItemType>(item);
	DoubleNode<ItemType>* pos_ptr = getAtPos(position);
	//if there are no entries in list
	if (head == nullptr)	
	{
		new_node_ptr->setPrevious(nullptr);
		new_node_ptr->setNext(nullptr);
		tail = new_node_ptr;
		head = new_node_ptr;
	}
	//if we are entering at the beginning
	else if (pos_ptr == head)
	{
		if (head == nullptr) {
			head = new_node_ptr;
		}
		else {
			new_node_ptr->setNext(head);
			new_node_ptr->setPrevious(nullptr);
			head->setPrevious(new_node_ptr);
			head = new_node_ptr;

		}
	}
	//if we are entering entry at the end
	else if (pos_ptr == nullptr)		
	{
		new_node_ptr->setPrevious(tail);
		new_node_ptr->setNext(nullptr);
		tail->setNext(new_node_ptr);
		tail = new_node_ptr;
	}
	//entry for middle of the list
	else 
	{
		new_node_ptr->setPrevious(pos_ptr->getPrevious());
		new_node_ptr->setNext(pos_ptr);
		pos_ptr->getPrevious()->setNext(new_node_ptr);
		pos_ptr->setPrevious(new_node_ptr);
	}
	item_count++;
	return true;
}

template <class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position)
{
	DoubleNode<ItemType>* pos_ptr = getAtPos(position);
	//no node at position
	if (pos_ptr == nullptr) {
		return false;
	}
	else {
		//remove node
		if (pos_ptr == head) {
			head = pos_ptr->getNext();
		/*head->setPrevious(nullptr);
			//return node
			pos_ptr->setNext(nullptr);
			delete pos_ptr;
			pos_ptr = nullptr;*/
		}
		//remove last node
		else if (pos_ptr = tail) {
			tail = pos_ptr->getPrevious();
			tail->setNext(nullptr);
			pos_ptr->setPrevious(nullptr);
			delete pos_ptr;
			pos_ptr = nullptr;
		}
		//remove from middle
		else {
			pos_ptr->getPrevious()->setNext(pos_ptr->getNext());
			pos_ptr->getNext()->setPrevious(pos_ptr->getPrevious());
			//return to system
			pos_ptr->setNext(nullptr);
			pos_ptr->setPrevious(nullptr);
			delete pos_ptr;
			pos_ptr = nullptr;
		}
		item_count--;
		return true;
	}
}
//removes the node at position

template <class ItemType>
int DoublyLinkedList<ItemType>::getSize() const {
	return item_count;
}
// returns the number of the nodes in the calling list

template <class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const {
	return head;
}
// returns a copy of the headPtr

template <class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int& pos) const {
	DoubleNode<ItemType>* curr_ptr = head;
	int position = 1;
	if ((pos < 1) or (pos > item_count)) {
		return nullptr;
	}
	while (curr_ptr != nullptr) {
		if (position == pos) {
			return curr_ptr;
		}
		else {
			curr_ptr = curr_ptr->getNext();
			position++;
		}
	}
	return nullptr;
}

template <class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const 
{
	return item_count == 0;
}
// returns whether the calling list is empty


template <class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
	while (head != nullptr) {
		DoubleNode<ItemType>* temp_ptr = head;
		head = temp_ptr->getNext();
		temp_ptr->setNext(nullptr);
		delete temp_ptr;
	}
	item_count = 0;
}
// clears the list

template <class ItemType>
int DoublyLinkedList<ItemType>::getIndexOf(const ItemType& item) const {
	DoubleNode<ItemType>* curr_ptr = head;
	bool found = -1;
	int result = -1;
	int index = 1;
	while (!found && (index < item_count)) {
		if (curr_ptr->getItem() == item) {
			found = true;
			result = index;
		}
		else {
			index++;
		}
	}
	return result;
}

/*template <class ItemType>
int DoublyLinkedList<ItemType>::getIndexOf(const ItemType& item) const {
	int position = 0;
	DoubleNode<ItemType>* some_ptr = head;
	while (head != nullptr) {
		if (some_ptr->getNext() != item) {
			some_ptr = some_ptr->getNext();
			position++;	
		}
		else {
			position = -1;
		}
	}
	return position;
}*/
// returns the position of the given item in the list, -1 otherwise

/*template <class ItemType>
void DoublyLinkedList<ItemType>::display() const {
	DoubleNode<ItemType>* curr_ptr = head;
	for (int i = 0; i < item_count ; i++) 
	{
		std::cout << curr_ptr->getItem();
		if (i < item_count - 1) {
			std::cout << " ";
		}
		curr_ptr = curr_ptr->getNext();
		if (item_count == 0) {
			std::cout << "";
		}
	}
	std::cout << std::endl;
}*/
template <class ItemType>
void DoublyLinkedList<ItemType>::display() const {
	DoubleNode<ItemType>* curr_ptr = head;

	if (curr_ptr == nullptr) {
		std::cout <<""<< std::endl;
		return;
	}

	while (curr_ptr->getNext() != nullptr) {		//if the next node from current pointer is not empty
		std::cout << curr_ptr->getItem() << " ";	// output item;
		curr_ptr = curr_ptr->getNext();				// get next;
	}

	std::cout << curr_ptr->getItem();				// output item again for the last item;
	std::cout << std::endl;							
}
// prints the contents of the calling list in order

template <class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const {
	DoubleNode<ItemType>* curr_ptr = tail;
	while (curr_ptr->getPrevious() != nullptr) {
		std::cout << curr_ptr->getItem() << " ";
		curr_ptr = curr_ptr->getPrevious();
	}
	std::cout << curr_ptr->getItem();
	std::cout << std::endl;
}

// prints the contents of the calling list in reverse order

template <class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list)
{
	int position = 1;
	DoubleNode<ItemType>* list1 = head;
	DoubleNode<ItemType>* list2 = a_list.head;
	DoublyLinkedList<ItemType> *newList = new DoublyLinkedList();

	while (list1 != nullptr or list2 != nullptr) {
		if (list1 != nullptr) {
			newList->insert(list1->getItem(), position);
			list1 = list1->getNext();
			position++;
		}
		if (list2 != nullptr) {
			newList->insert(list2->getItem(), position);
			list2 = list2->getNext();
			position++;
		}
	}
	return *newList;
}
// returns the interleaved list of the calling and parameter lists