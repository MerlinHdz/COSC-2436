/** @file MagicBox.cpp */

#include "MagicBox.h"
template<class ItemType>
MagicBox<ItemType>::MagicBox() : firstItemStored(false)
{
    // PlainBox constructor is called implicitly
    // Box has no magic initially
    // end default constructor
}

template<class ItemType>
void MagicBox<ItemType>::setItem(const ItemType& theItem)
{
    if (!firstItemStored)
    {
        PlainBox<ItemType>::setItem(theItem);
        firstItemStored = true; // Box has magic now
        // end if
    }
}   // end setItem