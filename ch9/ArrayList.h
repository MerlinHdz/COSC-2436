/** ADT list: Array-based implementation.
 * @file ArrayList.h
 */

#ifndef ARRAY_LIST_
#define ARRAY_LIST_

#include "ListInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayList: public ListInterface<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 100;
    ItemType items[DEFAULT_CAPACITY + 1]; // Array of list items (ignore items[0])
    int itemCount;
    int maxItems;

public:
    ArrayList();
    // Copy Constructor and destructor are supplied by compiler

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();

    /** @throw PrecondViolatedExcept if position < 1 or position > getLength(). */
    ItemType getEntry(int position) const;

    /** @throw PrecondViolatedExcept if position < 1 or position > getLength(). */
    ItemType replace(int position, const ItemType& newEntry);
};
#include "ArrayList.cpp"
#endif