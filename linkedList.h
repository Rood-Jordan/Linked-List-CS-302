#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include "listInterface.h"

using namespace std;

template<class ItemType>
class linkedList : public listInterface<ItemType> {
    Node<ItemType>* headPtr;
    int itemCount;

public:
    linkedList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const;
    ItemType replace(int position, const ItemType& newEntry);
    
    ~linkedList();
};
#include "linkedList.cpp"
#endif
