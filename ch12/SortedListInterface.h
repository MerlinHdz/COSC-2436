/** Interface for the ADt sorted list 
 @file SortedListInterface.h
*/

#ifndef SORTED_LIST_INTERFACE
#define SORTED_LIST_INTERFACE

template<class ItemType>
class SortedListInterface
{
public:
    /**
     * @brief Inserts an entry into this sorted list in its proper order
     * so that the list remains sorted.
     * @pre None
     * @post newEntry is in the list, and the list is sorted
     * @param newEntry the entry to insert into the sorted list
     * @return True if insertion is successful, false if not.
     */
    virtual bool insertSorted(const ItemType& newEntry) = 0;

    /**
     * @brief Removes the first or only occurrence of the given entry from this
     * sorted list.
     * @pre None
     * @post If the removal is successful, the first occurrence of the given entry
     * is no longer in the sorted list, and the returned value is true. Otherwise,
     * the sorted list is unchanged, and the returned value is false.
     * @param anEntry The entry to remove
     * @return true if removal was successful, false if not.
     */
    virtual bool removeSorted(const ItemType& anEntry) = 0;

    /**
     * @brief Gets the position of the first or only occurrence of the given entry
     * in this sorted list. In the case the entry is not in the list, determines
     * where it should be if it were added to the list.
     * @pre None
     * @post The position of the given entry is or belongs is returned.
     * The sorted list is unchanged.
     * @param anEntry The entry to locate.
     * @return Either the position of the given entry, if it occurs in the sorted
     * list, or the position where the entry would occur, but as a negative int
     */
    virtual int getPosition(const ItemType& anEntry) = 0;


    // The following methods are the same as those given in ListInterface
    // in Listing 8-1 of Chapter 8 and are completely specified here

    /** Sees whether this list is empty. */
    virtual bool isEmpty() const = 0;

    /** Gets the current number of entries in this list*/
    virtual int getLength() const = 0;

    /** Removes the entry at a given position */
    virtual bool remove(int position) const = 0;

    /** Removes all entries from this list. */
    virtual void clear() = 0;

    /** Gets the entry at the given position in the list */
    virtual ItemType getEntry(int position) const = 0;

    /** Destroys this sorted list and frees its assigned memory */
    virtual ~SortedListInterface() {}
};  // end SortedListInterface

#endif