/** @file PlainBox.cpp */
#include "PlainBox.h"

// PlainBox::PlainBox()
// {   
// } // end default constructor


//A BETTER implementation of default constructor using an initializer
template<class ItemType>
PlainBox<ItemType>::PlainBox(const ItemType& theItem): item(theItem)
{    
} // end default constructor


template<class ItemType>
PlainBox<ItemType>::PlainBox(const ItemType& theItem)
{
    item = theItem;
}   // end constructor


template<class ItemType>
void PlainBox<ItemType>::setItem(const ItemType& theItem)
{
    item = theItem;
    // end setItem
}

template<class ItemType>
ItemType PlainBox<ItemType>::getItem() const
{
    return item;
}   // end getItem


/** NOTE
 * This file was modified to work with the template version of PlainBox.h
 * template<class ItemType> was added prior to each method's definition
 * and the namespace indicator PlainBox<ItemType>::, also precedes each method
 * name to reflect that the method's definition is based on the generic type
 * ItemType. 
 */