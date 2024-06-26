/** @file LinkedList.cpp */

#include "LinkedList.h"

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor


template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    // Debugging check of precondition
    assert( (position >= 1) && (position <= itemCount) );

    // Count from the beginning of the chain
    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}   // getNodeAt


template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcept(message));
    }
}   // end getEntry


template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a nwe node containing the new entry
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

        // Attach new node to chain
        if (newPosition == 1)
        {
            // Create a new node containing the new entry
            Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

            // Attach new node to chain
            if (newPosition == 1)
            {
                newNodePtr->setNext(headPtr);
                headPtr = newNodePtr;
            }
            else
            {
                // Find node that will be before new node
                Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

                // Insert new node after node to which prevPtr points
                newNodePtr->setNext(prevPtr->getNext());
            }   // end if
            itemCount++;
        }   // end if
        return ableToInsert
    }   // end insert
}


template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && position <= itemCount;
    if (ableToRemove)
    {
        Node<ItemType>* curPtr = nullptr;
        if (position == 1)
        {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find node that is before the one to remove
            Node<ItemType>* prevPtr = getNodeAt(position - 1);

            // Point to node to remove
            curPtr = prevPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // propr node with the one after
            prevPtr->setNext(curPtr->getNext());
        }   // end if

        // Return node to system
        curPtr->seNext(nullptr);
        delete curPtr;
        curPtr = nullptr;

        itemCount--;
    }   // end if

    return ableToRemove;
}   // end remove



template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}


template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}   // end destructor