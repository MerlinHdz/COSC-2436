/** @file BagInterface.h*/
#ifndef BAG_INTERFACE_
#define BAG_INTERFACE_

#include <vector>

template<class ItemType>
class BagInterface
{
public:
    /** Gets the current number of entries in this bag. 
    @return The integer number of entries currently in the bag. */
    virtual int getCurrentSize() const = 0;


    /** Sees whether the bag is empty. 
    @return True if the bag is empty, False otherwise*/
    virtual bool isEmpty() const = 0;


    /** Adds new entry to this bag.
    @post If successful, newEntry is stored in the bag and the count
    of items in the bag has been increased by 1.
    @param newEntry The object to be added as a new entry.
    @return True if addition was successful, false if not.*/
    virtual bool add(const ItemType& newEntry) = 0;


    /** Removes one occurrence from a given entry from this bag,
    if possible. 
    @post If successful, anEntry has been removed from the bag
    and the count of items in the bag has been decreased by 1.
    @param anEntry The entry to be removed
    @return True if the removal was successful, false if not.
    */
    virtual bool remove(const ItemType& anEntry) = 0;


    /** Removes all entries from this bag
    @post Bag contains no items, and the count of items is 0.
    */
    virtual void clear() = 0;


    /** Counts the number of times a given entry appears in this bag
    @param anEntry The entry to be counted
    @return The number of times anEntry appears in the bag.
    */
    virtual int getFrequencyOf(const ItemType& anEntry) const = 0;


    /** Tests whether this bag contains a given entry.
    @param anEntry The entry to locate
    @return True if found, False otherwise.
    */
    virtual bool contains(const ItemType& anEntry) const = 0;


    /** Empties and then fills a given vector with all the entries
    that are in this bag.
    @return A vector containing copies of all the entries in the bag.
    */
    virtual std::vector<ItemType> toVector() const = 0;


    /** Destroys this bag and frees its assigned memory*/
    virtual ~BagInterface() {}
    // end BagInterface
};
#endif