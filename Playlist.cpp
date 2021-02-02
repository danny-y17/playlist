#include "Playlist.hpp"
/*
    Default Constructor
    Goal: Calls its parent constructor
*/
Playlist::Playlist()
{  
    DoublyLinkedList();
}

/*
    Goal: Returns the sum of the lengths of each item in the Playlist
*/
double Playlist::getTotalTime() const {
    double total = 0;
    for (int i = 1; i <= item_count; i++) {       //to the end
        total += getAtPos(i)->getItem()->getLength();   //get item and the length of em
    }
    return total;   //return total 
}


/*
    Parameter: Another Playlist (rhs)
    Goal: Implement Union.
        rhs to be combined with the contents of this (the calling) list.
        Duplicates are allowed.
*/
void Playlist::operator+=(Playlist rhs) {
    DoubleNode<PlaylistItem*>* curr_ptr = rhs.head;
    for (int i = 1; i <= rhs.getSize(); i++) {
        insert(rhs.getAtPos(i)->getItem(),item_count+1); //insert item at end
    }   
}

/*
    Parameter: Another Playlist (rhs)
    Goal: Implement Difference.
    Removes all items from this (the calling) list that are also in rhs.
*/
void Playlist::operator-=(Playlist rhs) {
  /* DoubleNode<PlaylistItem*> *curr_ptr = rhs.head;
    int position = 1;
    while (curr_ptr != nullptr) {
        if (curr_ptr == head) {
            remove(position);
        }
        if (curr_ptr->getNext() == head->getNext()) {
            position++;
            remove(position);
        }
    }*/
}

/*
    Goal: Moves the current object at the head of the list to the end of the list.
*/
void Playlist::skip() {
   
    DoubleNode<PlaylistItem*>* temp = head;
    insert(temp->getItem(), item_count+1);
    remove(1);
}



    /*head = new DoubleNode<PlaylistItem*>();
    head->setItem(curr_ptr->getItem());
    remove(1);
    while (curr_ptr != nullptr) {
        curr_ptr->getNext();
    }
    curr_ptr = head;*/


/*
    Goal: Moves the current object at the end of the list to the head of the list.
*/
void Playlist::rewind() {
    DoubleNode<PlaylistItem*>* temp = tail;
    insert(temp->getItem(), 1);
    remove(item_count);

}

/*
    Goal: Calls the display function of each item in the Playlist
*/
void Playlist::display() {
    for (int i = 1; i <= DoublyLinkedList::getSize(); i++) {
        getAtPos(i)->getItem()->display();
    }
}
