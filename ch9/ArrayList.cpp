/** @file ArrayList.cpp */

#include "ArrayList.h"

template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}   // end default constructor 


template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const
{
    return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1)
                        && (itemCount < maxItems);
    
    if (ableToInsert)
    {
        // Make room for new entry by shifting all entries at 
        // positions from itemCount down to newPosition
        // (no shift if newPosition == itemCount + 1)
        for (int pos = itemCount; pos >= newPosition; pos--)
            items[pos + 1] = items[pos];

        // Insert new entry
        items[newPosition] = newEntry;
        itemCount++; // Increase count of entries
    }   // end if
    return ableToInsert;
}   // end insert


template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
        return items[position];
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcept(message));
    }
}   // end getEntry


template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry)
{
    // Enforce precondition
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet)
    {
        ItemType oldEntry = items[position];
        items[position] = newEntry;
        return oldEntry;
    }
    else
    {
        std::string message = "replace() called with an empty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcept(message));
    }
}   // end replace


template<class ItemType>
bool ArrayList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        // Remove entry by shifting all entries after the one at
        // position toward the beginning of the array
        // (no shift is position == itemCount)
        for (int pos = position; pos < itemCount; pos++)
            items[pos] = items[pos + 1];

        itemCount--; // Decrease count of entries
    }
}   // end remove


template<class ItemType>
void ArrayList<ItemType>::clear()
{
    itemCount = 0;
}   // end clear

