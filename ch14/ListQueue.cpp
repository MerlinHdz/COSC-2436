/** ADT queue: ADT List implementation 
 @file ListQueue.cpp */

#include "ListQueue.h"
#include <memory>

template<class ItemType>
ListQueue<ItemType>::ListQueue(): listPtr(std::make_unique<LinkedList<ItemType>>())
{
} // end default constructor


template<class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& aQueue): listPtr(aQueue.listPtr)
{
} // end copy constructor


template<class ItemType>
ListQueue<ItemType>::~ListQueue()
{
} // end destructor


template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const
{
    return listPtr->isEmpty();
} // end isEmpty


template<class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    return listPtr->insert(listPtr->getLength() + 1, newEntry);
}

template<class ItemType>
bool ListQueue<ItemType>::dequeue()
{
    return listPtr->remove(1);
}

template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const
{
    if (isEmpty())
    {
       std:cout << "peekFront() called with empty queue." << std::endl;
    }
    // Queue is not empty, return front
    return listPtr->getEntry(1);
} // end peekFront