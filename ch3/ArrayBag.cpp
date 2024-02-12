/** Implementation file for the class ArrayBag
 @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <vector>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
    items = new ItemType[DEFAULT_CAPACITY]
} // end default constructor

// add
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        ItemType* oldArray = items;
        items = new ItemType[2 * maxItems];
        for (int index = 0; index < maxItems; idex++)
        {
            items[index] = oldArray[index];
        }

        delete [] oldArray;
        maxItems = 2 * maxItems;
    }   // end if

    // We can always add the item
    items[itemCount] = newEntry;
    itemCount++;

    return true;
}   // end add


template<class ItemType>
ArrayBag<ItemType>::~ArrayBag()
{
    delete [] items;
}   // end destructor


template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++)
        bagContents.push_back(items[i]);
    return bagContents;
}   // end toVector


template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}   // end getCurrentSize


template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const 
{
    return itemCount == 0;
}   // end isEmpty


/**
 * @brief Private method
 * 
 * @param target 
 * @return int 
 */
/*
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
    int result = -1;
    int searchIndex = 0;

    // if the bag is empty, itemCount is zero, so loop is skipped
    while( (result == -1) && (searchIndex < itemCount) )
    {
        if (items[searchIndex] == target)
        {
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }   // end if
    }   // end while
    return result;
}   // end getIndexOf
*/

// recursive implementation
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target, int searchIndex) const
{
    int result = -1;
    if (searchIndex < itemCount)
    {
        if (items[searchIndex] ==  target)
        {
            result = searchIndex;
        }
        else
        {
            result = getIndexOf(target, searchIndex + 1);
        }   // end if
    }

    return result;
}   // end getIndexOf


// Private method recursive (new) * *  * * 
template<class ItemType>
int ArrayBag<ItemType>::countFrequency(const ItemType& target, int searchIndex) const
{
    int frequency = 0;

    if (searchIndex < itemCount)
    {
        if (items[searchIndex] == target)
        {
            frequency = 1 + countFrequency(target, searchIndex + 1);
        }
        else
        {
            frequency = countFrequency(target, searchIndex + 1);
        }   // end if
    }   // end if
    // else do nothing - base case

    return frequency;
}   // end countFrequency


/**
 * @brief Removes anEntry from a bag. If the entry occurs more
 * than once, we will remove only one occurrence. Exactly which
 * occurrence is removed is unspecified.
 * @pre itemCount (ArrayBag data member) is >= 1
 * @param anEntry 
 * @return true if removal was successful, false otherwise
 */
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
    int locatedIndex = getIndexOf(anEntry, 0);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);

    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }

    return canRemoveItem;
}   // end remove


template<class ItemType>
void ArrayBag<ItemType>::clear()
{
    itemCount = 0;
}   // end clear


template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
    return getIndexOf(anEntry, 0) > -1;
    // end contains
}


template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    // int frequency = 0;

    // // For loop implementation
    // for (int i = 0; i < itemCount; i++)
    //     if (items[i] == anEntry)
    //         frequency++;
    

    // return frequency;

    return countFrequency(anEntry, 0); // calling recursive function
}   // end getFrequencyOf