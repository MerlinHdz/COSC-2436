/** Header file for an array-based implementation of the ADT bag.
 @file ArrayBag.h*/

#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"
#include <vector>

template<class ItemType>
class ArrayBag: public BagInterface<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 6;  // Small size to test for a full bag
    ItemType items[DEFAULT_CAPACITY];       // Array of bag items
    int itemCount;                          // Current count of bag items
    int maxItems;                           // Max capacity of the bag

    // **** Interlude 2 change
    ItemType* items;

    // Returns either the index of the element in the array items that 
    // contains the given target, or -1 if the array does not contain the target
    //int getIndexOf(const ItemType& target) const;

    // recursive version header for getIndexOf
    int getIndexOf(const ItemType& target, int searchIndex) const;

    // helper method to be called by getFrequencyOf (recursive)
    int countFrequency(const ItemType& target, int searchIndex) const;

public:
    ArrayBag();
    virtual ~ArrayBag(); // *** Interlude 2 change
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    std::vector<ItemType> toVector() const;
};  // end ArrayBag

#include "ArrayBag.cpp"
#endif