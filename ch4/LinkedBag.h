/** ADT bag: Link-based implementation 
 @file LinkedBag.h */

#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"
#include <vector>

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to the first node
    int itemCount;           // Current count of bag items

    // Returns either a pointer to the node containing a given entry
    // or the null pointer if the entry is not in the bag
    Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
    virtual ~LinkedBag();

    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    std::vector<ItemType> toVector() const;
};  // end LinkedBag

#include "LinkedBag.cpp"
#endif